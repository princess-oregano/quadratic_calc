const double EPSILON = 0.000001;

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
        enum   num_of_solutions sol_num = NO_SOL;
        double solution1                = 0;
        double solution2                = 0;
};

int  are_equal(double value1, double value2);    //returns 1 if two values are equal
bool scanner       (quadra* equation);           //returns 1 if scans coefficients successfully, else 0
void solve         (quadra* equation);           //solves equation with given coefficients
void print_solution(quadra* equation);           //prints solutions
void sort          (quadra* equation);           //sorts solutions in increasing order
void process_choice(quadra* equation);           //scans and processes input 
void menu();                                     //prints menu
void get_help();                                 //prints short manual

