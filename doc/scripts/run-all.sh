#!/usr/bin/env bash
DIR=${1:-.}
. "$DIR/doc/scripts/compiler.sh"

# use a precompiled header for the template to improve perf
"$CXX" -Wall -Wfatal-errors -Wconversion -std=c++20 -O2 "$DIR/stress-tests/utilities/template.h" || exit $?
trap "rm -f $DIR/stress-tests/utilities/template.h.gch" EXIT

tests="$(find "$DIR/stress-tests" -name '*.cpp')"
declare -i pass=0
declare -i fail=0
failTests=""
# Request extra stack for recursive graph tests, within the platform limit.
ulimit -s 524288 2>/dev/null || ulimit -s hard 2>/dev/null || true
mkdir -p build
while IFS= read -r test; do
    echo "$(basename "$test"): "
    start=$(date +%s)
    "$CXX" -Wall -Wfatal-errors -Wconversion -std=c++20 -O2 "$test" -o build/stress-test && ./build/stress-test
    retCode=$?
    if (($retCode != 0)); then
        echo "Failed with $retCode"
        fail+=1
        failTests="$failTests$test\n"
    else
        pass+=1
    fi
    end=$(date +%s)
    runtime=$((end - start))
    echo "Took $runtime seconds"
    rm -f build/stress-test
    echo
done <<< "$tests"
echo "$pass/$(($pass+$fail)) tests passed"
if (($fail == 0)); then
    echo "No tests failed"
    exit 0
else
    echo -e "These tests failed: \n $failTests"
    exit 1
fi
