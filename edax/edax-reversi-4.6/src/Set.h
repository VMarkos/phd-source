#ifndef SET_H
#define SET_H

#include "board.h"

// Implementation of board hash set - utilises board symmetry while hashing.
// Does not own `boards`!

typedef struct Set {
    size_t capacity;
    size_t count;
    Board* boards;
} Set;


Set* set_create();
Set* set_create(size_t);
void set_destroy(Set**);

bool set_contains(Set*, Board*);
void set_add(Set*, Board*);
void set_remove(Set*, Board*);

long set_hash(Board*);

#endif
