#include "chunk.h"


void writeChunk(Chunk *chunk, uint8_t byte, size_t line){
    if(chunk->count == chunk->capacity){
        chunk->capacity = chunk->capacity < 8 ? 8 : chunk->capacity * 2;
        chunk->items = realloc(chunk->items, chunk->capacity); 
        chunk->lines = realloc(chunk->lines, chunk->capacity * sizeof(int));
        if(chunk->items == NULL){
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
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
