#ifndef COMMON_H
#define COMMON_H

#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

//! Accuracy of calculations.
const double THRESHOLD = 0.000001;
//! Length of string with entered choice.
const int CHOICE_LEN = 3;

//! Color constants for print_wcolor function().
const char DEFAULT_COLOR[] = "\x1b[0m";
const char RED[]           = "\x1B[31m";
const char GREEN[]         = "\x1b[32m";
const char MAGENTA[]       = "\x1b[95m";
const char CYAN[]          = "\x1B[36m";
const char WHITE[]         = "\x1b[37m";

//! Enum with a list of options.
enum option_t {
        OPT_SOLVE       = 0, //!< Solve equation.
        OPT_HELP        = 1, //!< Print help message.
        OPT_EASTER_EGG  = 2, //!< Print easter egg.
        OPT_QUIT        = 3, //!< Quit the program.
        OPT_ERROR_CHAR  = 4, //!< Wrong letter input.
        OPT_ERROR_WORD  = 5, //!< Word input.
};

//! Enum with a list of possible number of roots.
enum num_of_solutions_t {
         NO_SOL =   0, //!< No roots.
        ONE_SOL =   1, //!< One root.
        TWO_SOL =   2, //!< Two roots.
        INF_SOL = 777, //!< Infinite number of roots.
};

//! Structure with general information about equation.
struct quadra_t {
        double a_coef                   = 0; //!< First coefficient of the equation.
        double b_coef                   = 0; //!< Second coefficient of the equation.
        double c_coef                   = 0; //!< Third coefficient of the equation.
        num_of_solutions_t sol_num = NO_SOL; //!< Number of solutions.
        double solution1                = 0; //!< First solution of the equation.
        double solution2                = 0; //!< Second solution of the equation.
};

/**
 * Compares two double values.
 *
 * @param [in] value1 First value.
 * @param [in] value2 Second value.
 *
 * @return 1 if values are equal.
 */
bool are_equal(double value1, double value2);

/**
 * Trims '\n' simbol after using scanf.
 */
void trim();

/** Prints text in specific color.
 *
 * @param [in] stream Pointer to output stream.
 * @param [in] color ANSI color code.
 * @param [in] format Pointer to format string.
 * @param [in] ... arguments specifying data to print.
 */
void print_wcolor(FILE *stream, const char *color, const char* format, ...);

#endif // COMMON_H

