#ifndef AGENT_H
#define AGENT_H

// #include "board.h"
#include "book.h"
#include "move.h"
#include "play.h"

typedef struct Agent {
    Play* play;
    Book* book;
    int depth;
} Agent;

// Constructor
Agent* agent_create(const char*, int);

// Destructor
void agent_destroy(Agent**);

// Get best move as per Edax
int32_t agent_get_best_move(Agent*);

// Load game from file
bool agent_load_game(Agent*, const char*);

// Parse SGF string to Edax Board
// void agent_parse_board_string(const char*, Board*);

#endif
