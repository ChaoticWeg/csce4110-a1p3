#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

DATA_DIR="${THIS_DIR}/../data"

# generate unique ints
[[ ! -f "${DATA_DIR}/1k_unique.dat" ]] && ./generate.out --count 100000  --type unique
[[ ! -f "${DATA_DIR}/5k_unique.dat" ]] && ./generate.out --count 500000  --type unique
[[ ! -f "${DATA_DIR}/1m_unique.dat" ]] && ./generate.out --count 1000000 --type unique

# generate limited-range ints
[[ ! -f "${DATA_DIR}/1k_limited.dat" ]] && ./generate.out --count 100000   --type limited
[[ ! -f "${DATA_DIR}/5k_limited.dat" ]] && ./generate.out --count 500000   --type limited
[[ ! -f "${DATA_DIR}/1m_limited.dat" ]] && ./generate.out --count 1000000  --type limited
