#ifndef UI_H
#define UI_H

#include "common.h"
#include <stdio.h>
#include <math.h>

//! Prints solutions.
void print_solution  (const quadra_t* equation);
//! Prints menu.
void print_menu();
//! Prints short manual.
void print_help();
//! Prints a cat and 'bye' message.
void print_bye();
//! Prints a cat.
void print_easter_egg();
//! Prints a warning when an error occured.
void print_error(option_t opt);

#endif // UI_H
