/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "syncUtil.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "syncEnv.h"

// ---- encode / decode
uint64_t syncUtilAddr2U64(const char* host, uint16_t port) {
  uint64_t u64;
  uint32_t hostU32 = (uint32_t)inet_addr(host);
  // assert(hostU32 != (uint32_t)-1);
  u64 = (((uint64_t)hostU32) << 32) | (((uint32_t)port) << 16);
  return u64;
}

void syncUtilU642Addr(uint64_t u64, char* host, size_t len, uint16_t* port) {
  uint32_t hostU32 = (uint32_t)((u64 >> 32) & 0x00000000FFFFFFFF);

  struct in_addr addr;
  addr.s_addr = hostU32;
  snprintf(host, len, "%s", inet_ntoa(addr));
  *port = (uint16_t)((u64 & 0x00000000FFFF0000) >> 16);
}

void syncUtilnodeInfo2EpSet(const SNodeInfo* pNodeInfo, SEpSet* pEpSet) {
  pEpSet->inUse = 0;
  pEpSet->numOfEps = 0;
  addEpIntoEpSet(pEpSet, pNodeInfo->nodeFqdn, pNodeInfo->nodePort);
}

void syncUtilraftId2EpSet(const SRaftId* raftId, SEpSet* pEpSet) {
  char     host[TSDB_FQDN_LEN];
  uint16_t port;

  syncUtilU642Addr(raftId->addr, host, sizeof(host), &port);

  /*
    pEpSet->numOfEps = 1;
    pEpSet->inUse = 0;
    pEpSet->eps[0].port = port;
    snprintf(pEpSet->eps[0].fqdn, sizeof(pEpSet->eps[0].fqdn), "%s", host);
  */
  pEpSet->inUse = 0;
  pEpSet->numOfEps = 0;
  addEpIntoEpSet(pEpSet, host, port);
}

void syncUtilnodeInfo2raftId(const SNodeInfo* pNodeInfo, SyncGroupId vgId, SRaftId* raftId) {
  uint32_t ipv4 = taosGetIpv4FromFqdn(pNodeInfo->nodeFqdn);
  assert(ipv4 != 0xFFFFFFFF);
  char ipbuf[128];
  tinet_ntoa(ipbuf, ipv4);
  raftId->addr = syncUtilAddr2U64(ipbuf, pNodeInfo->nodePort);
  raftId->vgId = vgId;
}

bool syncUtilSameId(const SRaftId* pId1, const SRaftId* pId2) {
  bool ret = pId1->addr == pId2->addr && pId1->vgId == pId2->vgId;
  return ret;
}

// ---- SSyncBuffer -----
void syncUtilbufBuild(SSyncBuffer* syncBuf, size_t len) {
  syncBuf->len = len;
  syncBuf->data = malloc(syncBuf->len);
}

void syncUtilbufDestroy(SSyncBuffer* syncBuf) { free(syncBuf->data); }

void syncUtilbufCopy(const SSyncBuffer* src, SSyncBuffer* dest) {
  dest->len = src->len;
  dest->data = src->data;
}

void syncUtilbufCopyDeep(const SSyncBuffer* src, SSyncBuffer* dest) {
  dest->len = src->len;
  dest->data = malloc(dest->len);
  memcpy(dest->data, src->data, dest->len);
}

// ---- misc ----

int32_t syncUtilRand(int32_t max) { return taosRand() % max; }

int32_t syncUtilElectRandomMS() { return ELECT_TIMER_MS_MIN + syncUtilRand(ELECT_TIMER_MS_RANGE); }

int32_t syncUtilQuorum(int32_t replicaNum) { return replicaNum / 2 + 1; }

cJSON* syncUtilNodeInfo2Json(const SNodeInfo* p) {
  char   u64buf[128];
  cJSON* pRoot = cJSON_CreateObject();

  cJSON_AddStringToObject(pRoot, "nodeFqdn", p->nodeFqdn);
  cJSON_AddNumberToObject(pRoot, "nodePort", p->nodePort);

  cJSON* pJson = cJSON_CreateObject();
  cJSON_AddItemToObject(pJson, "SNodeInfo", pRoot);
  return pJson;
}

cJSON* syncUtilRaftId2Json(const SRaftId* p) {
  char   u64buf[128];
  cJSON* pRoot = cJSON_CreateObject();

  snprintf(u64buf, sizeof(u64buf), "%lu", p->addr);
  cJSON_AddStringToObject(pRoot, "addr", u64buf);
  char     host[128];
  uint16_t port;
  syncUtilU642Addr(p->addr, host, sizeof(host), &port);
  cJSON_AddStringToObject(pRoot, "host", host);
  cJSON_AddNumberToObject(pRoot, "port", port);
  cJSON_AddNumberToObject(pRoot, "vgId", p->vgId);

  cJSON* pJson = cJSON_CreateObject();
  cJSON_AddItemToObject(pJson, "SRaftId", pRoot);
  return pJson;
}

char* syncUtilRaftId2Str(const SRaftId* p) {
  cJSON* pJson = syncUtilRaftId2Json(p);
  char*  serialized = cJSON_Print(pJson);
  cJSON_Delete(pJson);
  return serialized;
}

const char* syncUtilState2String(ESyncState state) {
  if (state == TAOS_SYNC_STATE_FOLLOWER) {
    return "TAOS_SYNC_STATE_FOLLOWER";
  } else if (state == TAOS_SYNC_STATE_CANDIDATE) {
    return "TAOS_SYNC_STATE_CANDIDATE";
  } else if (state == TAOS_SYNC_STATE_LEADER) {
    return "TAOS_SYNC_STATE_LEADER";
  } else {
    return "TAOS_SYNC_STATE_UNKNOWN";
  }
}

bool syncUtilCanPrint(char c) {
  if (c >= 32 && c <= 126) {
    return true;
  } else {
    return false;
  }
}

char* syncUtilprintBin(char* ptr, uint32_t len) {
  char* s = malloc(len + 1);
  assert(s != NULL);
  memset(s, 0, len + 1);
  memcpy(s, ptr, len);

  for (int i = 0; i < len; ++i) {
    if (!syncUtilCanPrint(s[i])) {
      s[i] = '.';
    }
  }
  return s;
}

char* syncUtilprintBin2(char* ptr, uint32_t len) {
  uint32_t len2 = len * 4 + 1;
  char*    s = malloc(len2);
  assert(s != NULL);
  memset(s, 0, len2);

  char* p = s;
  for (int i = 0; i < len; ++i) {
    int n = sprintf(p, "%d,", ptr[i]);
    p += n;
  }
  return s;
}

SyncIndex syncUtilMinIndex(SyncIndex a, SyncIndex b) {
  SyncIndex r = a < b ? a : b;
  return r;
}

SyncIndex syncUtilMaxIndex(SyncIndex a, SyncIndex b) {
  SyncIndex r = a > b ? a : b;
  return r;
}