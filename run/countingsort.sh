#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

SORTS_DIR="$(realpath "${THIS_DIR}/../out/sort")"
OUT_DIR="$(realpath "${THIS_DIR}/../out")"
DATA_DIR="$(realpath "${THIS_DIR}/../data")"

pushd "$(realpath "${THIS_DIR}/..")" >/dev/null 2>&1

echo ">>> building 'countingsort'"
make countingsort
MAKE_OK=$?

[[ $MAKE_OK -ne 0 ]] && echo "!!! failed to build 'countingsort'" && exit

popd >/dev/null 2>&1

for infile in "100k" "500k" "1m"; do
    THIS_INFILE="${DATA_DIR}/unsorted/${infile}_unique.dat"
    THIS_OUTFILE="${DATA_DIR}/sorted/countingsort/${infile}_unique.dat"

    # sort
    echo ">>> count-sorting integers from ${THIS_INFILE}"
    "${OUT_DIR}/sort/countingsort.out" "${THIS_INFILE}" > "${THIS_OUTFILE}"

    # check that ints are sorted
    "${OUT_DIR}/check.out" sorted "${THIS_OUTFILE}"

    [[ $? -ne 0 ]] && echo "!!! ${THIS_OUTFILE} may not be properly sorted"
done
