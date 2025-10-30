@echo off
echo Compiling BCode...

REM Create output directory if it doesn't exist
if not exist output (
    mkdir output
)

REM Check if clang exists
where clang >nul 2>nul
if %ERRORLEVEL%==0 (
    set COMPILER=clang
) else (
    where gcc >nul 2>nul
    if %ERRORLEVEL%==0 (
        set COMPILER=gcc
    ) else (
        echo No compiler found (clang or gcc required).
        exit /b 1
    )
)

REM Compile
%COMPILER% src\main.c src\vm.c src\compiler.c -o output\BCode
if %ERRORLEVEL%==0 (
    echo Compilation succeeded. Running...
    output\BCode
) else (
    echo Compilation failed.
    exit /b 1
)
