#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include <stdio.h>
#include <ctype.h>

/**
 * Scans and processes input.
 *
 * @return Choosed option.
 */
option_t process_choice();

/**
 * Scans coefficients.
 *
 * @param [out] equation Pointer to a structure with general information about quadratic equation.
 *
 * @return Bool value(0 if scans coefficients successfully, else 1).
 */
bool scan_coefs(quadra_t* equation);

#endif // INPUT_H

