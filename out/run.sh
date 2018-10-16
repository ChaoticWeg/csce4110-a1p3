#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# clean and make all
pushd "${THIS_DIR}/.." >/dev/null 2>&1
make clean && make all
popd >/dev/null 2>&1

# run scripts
bash "${THIS_DIR}/generate.sh"
