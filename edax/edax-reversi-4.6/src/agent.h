#ifndef AGENT_H
#define AGENT_H

#include "board.h"
#include "move.h"

typedef struct Agent {
    Board board;
    int depth;
} Agent;

// Constructor
Agent* agent_create(Board*, int);

// Destructor
void agent_destroy(Agent**);

// Get best move as per Edax
Move* agent_get_best_move();

#endif
