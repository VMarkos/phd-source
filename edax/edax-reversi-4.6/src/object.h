#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

#define ALLOCATE_OBJECT(type, object_type) \
    (type*)(sizeof(type), object_type)

// TODO: Fix this to check for NULLs and allocate properly!

#endif
