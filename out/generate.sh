#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

DATA_DIR="${THIS_DIR}/../data"

# generate unique ints
[[ ! -f "${DATA_DIR}/100k_unique.dat" ]] && ./generate.out --count 100000  --type unique > "${DATA_DIR}/100k_unique.dat"
[[ ! -f "${DATA_DIR}/500k_unique.dat" ]] && ./generate.out --count 500000  --type unique > "${DATA_DIR}/500k_unique.dat"
[[ ! -f "${DATA_DIR}/1m_unique.dat"   ]] && ./generate.out --count 1000000 --type unique > "${DATA_DIR}/1m_unique.dat"

# generate limited-range ints
[[ ! -f "${DATA_DIR}/100k_limited.dat" ]] && ./generate.out --count 100000   --type limited > "${DATA_DIR}/100k_limited.dat"
[[ ! -f "${DATA_DIR}/500k_limited.dat" ]] && ./generate.out --count 500000   --type limited > "${DATA_DIR}/500k_limited.dat"
[[ ! -f "${DATA_DIR}/1m_limited.dat"   ]] && ./generate.out --count 1000000  --type limited > "${DATA_DIR}/1m_limited.dat"
