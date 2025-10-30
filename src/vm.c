#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include "vm.h"
#include "util.h"

int interp(char *filePath, bool debug)
{
    char* program = getFileContents(filePath);
    if (!program) {
        return 1;
    }
    int pc = 0;
    int inst = 0;

    if (debug)
    {
        printf("Running program...");
    }

    int oldPC = 0; //used for subprograms

    while (program[pc] != '\0') {
        int inst = (int)program[pc];

        switch (inst) {
            case PRINT:
                break;

            case ADD:
                break;

            case HALT:
                return 0;

            default:
                fprintf(stderr, "Unknown instruction: %d\n", inst);
                return 1;
        }

        pc++;
    }

    free(program);
    return 0;
}