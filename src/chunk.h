#ifndef CHUNK_H 
#define CHUNK_H

#include "common.h"
#include "memory.h"
#include "value.h"


typedef enum {
    OP_CONSTANT,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NEGATE,
    OP_RETURN,
} OpCode;

typedef struct {
    size_t capacity;
    size_t count;
    uint8_t* items; //code
    ValueArray constants;
    size_t* lines;
} Chunk;


void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, size_t line);
void freeChunk(Chunk* chunk);
int addConstant(Chunk* chunk, Value value);


#endif // CHUNK_H
