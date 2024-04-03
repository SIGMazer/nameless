#ifndef VALUE_H
#define VALUE_H

#include "common.h"

typedef double Value;

typedef struct {
    size_t capacity;
    size_t count;
    Value* items;
} ValueArray;

void initValueArray(ValueArray* va);
void writeValueArray(ValueArray* va, Value value);
void freeValueArray(ValueArray* va);
void printValue(Value value);

#endif // !VALUE_H
