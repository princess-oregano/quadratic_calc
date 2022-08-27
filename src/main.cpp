#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "common.h"
#include "output.h"
#include "input.h"
#include "calculations.h"

int main()
{
        quadra_t equation {};
        option_t opt = OPT_SOLVE;
        bool quit = false;

        print_menu();

        while(!quit) {
                opt = process_choice();
                
                switch (opt) {
                        case OPT_SOLVE:
                                printf("Please enter coefficients: ");
                                switch (scan_coefs(&equation)) {
                                        case SCAN_SUCCESS:
                                                solve_equation(&equation);
                                                sort_solutions(&equation);
                                                print_solution(&equation);
                                                break;
                                        case SCAN_ERROR:
                                                print_wcolor(stderr, RED, "Could not scan coefficients.\n");
                                                break;
                                        case SCAN_EOF:
                                                print_wcolor(stderr, RED, "\nEOF encountered.\n");
                                                quit = true;
                                                break;
                                        default:
                                                print_wcolor(stderr, RED, "Invalid scanning status.\n");
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
                                quit = true;
                                break;
                        default:
                                print_wcolor(stderr, RED, "Invalid option.\n");
                                assert(0);
                }
        }

        print_bye();

        return 0;
}

