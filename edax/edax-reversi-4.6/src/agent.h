#ifndef AGENT_H
#define AGENT_H

#include "board.h"
#include "move.h"

typedef struct Agent {
    Board* board;
    int depth;
} Agent;

// Constructor
Agent* agent_create(char*, int);

// Destructor
void agent_destroy(Agent**);

// Get best move as per Edax
Move* agent_get_best_move();

// Parse SGF string to Edax Board
void agent_parse_board_string(const char*, Board*);

#endif
