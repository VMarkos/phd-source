#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define ALLOCATE_OBJECT(type) \
    (type*)mallocate(sizeof(type))

#define FREE_ARRAY(type, array, length) \
    type* = (type*) array; \
    for (int i = 0; i < length; i++) { \
        *(array + i) = 0; \
        free(array + i); \
    } \
    array = NULL;

void* mallocate(size_t);
void free_array(void*, int);

#endif
