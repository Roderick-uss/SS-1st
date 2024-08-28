#ifndef SOLVER_SQUARE_H
#define SOLVER_SQUARE_H

#include<stdio.h>

enum SQUARE_CONST {
    SS_INF_ROOTS  = -1,
    SS_ZERO_ROOTS =  0,
    SS_ONE_ROOT   =  1,
    SS_TWO_ROOTS  =  2
};

enum LINE_CONST {
    MAX_LINE = 100
};

struct equation {
    double a, b, c, x1, x2;
    SQUARE_CONST n_roots;
};

FILE* get_file_name(char* file_name);
void solve_square (equation* eq);
void print_roots(equation* eq);
void endless_input(double* a, double* b, double* c);
bool is_zero(double mun);

#endif // SOLVER_SQUARE_H
