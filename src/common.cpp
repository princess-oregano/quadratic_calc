#include <stdarg.h>
#include <math.h>
#include "common.h"

void print_wcolor(FILE *stream, const char *color, const char *format, ...)
{
        va_list args {};

        fprintf(stream, "%s", color);

        va_start(args, format);
        vfprintf(stream, format, args);
        va_end(args);

        fprintf(stream, "%s", DEFAULT_COLOR);
}

