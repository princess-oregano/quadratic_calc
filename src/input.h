#ifndef INPUT_H
#define INPUT_H

#include "common.h"
#include <stdio.h>
#include <ctype.h>

//! Scans and processes input.
option_t process_choice();
//! Returns 0 if scans coefficients successfully, else 1.
bool scan_coefs(quadra_t* equation);

#endif // INPUT_H

