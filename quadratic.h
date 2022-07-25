const double EPSILON = 0.000001;

enum num_of_solutions 
{
         no_sol =   0, 
        one_sol =   1, 
        two_sol =   2, 
        inf_sol = 777,
};

struct quadra 
{
        double a_coef                   = 0;
        double b_coef                   = 0;
        double c_coef                   = 0;
        enum   num_of_solutions sol_num = no_sol;
        double solution1                = 0;
        double solution2                = 0;
};

int  are_equal(double value1, double value2);
void scanner       (quadra* equation);
void solve         (quadra* equation);
void print_solution(quadra* equation);
void sort(double* value1, double* value2);

