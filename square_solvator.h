#ifndef SOLVER_SQUARE_H
#define SOLVER_SQUARE_H

#define SS_INF_ROOTS  -1

int solve_square (double, double, double, double*, double*);
void print_roots(int, double, double);
void endless_input(double*, double*, double*);
int tester1_input(FILE*, double*, double*, double*, double*, double*, int*);
int is_zero(double);
void LOG_FATAL(const char* , ...);
void LOG_INFO(const char* , ...);

#endif
