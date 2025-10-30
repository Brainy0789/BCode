#include "vars.h"
#include <stdlib.h>

unsigned int hash(const char* str) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % TABLE_SIZE;
}

Value* getVariable(HashTable* table, const char* key) {
    unsigned int idx = hash(key);
    VarEntry* entry = table->buckets[idx];
    while (entry) {
        if (strcmp(entry->key, key) == 0)
            return &entry->value;
        entry = entry->next;
    }
    return NULL;
}

void setVariable(HashTable* table, const char* key, Value val) {
    unsigned int idx = hash(key);
    VarEntry* entry = table->buckets[idx];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = val;
            return;
        }
        entry = entry->next;
    }

    entry = malloc(sizeof(VarEntry));
    entry->key = strdup(key);
    entry->value = val;
    entry->next = table->buckets[idx];
    table->buckets[idx] = entry;
}
