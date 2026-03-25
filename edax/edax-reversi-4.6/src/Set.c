#include "set.h"
#include "board.h"

Set* set_create() {
    return set_create(100);
}

Set* set_create(size_t capacity) {
    Set* set = ALLOCATE_OBJECT(Set);
    set->capacity = capacity;
    set->count = 0;
    ALLOCATE_ARRAY(Board, set->capacity);
    return set;
}

void set_destroy(Set** set_p) {
    if (set_p == NULL || *set_p == NULL) return;
    Set* set = *set_p;
    set->capacity = 0;
    set->count = 0;
    set = NULL;
}

bool set_contains(Set* set, Board* board) {
}

void set_add(Set* set, Board* board) {
}

void set_remove(Set* set, Board* board) {
}

long set_hash(Board* board) {
    // TODO: compute hash value for board.
}
