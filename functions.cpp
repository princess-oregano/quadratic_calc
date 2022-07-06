#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int compare(double value1, double value2)
{
        if (value1 - value2 < EPSILON)
                return 0;
        else 
                return 1;
}

void scanner(struct quadra equation)
{
       
}

void solve(struct quadra equation)
{
        if (equation.a_coef == 0)
        {
                if (equation.b_coef == 0)
                {
                        if (equation.c_coef == 0)
                                printf("Infinite number of solutions.\n");
                        else 
                                printf("No solutions.\n");
                }
                else 
                {
                        if (equation.c_coef == 0)
                        {
                                equation.solution1 = equation.solution2 = 0;
                        }
                        else
                        {
                                equation.solution1 = equation.solution2 = - equation.b_coef/equation.c_coef;
                        }
                }
        }
        else 
        {
                if (equation.b_coef == 0)
                {
                        if (equation.c_coef == 0)
                        {
                                equation.solution1 = equation.solution2 = 0;
                        }
                        else 
                        {
                                if (-equation.c_coef/equation.a_coef > 0)
                                {
                                        equation.solution1 = sqrt(-equation.c_coef/equation.a_coef);
                                        equation.solution2 = -sqrt(-equation.c_coef/equation.a_coef);
                                }
                                else
                                {
                                        printf("No real solutions.\n");
                                }
                        }
                }
                else
                {
                        if (equation.c_coef == 0)
                        {
                                equation.solution1 = 0;
                                equation.solution2 = -equation.b_coef/equation.a_coef;
                        }
                        else
                        {
                                equation.discriminant_squared = equation.b_coef*equation.b_coef 
                                                       - 4*equation.a_coef*equation.c_coef;
                                if (equation.discriminant_squared < 0)
                                {
                                        printf("No real solutions.\n");
                                }
                                else
                                {
                                        equation.solution1 = (- equation.b_coef - sqrt(equation.discriminant_squared)) / (2*equation.a_coef);
                                        equation.solution2 = (- equation.b_coef + sqrt(equation.discriminant_squared)) / (2*equation.a_coef);
                                }
                        }
                }
        }
}

void print_solution(struct quadra equation)
{
        if (equation.solution1 == equation.solution2)
                printf("One solution: %lf.\n", equation.solution1);
        else 
                printf("Two solutions: %lf; %lf.\n", equation.solution1, equation.solution2);
}
