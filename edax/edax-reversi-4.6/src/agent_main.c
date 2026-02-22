#include <stdio.h>
#include "agent.h"
#include "move.h"

int main(void) {
    const char* board_str = "...................................wb......bw................... b";
    int depth = 13;
    printf("Depth: %d\n", depth);
    Agent* agent = agent_create(board_str, depth);
    printf("Agent created!\n");
    Move* move = agent_get_best_move(agent);
    printf("Move computed\n");
    char* move_string;
    printf("Move: %s\n", move_to_string(move->x, agent->board->player, move_string));
    agent_destroy(&agent);
    printf("Agent destroyed\n");
    return 0;
}
