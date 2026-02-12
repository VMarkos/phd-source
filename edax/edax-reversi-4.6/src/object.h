#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define ALLOCATE_OBJECT(type) \
    (type*)mallocate(sizeof(type))

void* mallocate(size_t);


#endif
