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
    const size_t written = fwrite(buffer, size, count, stream);
    if (written < count) exit(1);
}

void safe_fread(const void* buffer, size_t size, size_t count, FILE* stream) {
    const size_t read = fread(buffer, size, count, stream);
    if (read < count) {
        if (feof(stream)) {
            perror("Could not open file: Unexpected EOF.\n");
            exit(1);
        } else if (ferror(stream)) {
            perror("Could not open file.\n");
            exit(1);
        }
    }
}

void safe_fseek(FILE* stream, long offset, int whence) {
    int status_code = fseek(stream, offset, whence);
    if (status_code < 0) exit(1);
}

void safe_offset_read(const void* buffer, size_t size, size_t count, FILE* stream, long offset) {
    safe_fseek(stream, offset, SEEK_CUR);
    safe_fread(buffer, size, count, stream);
}
