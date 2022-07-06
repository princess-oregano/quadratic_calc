#include <stdio.h>
#include <math.h>
#include "quadratic.h"

static num_of_answers answer = no_ans;

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
        if (are_equal(equation->a_coef, 0))
        {
                if (are_equal(equation->b_coef, 0))
                {
                        if (are_equal(equation->c_coef,0))
                                answer = inf;
                        else 
                                answer = no_ans;
                }
                else 
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                answer = one;
                        }
                        else
                        {
                                equation->solution1 = - equation->c_coef/equation->b_coef;
                                answer = one;
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
                                answer = one;
                        }
                        else 
                        {
                                if (-equation->c_coef/equation->a_coef > 0)
                                {
                                        equation->solution1 = sqrt(-equation->c_coef/equation->a_coef);
                                        equation->solution2 = -sqrt(-equation->c_coef/equation->a_coef);
                                        answer = two;
                                }
                                else
                                {
                                        answer = no_ans;
                                }
                        }
                }
                else
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->solution2 = -equation->b_coef/equation->a_coef;
                                answer = two;
                        }
                        else
                        {
                                equation->discriminant_squared = equation->b_coef*equation->b_coef 
                                                       - 4*equation->a_coef*equation->c_coef;
                                if (equation->discriminant_squared < 0)
                                {
                                      answer = no_ans;
                                }
                                else
                                {
                                        equation->solution1 = (- equation->b_coef - sqrt(equation->discriminant_squared)) / (2*equation->a_coef);
                                        equation->solution2 = (- equation->b_coef + sqrt(equation->discriminant_squared)) / (2*equation->a_coef);
                                        if (are_equal(equation->solution1, equation->solution2))
                                                answer = one;
                                        else 
                                                answer = two;
                                }
                        }
                }
        }
}

void print_solution(struct quadra* equation)
{
        if (answer == no_ans)
                printf("No answer.\n");
        else if (answer == one)
                printf("One solution: %lf.\n", equation->solution1);
        else if (answer == two)
                printf("Two solutions: %lf; %lf.\n", equation->solution1, equation->solution2);
        else 
                printf("Infinite number of solutions.\n");
}

