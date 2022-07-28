#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;
        option mode = OPT_SOLVE;

        print_menu();
        while((mode = process_choice()) != OPT_QUIT)
        {
                switch (mode)
                {
                        case OPT_SOLVE:
                                if (!scan_coefs(&equation))
                                {
                                        solve_equation(&equation);
                                        print_solution(&equation);
                                }
                                else
                                {
                                        print_error(mode);
                                }
                                trim();
                                break;
                        case OPT_HELP:
                                print_help();
                                break;
                        case OPT_EASTER_EGG:
                                easter_egg();
                                break;
                        case OPT_ERROR_CHAR:
                        case OPT_ERROR_WORD:
                                print_error(mode);
                                break;
                        case OPT_QUIT:
                        default:
                                break;
                }
        }

        print_bye();

        return 0;
}

