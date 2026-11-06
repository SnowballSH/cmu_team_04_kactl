# Shared compiler selection for the build checks. Respect explicit overrides.
if [ -z "${CXX:-}" ]; then
    if command -v g++-16 >/dev/null 2>&1; then
        CXX=g++-16
    else
        CXX=g++
    fi
fi
export CXX
