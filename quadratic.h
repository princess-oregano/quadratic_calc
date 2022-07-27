const double THRESHOLD = 0.000001;
const int ARRAY_SIZE = 40;

enum option
{
        SOLVE       = 0,
        HELP        = 1,
        CATS        = 2,
        QUIT        = 3,
        WRONG_INPUT = 4,
        WORD        = 5,
};

enum num_of_solutions 
{
         NO_SOL =   0, 
        ONE_SOL =   1, 
        TWO_SOL =   2, 
        INF_SOL = 777,
};

struct quadra 
{
        double a_coef                   = 0;
        double b_coef                   = 0;
        double c_coef                   = 0;
        num_of_solutions sol_num   = NO_SOL;
        double solution1                = 0;
        double solution2                = 0;
};
//returns 1 if two values are equal
int  are_equal(double value1, double value2);    
 //returns 1 if scans coefficients successfully, else 0
bool scanner         (quadra* equation);         
//solves equation with given coefficients
void solve           (quadra* equation);           
//prints solutions
void print_solution  (quadra* equation);           
//sorts solutions in increasing order
void sort            (quadra* equation);           
//scans and processes input
option process_choice();            
//prints menu
void menu();                                     
//prints short manual
void print_help();                                 
//prints a cat and 'bye' message
void print_bye();
//prints a cat
void easter_egg();
//trims '\n' sumbol after using scanf
void trim();
//prints a warning when an error occured
void print_error(option mode);

