const double THRESHOLD = 0.000001;
const int CHOICE_LEN = 40;

enum option
{
        OPT_SOLVE      = 0,
        OPT_HELP       = 1,
        OPT_EASTER_EGG = 2,
        OPT_QUIT       = 3,
        OPT_ERROR_CHAR = 4,
        OPT_ERROR_WORD = 5,
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
        double a_coef                 = 0;
        double b_coef                 = 0;
        double c_coef                 = 0;
        num_of_solutions sol_num = NO_SOL;
        double solution1              = 0;
        double solution2              = 0;
};

// Returns 1 if two values are equal.
bool are_equal(double value1, double value2); 
// Returns 0 if scans coefficients successfully, else 1.
bool scan_coefs      (quadra* equation);         
// Solves equation with given coefficients.
void solve_equation  (quadra* equation);           
// Sorts solutions in increasing order.
void sort_solutions  (quadra* equation);
// Prints solutions.
void print_solution  (const quadra* equation);           
// Scans and processes input.
option process_choice();            
// Prints menu.
void print_menu();                                     
// Prints short manual.
void print_help();                                 
// Prints a cat and 'bye' message.
void print_bye();
// Prints a cat.
void print_easter_egg();
// Trims '\n' simbol after using scanf.
void trim();
// Prints a warning when an error occured.
void print_error(option opt);

