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