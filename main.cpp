#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;

        menu();
        while(1)
        {
                process_choice(&equation); 
        }

        return 0;
}

