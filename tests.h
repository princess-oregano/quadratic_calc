#include "quadratic.h"

struct answer {
        double solution1              = 0;
        double solution2              = 0;
        num_of_solutions sol_num = NO_SOL;
};

// Returns true if the expected values align with recieved.
bool check(quadra* equation, answer* ans); 
// Prints the result of comparison.
void test_msg(quadra* equation, answer* ans, bool status);
// Compares given solutions with the one that program outputs.
void make_test(double coef_a, double coef_b, double coef_c, 
               double sol1, double sol2, num_of_solutions number_sols);

