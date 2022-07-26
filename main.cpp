#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;
        
        while(1)
        {
                menu();
                process_choice(&equation); 
        }

        return 0;
}

