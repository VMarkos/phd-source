#include <stdio.h>
#include <string.h>
#include "agent.h"
#include "board.h"
#include "eval.h"
#include "move.h"
#include "options.h"

int main(void) {
    // const char* board_str = "...........................wb......bw............................ b";
    options.eval_file = string_duplicate("data/eval.dat");
    options.verbosity = false;
    eval_open(options.eval_file);
    const char* file = "tests/game_001.txt";
    int depth = 13;
    Agent* agent = agent_create(file, depth);
    // board_print(&agent->play->board, agent->play->player, stdout);
    int32_t move_x = agent_get_best_move(agent);
    agent_destroy(&agent);
    return 0;
}
