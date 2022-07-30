#include <stdio.h>
#include <math.h>
#include "tests.h"

int main()
{
        quadra equation; 
        answer ans;

        equation.a_coef = 0;
        equation.b_coef = 0; 
        equation.c_coef = 0;

        ans.solution1 = 0;
        ans.solution2 = 0;
        ans.sol_num = INF_SOL;

        solve_equation(&equation);
        test_msg(&equation, &ans, check(&equation, &ans));

        return 0;
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
                printf("Okay.\n");
        }
        else
        {
                printf("Failure!");
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
}

