#!/bin/bash

echo "Compiling BCode..."
mkdir -p output 

if clang src/main.c src/vm.c -o output/BCode; then
    echo "Compilation succeeded. Running..."
    ./output/BCode
else
    echo "Compilation failed."
    exit 1
fi
