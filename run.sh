#!/usr/bin/env bash

THIS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"
pushd "${THIS_DIR}" >/dev/null 2>&1

# clean and make all

echo ">>> cleaning..."
make clean
[[ $? -ne 0 ]] && echo "!!! failed to clean" && exit

echo ">>> building..."
make all
[[ $? -ne 0 ]] && echo "!!! failed to build" && exit

# generate and check uniqueness of number sets

DATA_DIR="$(readlink -f "${THIS_DIR}/data")"

for type in limited unique; do
    echo ">>> generating $type ints if we need to..."

    for size in 100k 500k 1m; do
        case $size in 100k) count_arg="100000";; 500k) count_arg="500000";; 1m) count_arg="1000000";; *) count_arg="0";; esac

        filepath="$(readlink -f "${DATA_DIR}/unsorted/${size}_${type}.dat")"
        [[ ! -f "${filepath}" ]] && echo "!!! need $size $type ints. generating..." && "${THIS_DIR}/out/generate.out" --count $count_arg --type $type > "${filepath}"
        [[ "${type}" == "unique" ]] && [[ -f "${filepath}" ]] && "${THIS_DIR}/out/check.out" unique "${filepath}"
    done

done

# sort!

bash "${THIS_DIR}/run/countingsort.sh"
bash "${THIS_DIR}/run/quicksort.sh"

# clean up

popd >/dev/null 2>&1
