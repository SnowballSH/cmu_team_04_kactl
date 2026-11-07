#!/usr/bin/env bash
DIR=${1:-.}
. "$DIR/doc/scripts/compiler.sh"

# use a precompiled header for the template to improve perf
"$CXX" -Wall -Wextra -Wfatal-errors -Wconversion -std=c++20 -x c++-header "$DIR/content/contest/template.cpp" || exit $?
trap "rm -f $DIR/content/contest/template.cpp.gch" EXIT

SCRIPT_DIR=$DIR/doc/scripts
tests="$(find "$DIR/content" -name '*.h' | grep -vFf "$SCRIPT_DIR/skip_headers")"
echo "skipped: "
find "$DIR/content" -name '*.h' | grep -Ff "$SCRIPT_DIR/skip_headers"
declare -i pass=0
declare -i fail=0
failHeaders=""
while IFS= read -r test; do
    if [[ "$test" == */SIMD.h ]] && ! "$CXX" -dumpmachine | grep -Eq '(^|-)x86_64|i[3-6]86'; then
        echo "Skipped SIMD.h: requires an x86 target"
        continue
    fi
    echo "$(basename "$test"): "
    "$SCRIPT_DIR/test-compiles.sh" "$test"
    retCode=$?
    if (($retCode != 0)); then
        echo $retCode
        fail+=1
        failHeaders="$failHeaders$test\n"
    else
        pass+=1
    fi
    echo
done <<< "$tests"
echo "$pass/$(($pass+$fail)) tests passed"
if (($pass == 0)); then
    echo "No tests found (make sure skip_headers doesn't have whitespace lines)"
    exit 1
elif (($fail == 0)); then
    echo "No tests failed"
    exit 0
else
    echo -e "These tests failed: \n $failHeaders"
    exit 1
fi
