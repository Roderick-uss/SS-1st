#include <math.h>

#include "square_solvator.h"

int main () {
    // todo struct
    equation eq = {NAN, NAN, NAN, 0, 0, SS_ZERO_ROOTS};
    endless_input(&(eq.a), &(eq.b), &(eq.c));

    solve_square(&eq);

    print_roots(&eq);
}
