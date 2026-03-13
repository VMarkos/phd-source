#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define ALLOCATE_OBJECT(type) \
    (type*)mallocate(sizeof(type))

#define ALLOCATE_ARRAY(type, length) \
    (type*)callocate(sizeof(type) * length)

#define FREE_ARRAY(type, array, length) \
    for (int i = 0; i < length; i++) { \
        *(array + i) = 0; \
        free(array + i); \
    } \
    array = NULL;

#define FREE_OBJECT_ARRAY(type, array, length) \
    for (int i = 0; i < length; i++) { \
        type##_destroy(&(array + i)); \
    } \
    array = NULL;


void* mallocate(size_t);
void* callocate(size_t);
void safe_fwrite(const void*, size_t, size_t, FILE*);

#endif
