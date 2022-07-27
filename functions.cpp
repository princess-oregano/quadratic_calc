#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "quadratic.h"

int are_equal(double value1, double value2) 
{
        if (fabs(value1 - value2) < THRESHOLD)
                return 1;
        else 
                return 0;
}

void menu()
{
        printf("************************************************\n");
        printf("███╗   ███╗███████╗███╗   ██╗██╗   ██╗\n"
               "████╗ ████║██╔════╝████╗  ██║██║   ██║\n"
               "██╔████╔██║█████╗  ██╔██╗ ██║██║   ██║\n"
               "██║╚██╔╝██║██╔══╝  ██║╚██╗██║██║   ██║\n"
               "██║ ╚═╝ ██║███████╗██║ ╚████║╚██████╔╝\n"
               "╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝ \n");
        printf("\n"
               "s) solve equation           h) help\n"
               "\n"
               "q) quit\n");
        printf("************************************************\n");
}

void print_help()
{
       printf("\nCommands:\n"
              "'s': asks for coefficients to solve equation\n"
              "'h': open manual\n"
              "'q': quits the program\n");
       printf("\nCoefficients entry:\n"
              "For equation like a*x^2 + b*x + c = 0, enter a b c.\n"
              "Example: for 5*x^2 + 10*x = 0 enter 5 10 0.\n\n");
}

option process_choice()
{
        char choice[ARRAY_SIZE] = {};
        int  ch = 0;
        int  letter = 0;

        printf("Please choose an option: ");

        while (((ch = getchar()) != '\n') && (letter < ARRAY_SIZE))
        {
                choice[letter] = ch;
                letter++;
        }
        choice[letter] = '\0';
        
        if (strlen(choice) == 1)
        {
                switch (tolower(choice[0]))
                {
                        case 's':
                                return SOLVE;
                                break;
                                /*
                                 *printf("Enter coefficient:\n");
                                 *if (scanner(equation))
                                 *{
                                 *        while (getchar() != '\n')
                                 *                ;
                                 *        
                                 *        solve(equation);
                                 *        print_solution(equation);
                                 *        
                                 *        break;
                                 *}
                                 *else 
                                 *{
                                 *        while (getchar() != '\n')
                                 *                ;
                                 *        
                                 *        printf("Wrong input!\n");
                                 *        printf("Press 'h' if you need help\n");
                                 *        
                                 *        break;
                                 *}
                                 */
                        case 'h':
                                return HELP;
                                break;
                                /*
                                 *print_help();
                                 *break;
                                 */
                        case 'q':
                                return QUIT;
                                break;
                                /*
                                 *print_bye();
                                 *exit(EXIT_SUCCESS);
                                 *break;
                                 */
                        case 'c':
                                return CATS;
                                break;
                                /*
                                 *easter_egg();
                                 *break;
                                 */
                        default:
                                return WRONG_INPUT;
                                break;
                                /*
                                 *printf("Wrong input!\n");
                                 *printf("Press 'h' if you need help.\n");
                                 *break;
                                 */
                }
        }
        else
        {
                return WORD;
        }

        choice[0] = '\0';

}

bool scanner(quadra* equation)
{
        printf("Please enter coefficients: ");

        if (scanf("%lf %lf %lf", &equation->a_coef, &equation->b_coef, &equation->c_coef) != 3)
                return 0;
        else return 1;
}

void solve(quadra* equation)
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
                                                equation->sol_num = ONE_SOL;
                                        else 
                                                equation->sol_num = TWO_SOL;
                                }
                        }
                }
        }
}

void sort(quadra* equation)
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
               equation->a_coef, (equation->b_coef > 0) ? '+' : '-',
               fabs(equation->b_coef), (equation->c_coef > 0) ? '+' : '-',
               fabs(equation->c_coef));

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
                sort(equation);
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

void easter_egg()
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

void print_error(option mode)
{
         fprintf(stderr, "\x1b[31mWrong input!\n\x1b[0m");

         if (mode == WRONG_INPUT)
                 fprintf(stderr, "\x1b[31mOnly options 's', 'h' and 'q' are allowed.\n\x1b[0m");
         else if (mode == WORD)
                 fprintf(stderr, "\x1b[31mOnly letters are allowed.\n\x1b[0m");
         else 
                 fprintf(stderr, "\x1b[31mCould not scan coefficients.\n\x1b[0m");

         printf("\x1b[31mPress 'h' for more details.\n\x1b[0m");
}

