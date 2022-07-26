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

int  are_equal(double value1, double value2);
bool scanner       (quadra* equation);
void solve         (quadra* equation);
void print_solution(quadra* equation);
void sort          (quadra* equation);
void scan_choice   (quadra* equation);
void menu();
void get_help();

