#include <stdio.h>
#include <math.h>

#include "square_solvator.h"

int main () {

    double a = NAN, b = NAN, c = NAN;
    endless_input(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int root_num = solve_square (a, b, c, &x1, &x2);

    print_roots(root_num, x1, x2);
}
