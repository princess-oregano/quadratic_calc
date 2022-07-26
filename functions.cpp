#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "quadratic.h"

int are_equal(double value1, double value2) 
{
        if (fabs(value1 - value2) < EPSILON)
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
               "c) cats                     q) quit\n");
        printf("************************************************\n");
}

void get_help()
{
       printf("\nCommands:\n"
              "'s': asks for coefficients to solve equation\n"
              "'h': open manual\n"
              "'c': cats\n" 
              "'q': quits the program\n");
       printf("\nCoefficients entry:\n"
              "For equation like a*x^2 + b*x + c = 0, enter a b c.\n"
              "Example: for 5*x^2 + 10*x = 0 enter 5 10 0.\n");
}

void scan_choice(quadra* equation)
{
        char choice[41] = {};
        char ch = '0';
        int i = 0;

        while (!isspace(ch = getchar()) && (i < 40))
        {
                choice[i] = ch;
                i++;
        }
        choice[i] = '\0';
        
        if (i == 1)
        {
                switch (tolower(choice[0]))
                {
                        case 's':
                                printf("Enter coefficient:\n");
                                if (scanner(equation))
                                {
                                        while (getchar() != '\n')
                                                continue;
                                        
                                        solve(equation);
                                        print_solution(equation);
                                        
                                        break;
                                }
                                else 
                                {
                                        while (getchar() != '\n')
                                                continue;
                                        
                                        printf("Wrong input!\n");
                                        printf("Press 'h' if you need help\n");
                                        
                                        break;
                                }
                        case 'h': 
                                get_help();
                                break;
                        case 'q':
                                printf(
                                "              __..--''``---....___   _..._    __         \n"
                                "    /// //_.-'    .-/\";  `        ``<._  ``.''_ `. / // /\n"
                                "   ///_.-' _..--.'_    \\                    `( ) ) // //\n"
                                "   / (_..-' // (< _     ;_..__               ; `' / ///  \n"
                                "    / // // //  `-._,_)' // / ``--...____..-' /// / //   \n");
                                printf("Bye!\n");

                                exit(EXIT_SUCCESS);
                                break;
                        case 'c': 
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
                                break;
                        default:
                                printf("Wrong input!\n");
                                printf("Press 'h' if you need help\n");
                                break;
                }
        }
        else 
                printf("Wrong input!\n");

}

bool scanner(quadra* equation)
{
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
        printf("The equation entered:\n"
               "%.2lf*x^2 %c %.2lf*x %c %.2lf = 0.\n",
               equation->a_coef, (equation->b_coef > 0) ? '+' : '-',
               equation->b_coef, (equation->c_coef > 0) ? '+' : '-',
               equation->c_coef);

        printf("Solutions:\n");

        if (equation->sol_num == NO_SOL)
                printf("No solutions.\n");
        else if (equation->sol_num == ONE_SOL)
                printf("One solution: %lf.\n", equation->solution1);
        else if (equation->sol_num == TWO_SOL)
        {
                sort(equation);
                printf("Two solutions: %lf; %lf.\n", equation->solution1, equation->solution2);
        }
        else 
                printf("Infinite number of solutions.\n");
}

