#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "quadratic.h"

bool are_equal(double value1, double value2) 
{
        return (fabs(value1 - value2) < THRESHOLD);
}

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
               "  `--'   `--'                    \n");
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
                
option process_choice()
{
        char choice[CHOICE_LEN] = {};
        int  symbols_num = 0;

        printf("Please choose an option: ");

        scanf("%s%n", choice, &symbols_num);
        
        if (symbols_num > 1)
                return OPT_ERROR_WORD;
        
        switch (tolower(choice[0]))
                {
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

bool scan_coefs(quadra* equation)
{
        printf("Please enter coefficients: ");

        if (scanf("%lf %lf %lf", &equation->a_coef, &equation->b_coef, &equation->c_coef) != 3)
                return 1;
        else 
                return 0;
}

void solve_equation(quadra* equation)
{
        double discriminant_squared = 0;

        if (are_equal(equation->a_coef, 0)) 
        {
                if (are_equal(equation->b_coef, 0))
                {
                        if (are_equal(equation->c_coef,0))
                                equation->sol_num = INF_SOL;
                        else 
                                equation->sol_num = NO_SOL;
                }
                else 
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->sol_num = ONE_SOL;
                        }
                        else
                        {
                                equation->solution1 = - equation->c_coef/equation->b_coef;
                                equation->sol_num = ONE_SOL; 
                        }
                }
        }
        else 
        {
                if (are_equal(equation->b_coef,0))
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->sol_num = ONE_SOL;
                        }
                        else 
                        {
                                if (-equation->c_coef/equation->a_coef > 0)
                                {
                                        equation->solution1 =  sqrt(-equation->c_coef/equation->a_coef);
                                        equation->solution2 = -sqrt(-equation->c_coef/equation->a_coef);
                                        equation->sol_num = TWO_SOL;
                                }
                                else
                                {
                                        equation->sol_num = NO_SOL;
                                }
                        }
                }
                else
                {
                        if (are_equal(equation->c_coef,0))
                        {
                                equation->solution1 = 0;
                                equation->solution2 = -equation->b_coef/equation->a_coef;
                                equation->sol_num = TWO_SOL;
                        }
                        else
                        {
                                discriminant_squared =   equation->b_coef*equation->b_coef 
                                                     - 4*equation->a_coef*equation->c_coef;
                                if (discriminant_squared < 0)
                                {
                                      equation->sol_num = NO_SOL;
                                }
                                else
                                {
                                        equation->solution1 = (- equation->b_coef - sqrt(discriminant_squared)) / (2*equation->a_coef);
                                        equation->solution2 = (- equation->b_coef + sqrt(discriminant_squared)) / (2*equation->a_coef);
                                        if (are_equal(equation->solution1, equation->solution2))
                                        {
                                                equation->sol_num = ONE_SOL;
                                                equation->solution2 = 0;
                                        }
                                        else
                                        {
                                                equation->sol_num = TWO_SOL;
                                        }
                                }
                        }
                }
        }
}

void sort_solutions(quadra* equation)
{
        double temp = 0;

        if (equation->solution1 > equation->solution2)
        {
                               temp = equation->solution1;
                equation->solution1 = equation->solution2;
                equation->solution2 = temp;
        }
}

void print_solution(quadra* equation)
{
        printf("\nThe equation entered:\n"
               "%.2lf*x^2 %c %.2lf*x %c %.2lf = 0.\n",
                equation->a_coef,       
               (equation->b_coef > 0) ? '+' : '-', fabs(equation->b_coef), 
               (equation->c_coef > 0) ? '+' : '-', fabs(equation->c_coef));

        printf("Solutions:\n");

        if (equation->sol_num == NO_SOL)
        {
                printf("No solutions.\n");
        }
        else if (equation->sol_num == ONE_SOL)
        {
                printf("One solution: %lf.\n", equation->solution1);
        }
        else if (equation->sol_num == TWO_SOL)
        {
                sort_solutions(equation);
                printf("Two solutions: %lf; %lf.\n", equation->solution1, equation->solution2);
        }
        else
        {
                printf("Infinite number of solutions.\n");
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

void trim()
{
        while (getchar() != '\n')
                ;
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

