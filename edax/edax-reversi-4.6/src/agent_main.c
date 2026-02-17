#include "agent.h"
#include "move.h"

int main(void) {
    char* board_str = ""; // TODO: Add a sample board
    int depth = 13;
    Agent* agent = agent_create(board_str, depth);
    Move* move = agent_get_best_move(agent);
    agent_destroy(&agent);
    return 0;
}
