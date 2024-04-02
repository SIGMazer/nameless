#include "common.h"
#include "debug.h"
#include "value.h"



void disassembleChunk(Chunk *chunk, const char *name){
    printf("== %s ==\n", name);
    for (size_t offset = 0; offset < chunk->count;){
        offset = disassembleInstruction(chunk, offset);
    }
}

static int simpleInstruction(const char *name, int offset){
    printf("%s\n", name);
    return offset + 1;
}

static int constantInstruction(const char *name, Chunk *chunk, int offset){
    uint8_t constantIndex = chunk->items[offset + 1];
    printf("%-16s %4d '", name, constantIndex);
    printValue(chunk->constants.items[constantIndex]);
    printf("'\n");
    return offset + 2;
}


int disassembleInstruction(Chunk *chunk, int offset){
    printf("%04d ", offset);
    if(offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1]){
        printf("   | ");
    }else{
        printf("%4ld ", chunk->lines[offset]);
    }

    uint8_t instruction = chunk->items[offset];
    switch (instruction){
        case OP_CONSTANT:
            return constantInstruction("OP_CONSTANT", chunk, offset);
        case OP_RETURN:
            return simpleInstruction("OP_RETURN", offset);
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

