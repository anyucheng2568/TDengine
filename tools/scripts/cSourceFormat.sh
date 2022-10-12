#!/bin/bash

PRJ_ROOT_DIR=$( readlink -f -- "`dirname $0`/../.." )

ORIGIN_DIR=`pwd`

cd ${PRJ_ROOT_DIR}

# include/
for f in `find ${PRJ_ROOT_DIR}/include/os -regex '.*\.\(cpp\|hpp\|cu\|c\|h\)'`; do
    clang-format -i $f
done

cd ${ORIGIN_DIR}