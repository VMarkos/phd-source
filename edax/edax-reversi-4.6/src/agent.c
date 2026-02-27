#include <stdlib.h>
#include "agent.h"
// #include "move.h"
#include "ui.h"
#include "object.h"
#include "play.h"
#include "search.h"

// Owns Board* board. Owns depth (evidently).

Agent* agent_create(const char* file, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->play = ALLOCATE_OBJECT(Play);
    bool game_loaded = agent_load_game(agent, file);
    if (!game_loaded) printf("Failed to load game!\n");
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

bool agent_load_game(Agent* agent, const char* file) {
    play_init(agent->play, NULL); // Maybe load a book somehow here, even an empty one?
    agent->play->search.id = 1; // hard coded as in UI
    search_set_observer(&agent->play->search, search_observer);
    agent->play->type = UI_NBOARD;
    return play_load(agent->play, file);
}

int32_t agent_get_best_move(Agent* agent) {
    printf("play go not run yet\n");
    play_go(agent->play, true);
    printf("play_go run!\n");
    int32_t move_x = play_get_last_move(agent->play)->x;
    printf("last move retrieved!\n");
    return move_x;
}

// Thin wrapper around `board_set()`.
/* void agent_parse_board_string(const char* board_string, Board* board) {
    board_set(board, board_string);
    // board_from_FEN(board, board_string);
}*/
