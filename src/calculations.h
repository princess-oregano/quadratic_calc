#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "common.h"

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
 * Solves equation with given coefficients.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 */
void solve_equation(quadra_t* equation);

/**
 * Sorts solutions in increasing order.
 *
 * @param equation Pointer to a structure with general information about quadratic equation.
 */
void sort_solutions(quadra_t* equation);

#endif // CALCULAIONS_H

