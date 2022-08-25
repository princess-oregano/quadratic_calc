#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

const double THRESHOLD = 0.000001;
const int CHOICE_LEN = 3;

const char DEFAULT_COLOR[] = "\x1b[0m";
const char RED[]           = "\x1B[31m";
const char GREEN[]         = "\x1b[32m";
const char MAGENTA[]       = "\x1b[95m";
const char CYAN[]          = "\x1B[36m";
const char WHITE[]         = "\x1b[37m";

enum option_t {
        OPT_SOLVE       = 0,
        OPT_HELP        = 1,
        OPT_EASTER_EGG  = 2,
        OPT_QUIT        = 3,
        OPT_ERROR_CHAR  = 4,
        OPT_ERROR_WORD  = 5,
};

enum num_of_solutions_t {
         NO_SOL =   0,
        ONE_SOL =   1,
        TWO_SOL =   2,
        INF_SOL = 777,
};

//! Contains information about equation.
struct quadra_t {
        double a_coef                   = 0; //!< First coefficient of the equation.
        double b_coef                   = 0; //!< Second coefficient of the equation.
        double c_coef                   = 0; //!< Third coefficient of the equation.
        num_of_solutions_t sol_num = NO_SOL; //!< Number of solutions.
        double solution1                = 0; //!< First solution of the equation.
        double solution2                = 0; //!< Second solution of the equation.
};

//! Compares two double values.
//! @return 1 if values are equal.
bool are_equal(double value1, double value2);
//! Trims '\n' simbol after using scanf.
void trim();
//! Prints text in specific color.
void print_wcolor(FILE *stream, const char *color, const char* format, ...);

#endif // COMMON_H

