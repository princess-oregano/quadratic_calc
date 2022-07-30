#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;
        option opt = OPT_SOLVE;

        print_menu();
        while((opt = process_choice()) != OPT_QUIT)
        {
                switch (opt)
                {
                        case OPT_SOLVE:
                                if (!scan_coefs(&equation))
                                {
                                        solve_equation(&equation);
                                        print_solution(&equation);
                                }
                                else
                                {
                                        print_error(opt);
                                }
                                trim();
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
        }

        print_bye();

        return 0;
}

