#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;

        while(1)
        {
                menu();
                scan_choice(&equation); 
        }

        return 0;
}

