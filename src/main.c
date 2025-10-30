#include <stdio.h> 
#include "vm.h"

char vers[] = "0.1.0";

int main()
{
    printf("BCode Compiler v%s\n", vers);
    interp("tests/test.ba");
    return 0;
}