#ifndef MEMORY_H
#define MEMORY_H


#include "common.h"


#define DA_APPEND(da, value) \
    do { \
        if ((da)->capacity == (da)->count) { \
            (da)->capacity = (da)->capacity == 0 ? 8 : (da)->capacity * 2; \
            (da)->items = realloc((da)->items, sizeof(*(da)->items) * (da)->capacity); \
        } \
        (da)->items[(da)->count] = value; \
        (da)->count++; \
    } while (0)

#define DA_FREE(da) \
    do { \
        free((da)->items); \
        (da)->items= NULL; \
        (da)->capacity = 0; \
        (da)->count = 0; \
    } while (0)


#endif // !MEMORY_H
