#include "chunk.h"


void initChunk(Chunk *chunk){
    chunk->count = 0;
    chunk->capacity = 0;
    chunk->items = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, size_t line){

    if(chunk->capacity < chunk->count + 1){
        chunk->capacity =chunk->capacity < 8 ? 8 : chunk->capacity * 2; 
        chunk->items = realloc(chunk->items, chunk->capacity * sizeof(uint8_t)); 
        chunk->lines = realloc(chunk->lines, chunk->capacity * sizeof(size_t)); 
    }

    chunk->items[chunk->count] = byte;
    chunk->lines[chunk->count] = line;
    chunk->count++;
}

void freeChunk(Chunk *chunk){
    DA_FREE(chunk);
    freeValueArray(&chunk->constants);
    free(chunk->lines);
}

int addConstant(Chunk *chunk, Value value){
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}
