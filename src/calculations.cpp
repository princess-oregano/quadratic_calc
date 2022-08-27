#include <assert.h>
#include <math.h>
#include "calculations.h"

bool are_equal(double value1, double value2)
{
        return (fabs(value1 - value2) < THRESHOLD);
}

void sort_solutions(quadra_t* equation)
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

        double discriminant = 0;

        if (are_equal(equation->a_coef, 0)) {
                if (are_equal(equation->b_coef, 0)) {
                        equation->sol_num = (are_equal(equation->c_coef, 0)) ? INF_SOL : NO_SOL;
                } else {
                        equation->solution1 = -equation->c_coef / equation->b_coef;
                        equation->sol_num = ONE_SOL;
                }

                return;
        }

        // If a != 0.
        if (are_equal(equation->b_coef, 0)) {
                if (are_equal(equation->c_coef, 0)) {
                        equation->solution1 = 0;
                        equation->sol_num = ONE_SOL;

                        return;
                }

                // If c != 0.
                if (-equation->c_coef / equation->a_coef > 0) {
                        equation->solution1 =  sqrt(-equation->c_coef / equation->a_coef);
                        equation->solution2 = -sqrt(-equation->c_coef / equation->a_coef);
                        equation->sol_num = TWO_SOL;
                } else {
                        equation->sol_num = NO_SOL;
                }

                return;
        }

        // If a, b != 0.
        if (are_equal(equation->c_coef,0)) {
                equation->solution1 = 0;
                equation->solution2 = -equation->b_coef / equation->a_coef;
                equation->sol_num = TWO_SOL;

                return;
        }

        // If a, b, c != 0.
        discriminant =     equation->b_coef * equation->b_coef
                     - 4 * equation->a_coef * equation->c_coef;
        if (discriminant < 0) {
                equation->sol_num = NO_SOL;
        } else {
                equation->solution1 = (-equation->b_coef - sqrt(discriminant)) / (2 * equation->a_coef);
                equation->solution2 = (-equation->b_coef + sqrt(discriminant)) / (2 * equation->a_coef);

                if (are_equal(equation->solution1, equation->solution2)) {
                        equation->sol_num = ONE_SOL;
                        equation->solution2 = 0;
                } else {
                        equation->sol_num = TWO_SOL;
                }
        }
}

