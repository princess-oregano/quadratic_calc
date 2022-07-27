#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{
        quadra equation;
        option mode = SOLVE;

        menu();
        while((mode = process_choice()) != QUIT)
        {
                switch (mode)
                {
                        case SOLVE:
                                if (scanner(&equation))
                                {
                                        solve(&equation);
                                        print_solution(&equation);
                                }
                                else
                                {
                                        print_error(mode);
                                }
                                trim();
                                break;
                        case HELP:
                                print_help();
                                break;
                        case CATS:
                                easter_egg();
                                break;
                        case WRONG_INPUT:
                        case WORD:
                                print_error(mode);
                                break;
                        case QUIT:
                        default:
                                break;
                }
        }

        print_bye();

        return 0;
}

