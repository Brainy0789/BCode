#ifndef VARS_H
#define VARS_H

typedef enum { VAL_INT, VAL_FLOAT, VAL_BOOL, VAL_STRING } ValueType;

typedef struct {
    ValueType type;
    union {
        int i;
        float f;
        bool b;
        char* s;
    } data;
} Value;

typedef struct VarEntry {
    char* key;
    Value value;
    struct VarEntry* next;
} VarEntry;

#define TABLE_SIZE 128

typedef struct {
    VarEntry* buckets[TABLE_SIZE];
} HashTable;
#endif