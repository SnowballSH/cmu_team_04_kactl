#!/usr/bin/env bash
. "$(dirname "$0")/compiler.sh"
mkdir -p build
FILE="$1"
cat >build/temp.cpp <<EOF
#include "../content/contest/template.cpp"
#include "../$FILE"
EOF
"$CXX" -Wall -Wextra -Wfatal-errors -Wconversion -std=c++20 build/temp.cpp -o build/header-check && rm build/header-check build/temp.cpp
