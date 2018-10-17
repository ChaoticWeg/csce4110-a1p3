#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

# clean and make all

make clean
[[ $? -ne 0 ]] && echo "failed to clean" && exit

# run scripts

RUN_DIR="$(realpath "${THIS_DIR}/run")"
bash "${RUN_DIR}/generate.sh"
bash "${RUN_DIR}/check.sh"

# clean up

popd >/dev/null 2>&1
