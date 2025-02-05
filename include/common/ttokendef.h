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

#ifndef _TD_COMMON_TOKEN_H_
#define _TD_COMMON_TOKEN_H_

#define TK_OR                   1
#define TK_AND                  2
#define TK_UNION                3
#define TK_ALL                  4
#define TK_MINUS                5
#define TK_EXCEPT               6
#define TK_INTERSECT            7
#define TK_NK_BITAND            8
#define TK_NK_BITOR             9
#define TK_NK_LSHIFT            10
#define TK_NK_RSHIFT            11
#define TK_NK_PLUS              12
#define TK_NK_MINUS             13
#define TK_NK_STAR              14
#define TK_NK_SLASH             15
#define TK_NK_REM               16
#define TK_NK_CONCAT            17
#define TK_CREATE               18
#define TK_ACCOUNT              19
#define TK_NK_ID                20
#define TK_PASS                 21
#define TK_NK_STRING            22
#define TK_ALTER                23
#define TK_PPS                  24
#define TK_TSERIES              25
#define TK_STORAGE              26
#define TK_STREAMS              27
#define TK_QTIME                28
#define TK_DBS                  29
#define TK_USERS                30
#define TK_CONNS                31
#define TK_STATE                32
#define TK_USER                 33
#define TK_ENABLE               34
#define TK_NK_INTEGER           35
#define TK_SYSINFO              36
#define TK_DROP                 37
#define TK_GRANT                38
#define TK_ON                   39
#define TK_TO                   40
#define TK_REVOKE               41
#define TK_FROM                 42
#define TK_SUBSCRIBE            43
#define TK_NK_COMMA             44
#define TK_READ                 45
#define TK_WRITE                46
#define TK_NK_DOT               47
#define TK_DNODE                48
#define TK_PORT                 49
#define TK_DNODES               50
#define TK_NK_IPTOKEN           51
#define TK_FORCE                52
#define TK_LOCAL                53
#define TK_QNODE                54
#define TK_BNODE                55
#define TK_SNODE                56
#define TK_MNODE                57
#define TK_DATABASE             58
#define TK_USE                  59
#define TK_FLUSH                60
#define TK_TRIM                 61
#define TK_IF                   62
#define TK_NOT                  63
#define TK_EXISTS               64
#define TK_BUFFER               65
#define TK_CACHEMODEL           66
#define TK_CACHESIZE            67
#define TK_COMP                 68
#define TK_DURATION             69
#define TK_NK_VARIABLE          70
#define TK_MAXROWS              71
#define TK_MINROWS              72
#define TK_KEEP                 73
#define TK_PAGES                74
#define TK_PAGESIZE             75
#define TK_TSDB_PAGESIZE        76
#define TK_PRECISION            77
#define TK_REPLICA              78
#define TK_VGROUPS              79
#define TK_SINGLE_STABLE        80
#define TK_RETENTIONS           81
#define TK_SCHEMALESS           82
#define TK_WAL_LEVEL            83
#define TK_WAL_FSYNC_PERIOD     84
#define TK_WAL_RETENTION_PERIOD 85
#define TK_WAL_RETENTION_SIZE   86
#define TK_WAL_ROLL_PERIOD      87
#define TK_WAL_SEGMENT_SIZE     88
#define TK_STT_TRIGGER          89
#define TK_TABLE_PREFIX         90
#define TK_TABLE_SUFFIX         91
#define TK_NK_COLON             92
#define TK_MAX_SPEED            93
#define TK_TABLE                94
#define TK_NK_LP                95
#define TK_NK_RP                96
#define TK_STABLE               97
#define TK_ADD                  98
#define TK_COLUMN               99
#define TK_MODIFY               100
#define TK_RENAME               101
#define TK_TAG                  102
#define TK_SET                  103
#define TK_NK_EQ                104
#define TK_USING                105
#define TK_TAGS                 106
#define TK_COMMENT              107
#define TK_BOOL                 108
#define TK_TINYINT              109
#define TK_SMALLINT             110
#define TK_INT                  111
#define TK_INTEGER              112
#define TK_BIGINT               113
#define TK_FLOAT                114
#define TK_DOUBLE               115
#define TK_BINARY               116
#define TK_TIMESTAMP            117
#define TK_NCHAR                118
#define TK_UNSIGNED             119
#define TK_JSON                 120
#define TK_VARCHAR              121
#define TK_MEDIUMBLOB           122
#define TK_BLOB                 123
#define TK_VARBINARY            124
#define TK_DECIMAL              125
#define TK_MAX_DELAY            126
#define TK_WATERMARK            127
#define TK_ROLLUP               128
#define TK_TTL                  129
#define TK_SMA                  130
#define TK_DELETE_MARK          131
#define TK_FIRST                132
#define TK_LAST                 133
#define TK_SHOW                 134
#define TK_PRIVILEGES           135
#define TK_DATABASES            136
#define TK_TABLES               137
#define TK_STABLES              138
#define TK_MNODES               139
#define TK_QNODES               140
#define TK_FUNCTIONS            141
#define TK_INDEXES              142
#define TK_ACCOUNTS             143
#define TK_APPS                 144
#define TK_CONNECTIONS          145
#define TK_LICENCES             146
#define TK_GRANTS               147
#define TK_QUERIES              148
#define TK_SCORES               149
#define TK_TOPICS               150
#define TK_VARIABLES            151
#define TK_CLUSTER              152
#define TK_BNODES               153
#define TK_SNODES               154
#define TK_TRANSACTIONS         155
#define TK_DISTRIBUTED          156
#define TK_CONSUMERS            157
#define TK_SUBSCRIPTIONS        158
#define TK_VNODES               159
#define TK_LIKE                 160
#define TK_TBNAME               161
#define TK_QTAGS                162
#define TK_AS                   163
#define TK_INDEX                164
#define TK_FUNCTION             165
#define TK_INTERVAL             166
#define TK_TOPIC                167
#define TK_WITH                 168
#define TK_META                 169
#define TK_CONSUMER             170
#define TK_GROUP                171
#define TK_DESC                 172
#define TK_DESCRIBE             173
#define TK_RESET                174
#define TK_QUERY                175
#define TK_CACHE                176
#define TK_EXPLAIN              177
#define TK_ANALYZE              178
#define TK_VERBOSE              179
#define TK_NK_BOOL              180
#define TK_RATIO                181
#define TK_NK_FLOAT             182
#define TK_OUTPUTTYPE           183
#define TK_AGGREGATE            184
#define TK_BUFSIZE              185
#define TK_STREAM               186
#define TK_INTO                 187
#define TK_TRIGGER              188
#define TK_AT_ONCE              189
#define TK_WINDOW_CLOSE         190
#define TK_IGNORE               191
#define TK_EXPIRED              192
#define TK_FILL_HISTORY         193
#define TK_SUBTABLE             194
#define TK_KILL                 195
#define TK_CONNECTION           196
#define TK_TRANSACTION          197
#define TK_BALANCE              198
#define TK_VGROUP               199
#define TK_MERGE                200
#define TK_REDISTRIBUTE         201
#define TK_SPLIT                202
#define TK_DELETE               203
#define TK_INSERT               204
#define TK_NULL                 205
#define TK_NK_QUESTION          206
#define TK_NK_ARROW             207
#define TK_ROWTS                208
#define TK_QSTART               209
#define TK_QEND                 210
#define TK_QDURATION            211
#define TK_WSTART               212
#define TK_WEND                 213
#define TK_WDURATION            214
#define TK_IROWTS               215
#define TK_CAST                 216
#define TK_NOW                  217
#define TK_TODAY                218
#define TK_TIMEZONE             219
#define TK_CLIENT_VERSION       220
#define TK_SERVER_VERSION       221
#define TK_SERVER_STATUS        222
#define TK_CURRENT_USER         223
#define TK_COUNT                224
#define TK_LAST_ROW             225
#define TK_CASE                 226
#define TK_END                  227
#define TK_WHEN                 228
#define TK_THEN                 229
#define TK_ELSE                 230
#define TK_BETWEEN              231
#define TK_IS                   232
#define TK_NK_LT                233
#define TK_NK_GT                234
#define TK_NK_LE                235
#define TK_NK_GE                236
#define TK_NK_NE                237
#define TK_MATCH                238
#define TK_NMATCH               239
#define TK_CONTAINS             240
#define TK_IN                   241
#define TK_JOIN                 242
#define TK_INNER                243
#define TK_SELECT               244
#define TK_DISTINCT             245
#define TK_WHERE                246
#define TK_PARTITION            247
#define TK_BY                   248
#define TK_SESSION              249
#define TK_STATE_WINDOW         250
#define TK_SLIDING              251
#define TK_FILL                 252
#define TK_VALUE                253
#define TK_NONE                 254
#define TK_PREV                 255
#define TK_LINEAR               256
#define TK_NEXT                 257
#define TK_HAVING               258
#define TK_RANGE                259
#define TK_EVERY                260
#define TK_ORDER                261
#define TK_SLIMIT               262
#define TK_SOFFSET              263
#define TK_LIMIT                264
#define TK_OFFSET               265
#define TK_ASC                  266
#define TK_NULLS                267
#define TK_ABORT                268
#define TK_AFTER                269
#define TK_ATTACH               270
#define TK_BEFORE               271
#define TK_BEGIN                272
#define TK_BITAND               273
#define TK_BITNOT               274
#define TK_BITOR                275
#define TK_BLOCKS               276
#define TK_CHANGE               277
#define TK_COMMA                278
#define TK_COMPACT              279
#define TK_CONCAT               280
#define TK_CONFLICT             281
#define TK_COPY                 282
#define TK_DEFERRED             283
#define TK_DELIMITERS           284
#define TK_DETACH               285
#define TK_DIVIDE               286
#define TK_DOT                  287
#define TK_EACH                 288
#define TK_FAIL                 289
#define TK_FILE                 290
#define TK_FOR                  291
#define TK_GLOB                 292
#define TK_ID                   293
#define TK_IMMEDIATE            294
#define TK_IMPORT               295
#define TK_INITIALLY            296
#define TK_INSTEAD              297
#define TK_ISNULL               298
#define TK_KEY                  299
#define TK_MODULES              300
#define TK_NK_BITNOT            301
#define TK_NK_SEMI              302
#define TK_NOTNULL              303
#define TK_OF                   304
#define TK_PLUS                 305
#define TK_PRIVILEGE            306
#define TK_RAISE                307
#define TK_REPLACE              308
#define TK_RESTRICT             309
#define TK_ROW                  310
#define TK_SEMI                 311
#define TK_STAR                 312
#define TK_STATEMENT            313
#define TK_STRICT               314
#define TK_STRING               315
#define TK_TIMES                316
#define TK_UPDATE               317
#define TK_VALUES               318
#define TK_VARIABLE             319
#define TK_VIEW                 320
#define TK_WAL                  321

#define TK_NK_SPACE   600
#define TK_NK_COMMENT 601
#define TK_NK_ILLEGAL 602
#define TK_NK_HEX     603  // hex number  0x123
#define TK_NK_OCT     604  // oct number
#define TK_NK_BIN     605  // bin format data 0b111

#define TK_NK_NIL 65535

#endif /*_TD_COMMON_TOKEN_H_*/
