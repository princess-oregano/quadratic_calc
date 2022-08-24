#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "common.h"
#include <math.h>

//! Solves equation with given coefficients.
void solve_equation  (quadra_t* equation);
//! Sorts solutions in increasing order.
void sort_solutions(quadra_t* equation);

#endif // CALCULAIONS_H

