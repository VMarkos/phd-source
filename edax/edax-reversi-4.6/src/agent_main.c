#include <stdio.h>
#include "agent.h"
#include "board.h"
#include "move.h"

int main(void) {
    // const char* board_str = "...........................wb......bw............................ b";
    const char* file = "tests/game_001.txt";
    int depth = 13;
    printf("Depth: %d\n", depth);
    Agent* agent = agent_create(file, depth);
    printf("Agent created!\n");
    printf("=== board set at:\n");
    board_print(&agent->play->board, agent->play->player, stdout);
    int32_t move_x = agent_get_best_move(agent);
    printf("Move computed\n");
    // char* move_string;
    // FIXME: Move is not actually computed, it returns a NULL pointer
    printf("Move: %d\n", move_x);
    agent_destroy(&agent);
    printf("Agent destroyed\n");
    return 0;
}
