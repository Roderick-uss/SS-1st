#include <stdio.h>
#include <math.h>

#include "Square_Solvation.h"

void swap(double* x1, double* x2) {
    *x1 -= *x2;
    *x2 += *x1;
    *x1 = -*x1 + *x2;
}

int ruined(int num, double a, double b, double c, double x1_exp, double x2_exp, int nRoots_exp) {
    double x1 = 0, x2 = 0;
    int nRoots = Square_Solution(a, b, c, &x1, &x2);
    if (nRoots == 2 && x1 > x2) swap(&x1, &x2);

    if (nRoots != nRoots_exp || !iszero(x1 - x1_exp) || !iszero(x2 - x2_exp)) {
        printf("RUINED\nTest %d\nArgs: a = %lg, b = %lg, c = %lg\n"
        "Your answer: x1 = %lg, x2 = %lg, nRoots = %d\nTest snswer: x1 = %lg, x2 = %lg, nRoots = %d\n",
        num, a, b, c, x1, x2, nRoots, x1_exp, x2_exp, nRoots_exp);

        return 1;
    }
    return 0;
}

/*
    @detail ввод в файл tester txt в формате "a b c x1_exp x2_exp nRoot_exp"
*/

void tester2() {

    typedef struct{
        double a, b, c, x1, x2;
        int nRoots;
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

    for (int i = 0; i < sizeof pull / sizeof(test); ++i) {
        if (ruined(i + 1, pull[i].a, pull[i].b, pull[i].c, pull[i].x1, pull[i].x2, pull[i].nRoots)) break;
    }
}

void tester() {

    FILE* fp;
    fp = fopen("tester.txt", "r");

    int num = 1;
    double a, b, c, x1_exp, x2_exp;
    int nRoots_exp;
    while (tester_input(fp, &a, &b, &c, &x1_exp, &x2_exp, &nRoots_exp) != -1) {
        if (ruined(num++, a, b, c, x1_exp, x2_exp, nRoots_exp)) break;
    }

    fclose(fp);
}

int main () {
    tester2();
    tester();
    printf("end");
    return 0;
    double a = NAN, b = NAN, c = NAN;

    printf ("Square Solution\tUSS 2024\n");
    endless_input(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int root_num = Square_Solution (a, b, c, &x1, &x2);

    print_roots(root_num, x1, x2);
}