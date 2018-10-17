#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
DATA_DIR="$(realpath "${THIS_DIR}/../data/unsorted")"
OUT_DIR="$(realpath "${THIS_DIR}/../out")"
pushd "${THIS_DIR}" >/dev/null 2>&1

# make check

pushd "${THIS_DIR}/.." >/dev/null 2>&1
echo ">>> building 'check'..."
make check
[[ $? -ne 0 ]] && echo "!!! failed to build 'check'" && exit
popd >/dev/null 2>&1

# check that unique sets are, in fact, unique

echo ">>> checking uniqueness of sets..."

"${OUT_DIR}/check.out" unique "${DATA_DIR}/100k_unique.dat" ; CHECK_100K=$?
"${OUT_DIR}/check.out" unique "${DATA_DIR}/500k_unique.dat" ; CHECK_500K=$?
"${OUT_DIR}/check.out" unique "${DATA_DIR}/1m_unique.dat"   ; CHECK_1M=$?

[[ $CHECK_100K -ne 0 ]] && echo "!!! 100k_unique.dat is not unique!";
[[ $CHECK_500K -ne 0 ]] && echo "!!! 500k_unique.dat is not unique!";
[[ $CHECK_1M -ne 0 ]]   && echo "!!! 1m_unique.dat is not unique!";

# clean up

popd >/dev/null 2>&1
