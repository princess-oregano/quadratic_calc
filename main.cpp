#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;

        scanf("%lf", &equation.a_coef);
        scanf("%lf", &equation.b_coef);
        scanf("%lf", &equation.c_coef);

        solve(&equation);

        print_solution(&equation);

        return 0;
}

