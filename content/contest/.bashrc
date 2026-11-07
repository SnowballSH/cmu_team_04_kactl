if command -v g++-16 >/dev/null 2>&1; then
    export CXX=${CXX:-g++-16}
else
    export CXX=${CXX:-g++}
fi
alias c='$CXX -Wall -Wconversion -Wfatal-errors -g -std=c++20 \
    -fsanitize=undefined,address'
if command -v xmodmap >/dev/null 2>&1 && [ -n "${DISPLAY:-}" ]; then
    xmodmap -e 'clear lock' -e 'keycode 66=less greater' #caps = <>
fi
