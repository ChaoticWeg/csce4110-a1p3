#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

SORTS_DIR="$(readlink -f "${THIS_DIR}/../out/sort")"
OUT_DIR="$(readlink -f "${THIS_DIR}/../out")"
DATA_DIR="$(readlink -f "${THIS_DIR}/../data")"

pushd "${THIS_DIR}/.." >/dev/null 2>&1

echo ">>> building 'quicksort'"
make quicksort
MAKE_OK=$?

[[ $MAKE_OK -ne 0 ]] && echo "!!! failed to build 'quicksort'" && exit

popd >/dev/null 2>&1

for infile in "100k" "500k" "1m"; do
    THIS_INFILE="${DATA_DIR}/unsorted/${infile}_unique.dat"
    THIS_OUTFILE="${DATA_DIR}/sorted/quicksort_all/${infile}_unique.dat"

    echo ">>> quicksorting integers from ${THIS_INFILE}"
    "${OUT_DIR}/sort/quicksort.out" "${THIS_INFILE}" > "${THIS_OUTFILE}"

    "${OUT_DIR}/check.out" sorted "${THIS_OUTFILE}"
    [[ $? -ne 0 ]] && echo "!!! ${THIS_OUTFILE} may not be properly sorted"
done
