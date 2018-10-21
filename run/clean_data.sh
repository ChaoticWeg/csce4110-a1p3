#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
DATA_DIR="${THIS_DIR}/../data"

# clean any stray data
for datafile in $(find "${DATA_DIR}" -maxdepth 1 -type f); do rm -f "$datafile"; done;

# clean any sorted data

for datadir in $(find "${DATA_DIR}/sorted" -maxdepth 1 -type d); do
    for datafile in $(find "${datadir}" -maxdepth 1 -type f); do rm -f "$datafile"; done;
done
