#include "quadratic.h"

struct answer {
        double solution1              = 0;
        double solution2              = 0;
        num_of_solutions sol_num = NO_SOL;
};

bool check(quadra* equation, answer* ans); 
void test_msg(quadra* equation, answer* ans, bool status);

