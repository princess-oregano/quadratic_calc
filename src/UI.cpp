#include "UI.h"

void print_menu()
{
        printf("************************************************\n");
        printf("                         ,       \n"
               "  ,-.       _,---._ __  / \\     \n"
               " /  )    .-'       `./ /   \\    \n"
               "(  (   ,'            `/    /|    \n"
               " \\  `-\"             \\'\\   / |\n"
               "  `.              ,  \\ \\ /  |  \n"
               "   /`.          ,'-`----Y   |    \n"
               "  (            ;        |   '    \n"
               "  |  ,-.    ,-'         |  /     \n"
               "  |  | (   |            | /      \n"
               "  )  |  \\  `.___________|/      \n"
               "  `--'   `--'                    \n"
               "      quadratic_calc by tyvia    \n");
        printf("\n"
               "s - solve equation\n"
               "h - help\n"
               "q - quit\n");
        printf("************************************************\n");
}

void print_help()
{
        printf("\nCommands:\n"
               "'s': ask for coefficients to solve equation\n"
               "'h': open manual\n"
               "'q': quit the program\n");
        printf("\nCoefficients entry:\n"
               "For equation like a*x^2 + b*x + c = 0, enter a b c.\n"
               "Example: for 5*x^2 + 10*x = 0 enter 5 10 0.\n\n");
}

void print_solution(const quadra* equation)
{
        assert(equation);

        printf("\nThe equation entered:\n"
               "%.2lf*x^2 %c %.2lf*x %c %.2lf = 0.\n",
                equation->a_coef,
               (equation->b_coef > 0) ? '+' : '-', fabs(equation->b_coef),
               (equation->c_coef > 0) ? '+' : '-', fabs(equation->c_coef));

        printf("Solutions:\n");

        if (equation->sol_num == NO_SOL)
                printf("No solutions.\n");
        else if (equation->sol_num == ONE_SOL)
                printf("One solution: %lf.\n", equation->solution1);
        else if (equation->sol_num == TWO_SOL)
                printf("Two solutions: %lf; %lf.\n", equation->solution1, equation->solution2);
        else
                printf("Infinite number of solutions.\n");

        printf("\n");
}

void print_bye()
{
        printf(
        "              __..--''``---....___   _..._    __         \n"
        "    /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // /\n"
        "   ///_.-' _..--.'_    \\                    `( ) ) // //\n"
        "   / (_..-' // (< _     ;_..__               ; `' / ///  \n"
        "    / // // //  `-._,_)' // / ``--...____..-' /// / //   \n");
        printf("                    Bye!\n");
}

void print_easter_egg()
{
        printf(
                "             *     ,MMM8&&&.            *              \n"
                "                  MMMM88&&&&&    .                     \n"
                "                 MMMM88&&&&&&&                         \n"
                "     *           MMM88&&&&&&&&                         \n"
                "                 MMM88&&&&&&&&                         \n"
                "                 'MMM88&&&&&&'                         \n"
                "                   'MMM8&&&'      *                    \n"
                "          |\\___/|     /\\___/\\                       \n"
                "          )     (     )    ~( .                        \n"
                "         =\\     /=   =\\~    /=                       \n"
                "           )===(       ) ~ (                           \n"
                "          /     \\     /     \\                        \n"
                "          |     |     ) ~   (                          \n"
                "         /       \\   /     ~ \\                       \n"
                "         \\       /   \\~     ~/                       \n"
                "  _/\\_/\\_/\\__  _/_/\\_/\\__~__/_/\\_/\\_/\\_/\\_/\\_\n"
                "  |  |  |  |( (  |  |  | ))  |  |  |  |  |  |          \n"
                "  |  |  |  | ) ) |  |  |//|  |  |  |  |  |  |          \n"
                "  |  |  |  |(_(  |  |  (( |  |  |  |  |  |  |          \n"
                "  |  |  |  |  |  |  |  |\\)|  |  |  |  |  |  |         \n"
                "  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |          \n");
}

void print_error(option opt)
{
        fprintf(stderr, "\x1b[31mWrong input!\n\x1b[0m");

        if (opt == OPT_ERROR_CHAR)
                fprintf(stderr, "\x1b[31mOnly options 's', 'h' and 'q' are allowed.\n\x1b[0m");
        else if (opt == OPT_ERROR_WORD)
                fprintf(stderr, "\x1b[31mOnly letters are allowed.\n\x1b[0m");
        else
                fprintf(stderr, "\x1b[31mCould not scan coefficients.\n\x1b[0m");

        printf("\x1b[31mPress 'h' for more details.\n\x1b[0m");
}

