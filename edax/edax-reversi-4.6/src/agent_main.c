#include "agent.h"
#include "move.h"

int main(void) {
    const char* board_str = "(;GM[10]FF[4]SZ[8]GN[Example Game]PB[Black]PW[White];B[f5];W[d6];B[c4];W[e3];B[f4];W[c5];B[c6];W[d3])";
    int depth = 13;
    Agent* agent = agent_create(board_str, depth);
    Move* move = agent_get_best_move(agent);
    agent_destroy(&agent);
    return 0;
}
