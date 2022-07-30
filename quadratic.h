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

//returns 0 if scans coefficients successfully, else 1
bool scan_coefs      (quadra* equation);         
//solves equation with given coefficients
void solve_equation  (quadra* equation);           
//prints solutions
void print_solution  (quadra* equation);           
//scans and processes input
option process_choice();            
//prints menu
void print_menu();                                     
//prints short manual
void print_help();                                 
//prints a cat and 'bye' message
void print_bye();
//prints a cat
void print_easter_egg();
//trims '\n' sumbol after using scanf
void trim();
//prints a warning when an error occured
void print_error(option opt);

