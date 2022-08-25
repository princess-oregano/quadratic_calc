#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "common.h"
#include <math.h>

/**
 * Solves equation with given coefficients.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 */
void solve_equation  (quadra_t* equation);

/**
 * Sorts solutions in increasing order.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 */
void sort_solutions(quadra_t* equation);

#endif // CALCULAIONS_H

