#include "input.h"

option_t process_choice()
{
        char choice[CHOICE_LEN] = {};
        int  symbols_num = 0;

        printf("Please choose an option: ");
        scanf("%2s%n", choice, &symbols_num);

        if (symbols_num > 1)
                return OPT_ERROR_WORD;

        switch (tolower(choice[0])) {
                        case 's':
                                return OPT_SOLVE;
                        case 'h':
                                return OPT_HELP;
                        case 'q':
                                return OPT_QUIT;
                        case 'c':
                                return OPT_EASTER_EGG;
                        default:
                                return OPT_ERROR_CHAR;
                }
}

bool scan_coefs(quadra_t* equation)
{
        assert(equation);

        printf("Please enter coefficients: ");

        if (scanf("%lf %lf %lf", &equation->a_coef, &equation->b_coef, &equation->c_coef) != 3)
                return 1;
        else
                return 0;
}

