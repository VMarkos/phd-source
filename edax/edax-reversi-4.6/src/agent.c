#include <stdlib.h>
#include "agent.h"
#include "move.h"
#include "object.h"

// Owns Board* board. Owns depth (evidently).

Agent* agent_create(char* board_string, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->board = ALLOCATE_OBJECT(Board);
    agent_parse_board_string(board_string, agent->board);
    agent->depth = depth;
    return agent;
}

void agent_destroy(Agent** agent_p) {
    if (agent_p == NULL | *agent_p == NULL) return;
    Agent* agent = *agent_p;
    free(agent->board);
    agent->board = NULL;
    agent->depth = 0;
    free(agent);
    *agent_p = NULL;
}

Move* agent_get_best_move() {

}

// Thin wrapper around `board_set()`.
void agent_parse_board_string(const char* board_string, Board* board) {
    board_set(board, board_string);
}
