#!/bin/bash

echo "Compiling BCode..."
mkdir -p output

# Check for clang, fallback to gcc
if command -v clang >/dev/null 2>&1; then
    COMPILER=clang
elif command -v gcc >/dev/null 2>&1; then
    COMPILER=gcc
else
    echo "No compiler found (clang or gcc required)."
    exit 1
fi

# Compile
if $COMPILER src/main.c src/vm.c src/compiler.c src/util.c -o output/BCode; then
    echo "Compilation succeeded. Running..."
    ./output/BCode
else
    echo "Compilation failed."
    exit 1
fi
