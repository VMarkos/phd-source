#include <stdio.h>
#include "agent.h"
#include "move.h"

int main(void) {
    // const char* board_str = "...................................wb......bw................... b";
    const char* file = "../tests/game_001.txt";
    int depth = 13;
    printf("Depth: %d\n", depth);
    Agent* agent = agent_create(file, depth);
    printf("Agent created!\n");
    Move* move = agent_get_best_move(agent);
    printf("Move computed\n");
    // char* move_string;
    // FIXME: Move is not actually computed, it returns a NULL pointer
    printf("Move: %d\n", move->x);
    agent_destroy(&agent);
    printf("Agent destroyed\n");
    return 0;
}
