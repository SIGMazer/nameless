#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "value.h"
#include "vm.h"


typedef struct{
    int count;
    int capacity;
    uint8_t *items;
} arr;


int main()
{
    initVM();

    Chunk chunk; 

    initChunk(&chunk);

    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    

    int constant2 = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant2, 123);

    writeChunk(&chunk, OP_ADD, 123);

    writeChunk(&chunk, OP_RETURN, 123);

    interpret(&chunk);

    freeVM();

    return EXIT_SUCCESS;
}
