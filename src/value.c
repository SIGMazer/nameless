#include "value.h"
#include "memory.h"




void writeValueArray(ValueArray *arr, Value value){
    DA_APPEND(arr, value);
}

void freeValueArray(ValueArray *arr){
    DA_FREE(arr);
}
void printValue(Value value){
    printf("%g", value);
}
