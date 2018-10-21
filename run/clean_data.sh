#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
DATA_DIR="$(readlink -f "${THIS_DIR}/../data")"

# function: clean cd

clean_cd() { for datafile in $(find . -maxdepth 1 -type f); do rm -f "$(readlink -f $datafile)"; done; };

# clean any stray data

pushd "${DATA_DIR}" >/dev/null 2>&1
clean_cd

# clean any sorted data

pushd "${DATA_DIR}/sorted" >/dev/null 2>&1
for dir in $(find . -maxdepth 1 -type d); do
    DIR_PATH="$(readlink -f $dir)"
    pushd "${DIR_PATH}" >/dev/null 2>&1
    clean_cd
    popd >/dev/null 2>&1
done
popd >/dev/null 2>&1

# clean up

popd >/dev/null 2>&1
