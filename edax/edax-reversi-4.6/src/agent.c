#include <stdlib.h>
#include "agent.h"
#include "move.h"
#include "object.h"
#include "play.h"
#include "search.h"

// Owns Board* board. Owns depth (evidently).

Agent* agent_create(const char* file, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->play = ALLOCATE_OBJECT(Play);
    agent_load_game(agent, file);
    agent->depth = depth;
    return agent;
}

    /*
Agent* agent_create(const char* board_string, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->board = ALLOCATE_OBJECT(Board);
    agent_parse_board_string(board_string, agent->board);
    printf("%#016lx - %#016lx\n", agent->board->player, agent->board->opponent);
    agent->depth = depth;
    return agent;
}*/

void agent_destroy(Agent** agent_p) {
    if ((agent_p == NULL) | (*agent_p == NULL)) return;
    Agent* agent = *agent_p;
    free(agent->play);
    agent->play = NULL;
    agent->depth = 0;
    free(agent);
    *agent_p = NULL;
}

void agent_load_game(Agent* agent, const char* file) {
    play_load(agent->play, file);
}

Move* agent_get_best_move(Agent* agent) {
    play_go(agent->play, false);
    Move* move = agent->play->result.move;
    return move;
    /* Search* search = ALLOCATE_OBJECT(Search);
    search_init(search);
    printf("Init search!\n");
    search_set_board(search, agent->board, agent->board->player);
    printf("Set board!\n");
    search->options.depth = agent->depth;
    search_run(search);
    printf("Search run!\n");
    int move_index = search->result->move;
    Move* move;
    board_get_move(agent->board, move_index, move);
    printf("Get best move!\n");
    return move; */
}

// Thin wrapper around `board_set()`.
/* void agent_parse_board_string(const char* board_string, Board* board) {
    board_set(board, board_string);
    // board_from_FEN(board, board_string);
}*/
