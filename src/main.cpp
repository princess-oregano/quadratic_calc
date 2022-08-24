#include <stdio.h>
#include <math.h>
#include "common.h"
#include "UI.h"
#include "input.h"
#include "calculations.h"

// Returns 1 if two values are equal.
bool are_equal(double value1, double value2);
// Trims '\n' simbol after using scanf.
void trim();

int main()
{
        quadra equation;
        option opt = OPT_SOLVE;

        print_menu();
        while((opt = process_choice()) != OPT_QUIT) {
                switch (opt) {
                        case OPT_SOLVE:
                                if (!scan_coefs(&equation)) {
                                        solve_equation(&equation);
                                        print_solution(&equation);
                                } else {
                                        print_error(opt);
                                }
                                break;
                        case OPT_HELP:
                                print_help();
                                break;
                        case OPT_EASTER_EGG:
                                print_easter_egg();
                                break;
                        case OPT_ERROR_CHAR:
                        case OPT_ERROR_WORD:
                                print_error(opt);
                                break;
                        case OPT_QUIT:
                        default:
                                break;
                }

                trim();
        }

        print_bye();

        return 0;
}

bool are_equal(double value1, double value2)
{
        return (fabs(value1 - value2) < THRESHOLD);
}

void trim()
{
        while (getchar() != '\n')
                ;
}

