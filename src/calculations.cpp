#include "calculations.h"

//! Sorts solutions in increasing order.
static void sort_solutions(quadra_t* equation)
{
        assert(equation);

        double temp = 0;

        if (equation->solution1 > equation->solution2) {
                               temp = equation->solution1;
                equation->solution1 = equation->solution2;
                equation->solution2 = temp;
        }
}

void solve_equation(quadra_t* equation)
{
        assert(equation);

        double discriminant_squared = 0;

        if (are_equal(equation->a_coef, 0)) {
                if (are_equal(equation->b_coef, 0)) {
                        equation->sol_num = (are_equal(equation->c_coef, 0)) ? INF_SOL : NO_SOL;
                } else {
                                equation->solution1 = -equation->c_coef / equation->b_coef;
                                equation->sol_num = ONE_SOL;
                }
        } else {
                if (are_equal(equation->b_coef,0)) {
                        if (are_equal(equation->c_coef,0)) {
                                equation->solution1 = 0;
                                equation->sol_num = ONE_SOL;
                        } else {
                                if (-equation->c_coef / equation->a_coef > 0) {
                                        equation->solution1 =  sqrt(-equation->c_coef / equation->a_coef);
                                        equation->solution2 = -sqrt(-equation->c_coef / equation->a_coef);
                                        equation->sol_num = TWO_SOL;
                                } else {
                                        equation->sol_num = NO_SOL;
                                }
                        }
                } else {
                        if (are_equal(equation->c_coef,0)) {
                                equation->solution1 = 0;
                                equation->solution2 = -equation->b_coef / equation->a_coef;
                                equation->sol_num = TWO_SOL;
                        } else {
                                discriminant_squared =   equation->b_coef*equation->b_coef
                                                     - 4*equation->a_coef*equation->c_coef;
                                if (discriminant_squared < 0) {
                                      equation->sol_num = NO_SOL;
                                } else {
                                        equation->solution1 = (-equation->b_coef - sqrt(discriminant_squared)) / (2*equation->a_coef);
                                        equation->solution2 = (-equation->b_coef + sqrt(discriminant_squared)) / (2*equation->a_coef);

                                        if (are_equal(equation->solution1, equation->solution2)) {
                                                equation->sol_num = ONE_SOL;
                                                equation->solution2 = 0;
                                        } else {
                                                equation->sol_num = TWO_SOL;
                                        }
                                }
                        }
                }
        }

        sort_solutions(equation);
}

