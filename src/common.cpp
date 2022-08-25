#include "common.h"
#include <math.h>

bool are_equal(double value1, double value2)
{
        return (fabs(value1 - value2) < THRESHOLD);
}

void trim()
{
        while (getchar() != '\n')
                ;
}

void print_wcolor(FILE *stream, const char *color, const char *format, ...)
{
        va_list args;

        fprintf(stream, color);
        
        va_start(args, format);
        vfprintf(stream, format, args);
        va_end(args); 
        
        fprintf(stream, DEFAULT_COLOR);

}

