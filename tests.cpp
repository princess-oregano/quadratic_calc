#include <stdio.h>
#include <math.h>
#include "tests.h"

int main()
{
        quadra equation; 
        answer ans;

        make_test(0, 0, 0, 0, 0, INF_SOL, &equation, &ans);

        return 0;
}

void make_test(double coef_a, double coef_b, double coef_c, 
               double sol1, double sol2, num_of_solutions number_sols,
               quadra* equation, answer* ans)
{
        equation->a_coef = coef_a;
        equation->b_coef = coef_b; 
        equation->c_coef = coef_c;

        ans->solution1 = sol1;
        ans->solution2 = sol2;
        ans->sol_num = number_sols;

        solve_equation(equation);
        test_msg(equation, ans, check(equation, ans));
}

bool check(quadra* equation, answer* ans)
{
        return (are_equal(ans->solution1, equation->solution1) &&
                are_equal(ans->solution2, equation->solution2) &&
                ans->sol_num == equation->sol_num);
}

void test_msg(quadra* equation, answer* ans, bool status)
{
        if (status)
        {
                printf("OK\n");

                return;
        }

        printf("FAILURE");

        printf("Expected:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ", ans->solution1, ans->solution2);
        if (ans->sol_num == NO_SOL)
                printf("0.\n");
        else if (ans->sol_num == ONE_SOL)
                printf("1.\n");
        else if (ans->sol_num == TWO_SOL)
                printf("2.\n");
        else 
                printf("Infinite.\n");

        printf("Recieved:\n");
        printf("x1 = %lf, x2 = %lf, number of solutions: ", equation->solution1, equation->solution2);
        if (equation->sol_num == NO_SOL)
                printf("0.\n");
        else if (equation->sol_num == ONE_SOL)
                printf("1.\n");
        else if (equation->sol_num == TWO_SOL)
                printf("2.\n");
        else 
                printf("Infinite.\n");
}

