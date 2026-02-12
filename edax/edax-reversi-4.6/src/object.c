#include <stdlib.h>
#include "object.h"

void* mallocate(size_t size) {
    void* p = malloc(size);
    if (p == NULL) exit(1);
    return p;
}
