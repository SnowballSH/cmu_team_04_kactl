# Hashes a file, ignoring all whitespace and comments. Use for
# verifying that code was correctly typed.
CPP=${CPP:-$(command -v cpp-16 || echo cpp)}
"$CPP" -dD -P -fpreprocessed | tr -d '[:space:]' | md5sum | cut -c-6
