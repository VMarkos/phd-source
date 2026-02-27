#include <stdlib.h>
#include "agent.h"
#include "book.h"
#include "ui.h"
#include "object.h"
#include "options.h"
#include "play.h"
#include "search.h"

// Owns Board* board. Owns depth (evidently).

extern bool book_verbose;

Agent* agent_create(const char* file, int depth) {
    Agent* agent = ALLOCATE_OBJECT(Agent);
    agent->play = ALLOCATE_OBJECT(Play);
    agent->book = ALLOCATE_OBJECT(Book);
    bool game_loaded = agent_load_game(agent, file);
    if (!game_loaded) printf("Failed to load game!\n");
    agent->depth = depth;
    return agent;
}


void agent_destroy(Agent** agent_p) {
    if ((agent_p == NULL) | (*agent_p == NULL)) return;
    Agent* agent = *agent_p;
    free(agent->play);
    agent->play = NULL;
    free(agent->book);
    agent->book = NULL;
    agent->depth = 0;
    free(agent);
    *agent_p = NULL;
}

bool agent_load_game(Agent* agent, const char* file) {
    book_verbose = true;
    play_init(agent->play, agent->book); // Maybe load a book somehow here, even an empty one?
    agent->book->search = &agent->play->search;
    book_load(agent->book, options.book_file);
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
