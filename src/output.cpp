#include "output.h"

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
        print_wcolor(stdout, MAGENTA,
               "\nCommands:\n"
               "'s': ask for coefficients to solve equation\n"
               "'h': open manual\n"
               "'q': quit the program\n\n"

               "Coefficients entry:\n"
               "For equation like a*x^2 + b*x + c = 0, enter a b c.\n"
               "Example: for 5*x^2 + 10*x = 0 enter 5 10 0.\n\n");
}

void print_solution(const quadra_t* equation)
{
        assert(equation);

        printf("\nThe equation entered:\n"
               "%.6lf*x^2 %c %.6lf*x %c %.6lf = 0.\n",
                equation->a_coef,
               (equation->b_coef > 0) ? '+' : '-', fabs(equation->b_coef),
               (equation->c_coef > 0) ? '+' : '-', fabs(equation->c_coef));

        printf("Solutions:\n");

        switch (equation->sol_num) {
                case NO_SOL:
                        printf("No solutions.\n");
                        break;
                case ONE_SOL:
                        printf("One solution: %.6lf.\n", equation->solution1);
                        break;
                case TWO_SOL:
                        printf("Two solutions: %.6lf; %.6lf.\n", equation->solution1, equation->solution2);
                        break;
                case INF_SOL:
                        printf("Infinite number of solutions.\n");
                        break;
                default:
                        fprintf(stderr, "Error: invalid number of solutions.\n");
                        assert(0);
        }

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

void print_error(option_t opt)
{
        print_wcolor(stderr, RED, "Wrong input!\n");

        switch (opt) {
                case OPT_ERROR_CHAR:
                        print_wcolor(stderr, RED, "Only options 's', 'h' and 'q' are allowed.\n");
                        break;
                case OPT_ERROR_WORD:
                        print_wcolor(stderr, RED, "Only letters are allowed.\n");
                        break;
                case OPT_SOLVE:
                case OPT_HELP:
                case OPT_EASTER_EGG:
                case OPT_QUIT:
                default:
                        print_wcolor(stderr, RED, "Invalid option.\n");
                        assert(0);
        }

        print_wcolor(stderr, RED, "Press 'h' for more details.\n");
}

