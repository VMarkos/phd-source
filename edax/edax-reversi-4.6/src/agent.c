#include <stdlib.h>
#include "agent.h"
#include "move.h"
#include "object.h"
#include "search.h"

// Owns Board* board. Owns depth (evidently).

Agent* agent_create(const char* board_string, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->board = ALLOCATE_OBJECT(Board);
    agent_parse_board_string(board_string, agent->board);
    printf("%#016x - %#016x\n", agent->board->player, agent->board->opponent);
    agent->depth = depth;
    return agent;
}

void agent_destroy(Agent** agent_p) {
    if ((agent_p == NULL) | (*agent_p == NULL)) return;
    Agent* agent = *agent_p;
    free(agent->board);
    agent->board = NULL;
    agent->depth = 0;
    free(agent);
    *agent_p = NULL;
}

Move* agent_get_best_move(Agent* agent) {
    Search* search = ALLOCATE_OBJECT(Search);
    search_init(search);
    printf("Init search!\n");
    search_set_board(search, agent->board, agent->board->player); // FIXME: Compute the player's turn to play
    printf("Set board!\n");
    search->options.depth = agent->depth; // TODO find how to use the board in search_run
    int search_success = search_run(search);
    printf("Search run!\n");
    int move_index = search->result->move;
    Move* move;
    board_get_move(agent->board, move_index, move);
    printf("Get best move!\n");
    return move;    
}

// Thin wrapper around `board_set()`.
void agent_parse_board_string(const char* board_string, Board* board) {
    board_set(board, board_string);
}
