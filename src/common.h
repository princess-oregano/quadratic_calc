#ifndef COMMON_H
#define COMMON_H

#include <assert.h>

const double THRESHOLD = 0.000001;
const int CHOICE_LEN = 40;

enum option {
        OPT_SOLVE      = 0,
        OPT_HELP       = 1,
        OPT_EASTER_EGG = 2,
        OPT_QUIT       = 3,
        OPT_ERROR_CHAR = 4,
        OPT_ERROR_WORD = 5,
};

enum num_of_solutions {
         NO_SOL =   0,
        ONE_SOL =   1,
        TWO_SOL =   2,
        INF_SOL = 777,
};

struct quadra {
        double a_coef                 = 0;
        double b_coef                 = 0;
        double c_coef                 = 0;
        num_of_solutions sol_num = NO_SOL;
        double solution1              = 0;
        double solution2              = 0;
};

#endif // COMMON_H

