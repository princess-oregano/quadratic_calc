#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "common.h"
#include "calculations.h"

//! Structure with general information about solution of equation.
struct answer {
        double solution1                = 0; //!< First solution.
        double solution2                = 0; //!< Secons solution.
        num_of_solutions_t sol_num = NO_SOL; //!< Number of solutions.
};

/**
 * Prints number of solutions.
 *
 * @param [in] sol_num Number of solutions.
 */
static void print_num_of_sols(num_of_solutions_t sol_num)
{
        switch (sol_num) {
                case NO_SOL:
                        printf("0.\n");
                        break;
                case ONE_SOL:
                        printf("1.\n");
                        break;
                case TWO_SOL:
                        printf("2.\n");
                        break;
                case INF_SOL:
                        printf("Infinite.\n");
                        break;
                default:
                        printf("Error.\n");
        }
}

/**
 * Prints the result of comparison.
 *
 * @param [in] equation Pointer to a structure with general information about quadratic equation.
 * @param ans [in] Structure with general information about solution of equation.
 * @param status [in] Bool value, true if recieved and expected solutions are equal.
 */
static void test_msg(quadra_t* equation, answer* ans, bool status)
{
        assert(equation);
        assert(ans);

        if (status) {
                print_wcolor(stdout, GREEN, "OK\n");
                return;
        }

        print_wcolor(stdout, RED, "\nFAILURE\n");

        printf("In equation:\n"
               "%.*lf*x^2 %c %.*lf*x %c %.*lf = 0.\n", PRECISION,
                equation->a_coef,
               (equation->b_coef > 0) ? '+' : '-', PRECISION, fabs(equation->b_coef),
               (equation->c_coef > 0) ? '+' : '-', PRECISION, fabs(equation->c_coef));

        printf("Expected:\n");
        printf("x1 = %.*lf, x2 = %.*lf, number of solutions: ", PRECISION, ans->solution1,
                                                                PRECISION, ans->solution2);
        print_num_of_sols(ans->sol_num);

        printf("Recieved:\n");
        printf("x1 = %.*lf, x2 = %.*lf, number of solutions: ", PRECISION, equation->solution1,
                                                                PRECISION, equation->solution2);
        print_num_of_sols(ans->sol_num);

        printf("\n");
}

/**
 * Returns true if the expected values align with recieved.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 * @param ans Structure with general information about solution of equation.
 *
 * @return Bool value(1 if expected solution equals to recieved, else 0).
 */
static bool check(quadra_t* equation, answer* ans)
{
        assert(equation);
        assert(ans);

        return (are_equal(ans->solution1, equation->solution1) &&
                are_equal(ans->solution2, equation->solution2) &&
                ans->sol_num == equation->sol_num);
}

/**
 * Compares given solutions with the one that program outputs.
 *
 * @param [in] coef_a Coefficient at x^2.
 * @param [in] coef_b Coefficient at x^1.
 * @param [in] coef_c Coefficient at x^0.
 * @param [in] sol1 First solution.
 * @param [in] sol2 Second solution.
 * @param [in] number_sols Number of solutions.
 */
static void make_test(double coef_a, double coef_b, double coef_c,
                      double sol1, double sol2, num_of_solutions_t number_sols)
{
        quadra_t equation;
        answer ans;

        equation.a_coef = coef_a;
        equation.b_coef = coef_b;
        equation.c_coef = coef_c;

        ans.solution1 = sol1;
        ans.solution2 = sol2;
        ans.sol_num = number_sols;

        solve_equation(&equation);
        sort_solutions(&equation);
        test_msg(&equation, &ans, check(&equation, &ans));
}

int main()
{
        make_test(0, 0, 0, 0, 0, INF_SOL);
        make_test(0, 0, 2.5, 0, 0, NO_SOL);
        make_test(0, -3.65, 0, 0, 0, ONE_SOL);
        make_test(0, 5, -10, 0, 2, ONE_SOL);
        make_test(2, 0, -9, -2.1213203, 2.1213203, TWO_SOL);
        make_test(5.63, 2.96, 1.3, 0, 0, NO_SOL);
        make_test(1, 2, 1, -1, 0, ONE_SOL);

        return 0;
}

