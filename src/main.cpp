#include <stdio.h>
#include <math.h>
#include "common.h"
#include "output.h"
#include "input.h"
#include "calculations.h"

int main()
{
        quadra_t equation;
        option_t opt = OPT_SOLVE;

        print_menu();
        while((opt = process_choice()) != OPT_QUIT) {
                switch (opt) {
                        case OPT_SOLVE:
                                if (!scan_coefs(&equation)) {
                                        solve_equation(&equation);
                                        sort_solutions(&equation);
                                        print_solution(&equation);
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
                                break;
                        default:
                                print_wcolor(stderr, RED, "Invalid option.\n");
                                assert(0);
                }

                trim();
        }

        print_bye();

        return 0;
}

