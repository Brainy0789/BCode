#ifndef VM_H
#define VM_H

#include <stdbool.h>

typedef enum
{
    PRINT = 0,
    HALT = 1,
    ADD = 2,
    SUB = 3,
    SET = 4,
    JUMP = 5,
    CJUMP = 6,
    SUBPROGRAM = 7,
    CALL = 8,
    RET = 9,
    ENDSUB = 10,
    PRINTLN = 11,
    FREE = 12,
    ALLOCA = 13
} Instruction;


int interp(char *filePath, bool debug);

#endif
