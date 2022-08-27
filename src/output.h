#ifndef output_H
#define output_H

#include "common.h"

/**
 * Prints solutions.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 */
void print_solution  (const quadra_t* equation);

//! Prints menu.
void print_menu();
//! Prints short manual.
void print_help();
//! Prints a cat and 'bye' message.
void print_bye();
//! Prints easter_egg(cats).
void print_easter_egg();

/** Prints a warning when an error occured.
 *
 * @param opt Choosed option.
 */
void print_error(option_t opt);

#endif // output_H

