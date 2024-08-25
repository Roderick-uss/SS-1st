#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "square_solvator.h"

/*
    strcmp
    memset
    strchr
    strcat
    memmove
    strdup
*/

/*
    @brief colored print
    @param COL - string with color code
    @param factor(va list, va_start before function and va_end after function)
    @param format - output string like in printf
*/

static void col_print(const char* format, const char* COL, va_list factor) {
    const char* WHITE = "\033[37m";

    printf("%s", COL);
    vprintf(format, factor);
    printf("%s", WHITE);
}

/*
    @brief prints with red color
    @param format - output string like in printf
*/

void LOG_FATAL(const char* format, ...) {
    const char* RED = "\033[31m";
    va_list factor;

    va_start(factor, format);
    col_print(format, RED, factor);
    va_end(factor);
}

/*
    @brief prints with green color
    @param format - output string like in printf
*/

void LOG_INFO(const char* format, ...) {
    const char* GREEN = "\033[32m"; 
    va_list factor;

    va_start(factor, format);
    col_print(format, GREEN, factor);
    va_end(factor);
}

/*
    @brief fflushs input buffer
*/

static void buff_fflush() {
    while(getchar() != '\n');
    return;
}

/*
    @brief prints number of roots of square equation
    @param root_num - number of roots
    @param x1 - 1st root
    @param x2 - 2nd root
*/

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

/*
    @brief input for tester1
    @param fp - file adress
    @param a - address of 1st quotient
    @param b - address of 2nd quotient
    @param c - address of 3rd quotient
    @param x1 - address of 1st root
    @param x2 - address of 2nd root
    @returns number that returns fscanf
*/

int tester1_input(FILE* fp, double* a, double* b, double* c, double* x1_exp, double* x2_exp, int* nRoots_exp) {
    int num_scanned = fscanf(fp, "%lg %lg %lg %lg %lg %d", a, b, c, x1_exp, x2_exp, nRoots_exp);
    return num_scanned;
}

/*
    @brief requirs correct input
    @param a - address of 1st quotient
    @param b - address of 2nd quotient
    @param c - address of 3rd quotient
*/

void endless_input(double* a, double* b, double* c) {

    LOG_INFO("Enter arguments a, b, c\n");

    while (scanf ("%lg %lg %lg", a, b, c) != 3) {
        buff_fflush();
        LOG_INFO("You can enter only numbers\nPlease try again\n");
    }
}
