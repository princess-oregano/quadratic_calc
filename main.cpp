#include <stdio.h>
#include <math.h>

int main()
{
        double a_coefficient = 0;
        double b_coefficient = 0;
        double c_coefficient = 0;
        double solution1 = 0;
        double solution2 = 0;
        double discriminant_squared = 0;

        scanf("%lf", &a_coefficient);
        scanf("%lf", &b_coefficient);
        scanf("%lf", &c_coefficient);

        if (a_coefficient == 0)
        {
                if (b_coefficient == 0)
                {
                        if (c_coefficient == 0)
                                printf("Infinite number of solutions.\n");
                        else 
                                printf("No solutions.\n");
                }
                else 
                {
                        if (c_coefficient == 0)
                        {
                                solution1 = 0;
                                printf("One solution: %.1lf\n", solution1);
                        }
                        else
                        {
                                solution1 = - b_coefficient/c_coefficient;
                                printf("One solution: %.1lf\n", solution1);
                        }
                }
        }
        else 
        {
                if (b_coefficient == 0)
                {
                        if (c_coefficient == 0)
                        {
                                solution1 = 0;
                                printf("One solution: %.1lf\n", solution1);
                        }
                        else 
                        {
                                if (-c_coefficient/b_coefficient > 0)
                                {
                                        solution1 = sqrt(-c_coefficient/b_coefficient);
                                        solution2 = -sqrt(-c_coefficient/b_coefficient);
                                        printf("Two solutions: %.1lf\n %.1lf\n", solution1, solution2);
                                }
                                else 
                                        printf("No real solutions.\n");
                        }
                }
                else
                {
                        if (c_coefficient == 0)
                        {
                                solution1 = 0;
                                solution2 = -b_coefficient/a_coefficient;
                                printf("Two solutions: %.1lf\n %.1lf\n", solution1, solution2);
                        }
                        else
                        {
                                discriminant_squared = b_coefficient*b_coefficient 
                                                       - 4*a_coefficient*c_coefficient;
                                if (discriminant_squared < 0)
                                        printf("No real solutions.\n");
                                else
                                {
                                        solution1 = (- b_coefficient - sqrt(discriminant_squared)) / (2*a_coefficient);
                                        solution2 = (- b_coefficient + sqrt(discriminant_squared)) / (2*a_coefficient);
                                        printf("Two solutions: %lf %lf\n", solution1, solution2);
                                }
                        }
                }
        }

        return 0;
}



































