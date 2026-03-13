#include <stdlib.h>
#include <stdio.h>
#include "object.h"

void* mallocate(size_t size) {
    void* p = malloc(size);
    if (p == NULL) exit(1);
    return p;
}

void* callocate(size_t size) {
    void* p = calloc(size);
    if (p == NULL) exit(1);
    return p;
}

void safe_fwrite(const void* buffer, size_t size, size_t count, FILE* stream) {
    size_t written = fwrite(buffer, size, count, stream);
    if (written < count) exit(1);
}
