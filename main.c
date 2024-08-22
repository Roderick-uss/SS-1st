#include <stdio.h>
#include <math.h>

#include "square_solvator.h"

int check(int num, double a, double b, double c, double x1_exp, double x2_exp, int n_roots_exp) {
    double x1 = 0, x2 = 0;
    int n_roots = solve_square(a, b, c, &x1, &x2);

    if (n_roots != n_roots_exp || !is_zero(x1 - x1_exp) || !is_zero(x2 - x2_exp)) {
        printf("RUINED\nTest %d\n"
        "Args: a = %lg, b = %lg, c = %lg\n"
        "Your answer: x1 = %lg, x2 = %lg, nRoots = %d\n"
        "Test snswer: x1 = %lg, x2 = %lg, nRoots = %d\n",
        num,
        a, b, c,
        x1, x2, n_roots,
        x1_exp, x2_exp, n_roots_exp);

        return 0;
    }
    return 1;
}

/*
    @detail ввод в файл tester txt в формате "a b c x1_exp x2_exp n_root_exp"
*/

void tester2() {

    typedef struct{
        double a, b, c, x1, x2;
        int n_roots;
    }test;

    test pull[] = {
        {1, 0, -5, -2.23606797749, +2.23606797749, 2},
        {1, 2, -3, -3, 1, 2},
        {0, 0, 0, 0, 0, -1},
        {2, 3, 1, -1, -0.5, 2},
        {1, 0, -9, -3, 3, 2},
        {0, 0, 7.953293, 0, 0, 0},
        {0, 25, 100, -4, 0, 1},
        {4, 10, 34, 0, 0, 0}
    };

    for (int i = 0; i < sizeof(pull) / sizeof(test); ++i) {
        int is_failed = !check(i + 1, pull[i].a, pull[i].b, pull[i].c, pull[i].x1, pull[i].x2, pull[i].n_roots);
        if (is_failed) break;
    }
}

void tester() {
    FILE* fp;
    fp = fopen("tester.txt", "r");

    int num = 1, n_roots_exp;
    double a, b, c, x1_exp, x2_exp;

    while (tester_input(fp, &a, &b, &c, &x1_exp, &x2_exp, &n_roots_exp) != -1) {
        int is_failed = !check(num++, a, b, c, x1_exp, x2_exp, n_roots_exp);
        if (is_failed) break;
    }

    fclose(fp);
}

int main () {
 //   tester2();
 //   tester();
 //   printf("end");
 //   return 0;

    printf ("Square Solution\tUSS 2024\n");

    double a = NAN, b = NAN, c = NAN;
    endless_input(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int root_num = solve_square (a, b, c, &x1, &x2);

    print_roots(root_num, x1, x2);
}