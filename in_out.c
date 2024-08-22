#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square_solvator.h"

static void fbuff_fflush(FILE* fp) {
    while(getc(fp) != '\n');
}

static void buff_fflush() {
    while(getchar() != '\n');
    return;
}

void print_roots(int root_num, double x1, double x2) {
    switch (root_num) {
        case 0:
            printf("Equation has no roots\n");
            break;

        case 1:
            printf("Equation has one root %.3lf\n", x1);
            break;

        case 2:
            printf("Equation has two roots: %.3lf, %.3lf\n", x1, x2);
            break;

        case SS_INF_ROOTS:
            printf("Equation has infinite number of roots\n");
            break;

        default:
            printf("ERROR\n");
            break;
    }
}

int tester_input(FILE* fp, double* a, double* b, double* c, double* x1_exp, double* x2_exp, int* nRoots_exp) {
    int num_scanned = fscanf(fp, "%lg %lg %lg %lg %lg %d", a, b, c, x1_exp, x2_exp, nRoots_exp);
    if (num_scanned != -1) fbuff_fflush(fp);
    return num_scanned;
}

void endless_input(double* a, double* b, double* c) {
    printf ("Enter arguments a, b, c\n");
    while (scanf ("%lg %lg %lg", a, b, c) != 3) {
        buff_fflush();
        printf("You can enter only numbers\nPlease try again\n");
    }
}