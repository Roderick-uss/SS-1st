#include <stdio.h>
#include <math.h>

#include "Square_Solvation.h"

/*
    @detail ввод в файл tester txt в формате "a b c x1_exp x2_exp nRootexp

"*/
void tester() {
    FILE* fp;
    fp = fopen("tester.txt", "r");
    int num = 1;
    double a, b, c, x1_exp, x2_exp;
    int nRoots_exp;
    while (tester_input(fp, &a, &b, &c, &x1_exp, &x2_exp, &nRoots_exp) != -1) {
        if (ruined(num++, a, b, c, x1_exp, x2_exp, nRoots_exp)) break;
    }
}

int main () {
    tester();
    printf("end");
    return 0;
    double a = NAN, b = NAN, c = NAN;
    
    printf ("Square Solution\tUSS 2024\n");
    endless_input(&a, &b, &c);

    int root_num = 0;
    double x1 = 0, x2 = 0;

    root_num = Square_Solution (a, b, c, &x1, &x2);

    print_roots(root_num, x1, x2);
}