#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int are_equal(double value1, double value2) 
{
        if (fabs(value1 - value2) < EPSILON)
                return 1;
        else 
                return 0;
}

void scanner(struct quadra* equation)
{
       
}

void solve(struct quadra* equation)
{
        double discriminant_squared = 0;

        if (are_equal(equation->a_coef, 0)) 
        {
                if (are_equal(equation->b_coef, 0))
                {
                        if (are_equal(equation->c_coef,0))
                                equation->sol_num = inf_sol;
                        else 
                                equation->sol_num = no_sol;
                }
                else 
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->sol_num = one_sol;
                        }
                        else
                        {
                                equation->solution1 = - equation->c_coef/equation->b_coef;
                                equation->sol_num = one_sol; 
                        }
                }
        }
        else 
        {
                if (are_equal(equation->b_coef,0))
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->sol_num = one_sol;
                        }
                        else 
                        {
                                if (-equation->c_coef/equation->a_coef > 0)
                                {
                                        equation->solution1 =  sqrt(-equation->c_coef/equation->a_coef);
                                        equation->solution2 = -sqrt(-equation->c_coef/equation->a_coef);
                                        equation->sol_num = two_sol;
                                }
                                else
                                {
                                        equation->sol_num = no_sol;
                                }
                        }
                }
                else
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->solution2 = -equation->b_coef/equation->a_coef;
                                equation->sol_num = two_sol;
                        }
                        else
                        {
                                discriminant_squared =   equation->b_coef*equation->b_coef 
                                                               - 4*equation->a_coef*equation->c_coef;
                                if (discriminant_squared < 0)
                                {
                                      equation->sol_num = no_sol;
                                }
                                else
                                {
                                        equation->solution1 = (- equation->b_coef - sqrt(discriminant_squared)) / (2*equation->a_coef);
                                        equation->solution2 = (- equation->b_coef + sqrt(discriminant_squared)) / (2*equation->a_coef);
                                        if (are_equal(equation->solution1, equation->solution2))
                                                equation->sol_num = one_sol;
                                        else 
                                                equation->sol_num = two_sol;
                                }
                        }
                }
        }
}

void print_solution(struct quadra* equation)
{
        if (equation->sol_num == no_sol)
                printf("No answer.\n");
        else if (equation->sol_num == one_sol)
                printf("One solution: %lf.\n", equation->solution1);
        else if (equation->sol_num == two_sol)
                printf("Two solutions: %lf; %lf.\n", equation->solution1, equation->solution2);
        else 
                printf("Infinite number of solutions.\n");
}

