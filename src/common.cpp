#include "common.h"
#include <math.h>
#include <stdio.h>

bool are_equal(double value1, double value2)
{
        return (fabs(value1 - value2) < THRESHOLD);
}

void trim()
{
        while (getchar() != '\n')
                ;
}

