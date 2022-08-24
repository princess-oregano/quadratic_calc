#include <stdio.h>
#include <math.h>
#include "tests.h"

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

void make_test(double coef_a, double coef_b, double coef_c,
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
        test_msg(&equation, &ans, check(&equation, &ans));
}

bool check(quadra_t* equation, answer* ans)
{
        assert(equation);
        assert(ans);

        return (are_equal(ans->solution1, equation->solution1) &&
                are_equal(ans->solution2, equation->solution2) &&
                ans->sol_num == equation->sol_num);
}

void test_msg(quadra_t* equation, answer* ans, bool status)
{
        assert(equation);
        assert(ans);

        if (status) {
                printf("\x1b[32mOK\n\x1b[0m");
                return;
        }

        printf("\n\n\x1b[31mFAILURE\x1b[0m\n");

        printf("Expected:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ",
                ans->solution1, ans->solution2);
        print_num_of_sols(ans->sol_num);

        printf("Recieved:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ",
                equation->solution1, equation->solution2);
        print_num_of_sols(ans->sol_num);

        printf("\n");
}

void print_num_of_sols(num_of_solutions_t sol_num)
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

