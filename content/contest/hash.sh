#!/usr/bin/env bash
# Hash code, ignoring whitespace and comments, with GNU preprocessing.
set -euo pipefail
if [[ -z "${CPP:-}" ]]; then
    if command -v cpp-16 >/dev/null 2>&1; then CPP=cpp-16; else CPP=cpp; fi
fi
"$CPP" -dD -P -fpreprocessed | tr -d '[:space:]' |
    python3 -c 'import hashlib, sys; print(hashlib.md5(sys.stdin.buffer.read()).hexdigest()[:6])'
