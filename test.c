#include <stdio.h>
#include <math.h>

#include "square_solvator.h"
/*
    @brief checks received roots with test's
    @param a - 1st quotient
    @param b - 2nd quotient
    @param c - 3rd quotient
    @param x1_exp - smaller test root
    @param x2_exp - larger test root
    @param n_roots_exp - test number of roots
    @returns 1 if receiver roots equal to test's
             0 if not equal
*/
int check(int num, double a, double b, double c, double x1_exp, double x2_exp, int n_roots_exp) {
    double x1 = 0, x2 = 0;
    int n_roots = solve_square(a, b, c, &x1, &x2);

    if (n_roots != n_roots_exp || !is_zero(x1 - x1_exp) || !is_zero(x2 - x2_exp)) {
        
        LOG_FATAL("RUINED\nTest %d\n"
        "Args: a = %lg, b = %lg, c = %lg\n"
        "Prog answer: x1 = %lg, x2 = %lg, nRoots = %d\n"
        "Test answer: x1 = %lg, x2 = %lg, nRoots = %d\n",
        num,
        a, b, c,
        x1, x2, n_roots,
        x1_exp, x2_exp, n_roots_exp);

        return 0;
    }
    return 1;
}

/*
    @breaf tester2 for solve_square
    @input in init of pull[]
    @param a - 1st quotient
    @param b - 2nd quotient
    @param c - 3rd quotient
    @param x1 - smaller quolient(0 if infinite)
    @param x2 - larger quolient(0 or 1 if infinite)
    @param n_roots - number of roots(-1 if infinite)
*/

void tester2() {

    typedef struct{
        double a, b, c, x1, x2;
        int n_roots;
    }test;

    test pull[] = {
        {1, 0, -5, -2.23606797749, +2.23606797749, 2},
        {1, 2, -3, -3, 1, 2},
        {0, 0, 0, 0, 0, SS_INF_ROOTS},
        {2, 3, 1, -1, -0.5, 2},
        {1, 0, -9, -3, 3, 2},
        {0, 0, 7.953293, 0, 0, 0},
        {0, 25, 100, -4, 0, 1},
        {4, 10, 34, 0, 0, 5},
    };

    for (int i = 0; i < sizeof(pull) / sizeof(test); ++i) {
        int is_failed = !check(i + 1, pull[i].a, pull[i].b, pull[i].c, pull[i].x1, pull[i].x2, pull[i].n_roots);
        if (is_failed) break;
    }
}

/*
    @breaf tester1 for solve_square
    @input in tester.txt(\n - separated simbol between tests)
           input order: a b c x1_exp x2_exp c_roots_exp
    @param a - 1st quotient
    @param b - 2nd quotient
    @param c - 3rd quotient
    @param x1_exp - smaller quolient(0 if infinite)
    @param x2_exp - larger quolient(0 or 1 if infinite)
    @param n_roots_exp - number of roots(-1 if infinite)
*/

void tester1() {
    FILE* fp;
    fp = fopen("tester.txt", "r");

    int num = 1, n_roots_exp;
    double a, b, c, x1_exp, x2_exp;

    while (tester1_input(fp, &a, &b, &c, &x1_exp, &x2_exp, &n_roots_exp) != -1) {
        int is_failed = !check(num++, a, b, c, x1_exp, x2_exp, n_roots_exp);
        if (is_failed) break;
    }

    fclose(fp);
}

int main () {
    tester2();
    tester1();
    LOG_INFO("end");
}