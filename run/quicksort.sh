#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

SORTS_DIR="$(realpath "${THIS_DIR}/../out/sort")"
OUT_DIR="$(realpath "${THIS_DIR}/../out")"
DATA_DIR="$(realpath "${THIS_DIR}/../data")"

pushd "$(realpath "${THIS_DIR}/..")" >/dev/null 2>&1

echo ">>> building 'quicksort'"
make quicksort
MAKE_OK=$?

[[ $MAKE_OK -ne 0 ]] && echo "!!! failed to build 'quicksort'" && exit

popd >/dev/null 2>&1

echo ">>> using 'quicksort' for 100k, 500k, and 1m ints"

"${OUT_DIR}/sort/quicksort.out" "${DATA_DIR}/unsorted/100k_unique.dat" > "${DATA_DIR}/sorted/quicksort_all/100k_unique.dat"
"${OUT_DIR}/sort/quicksort.out" "${DATA_DIR}/unsorted/500k_unique.dat" > "${DATA_DIR}/sorted/quicksort_all/500k_unique.dat"
"${OUT_DIR}/sort/quicksort.out" "${DATA_DIR}/unsorted/1m_unique.dat" > "${DATA_DIR}/sorted/quicksort_all/1m_unique.dat"