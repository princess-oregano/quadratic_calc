#ifndef TESTS_H
#define TESTS_H

#include "common.h"
#include "calculations.h"

struct answer {
        double solution1              = 0;
        double solution2              = 0;
        num_of_solutions_t sol_num = NO_SOL;
};

//! Returns true if the expected values align with recieved.
bool check(quadra_t* equation, answer* ans);
//! Prints the result of comparison.
void test_msg(quadra_t* equation, answer* ans, bool status);
//! Compares given solutions with the one that program outputs.
void make_test(double coef_a, double coef_b, double coef_c,
               double sol1, double sol2, num_of_solutions_t number_sols);
//! Prints number of solutions.
void print_num_of_sols(num_of_solutions_t sol_num);

#endif // TESTS_H
