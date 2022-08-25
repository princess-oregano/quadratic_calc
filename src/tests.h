#ifndef TESTS_H
#define TESTS_H

#include "common.h"
#include "calculations.h"

//! Structure with general information about solution of equation.
struct answer {
        double solution1                = 0; //!< First solution.
        double solution2                = 0; //!< Secons solution.
        num_of_solutions_t sol_num = NO_SOL; //!< Number of solutions.
};

#endif // TESTS_H

