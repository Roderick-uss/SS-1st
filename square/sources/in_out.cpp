#include <assert.h>
#include <math.h>
#include <stdio.h>

#include "colors.h"
#include "square_solvator.h"


static void get_line(char* line) {
    size_t i = 0;
    while((line[i++] = (char)getchar()) != '\n');
    return;
}

static void get_line_strip(char* line) {
    get_line(line);
    size_t i = 0;
    while(line[i++] != '\n');
    line[--i] = '\0';
    return;
}

/*
    @brief fflushs input buffer
*/

static void buff_fflush() {
    for(int curr_ch = NULL; curr_ch != '\n' && curr_ch != EOF; curr_ch = getchar());
    return;
}

/*
    @brief prints number of roots of square equation
    @param root_num - number of roots
    @param x1 - 1st root
    @param x2 - 2nd root
*/

FILE* get_file_name(char* file_name) {
    FILE* fp = NULL;
    while (fp == NULL){
//        scanf("%s", file_name);
//        buff_fflush();
        get_line_strip(file_name);
        fp = fopen(file_name, "r");
        if (fp == NULL) {
            LOG_FATAL("Incorrect input\n No such txt file(");
            printf("%s", file_name);
            LOG_FATAL(") in directory\n");
            LOG_INFO("Please try again\n");
        }
    }
    return fp;
}

void print_roots(equation* eq) {
    assert(isfinite(eq->x1));
    assert(isfinite(eq->x2));


    switch (eq->n_roots) {
        case SS_ZERO_ROOTS:
            LOG_INFO("Equation has no roots\n");
            break;

        case SS_ONE_ROOT:
            LOG_INFO("Equation has one root \n");
            printf("%.3lf", eq->x1);
            break;

        case SS_TWO_ROOTS:
            LOG_INFO("Equation has two roots: ");
            printf("%.4lf %.4lf\n", eq->x1, eq->x2);
            break;

        case SS_INF_ROOTS:
            LOG_INFO("Equation has infinite number of roots\n");
            break;

        default:
            printf("ERROR\n");
            break;
    }
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
        LOG_FATAL("You can enter only numbers\n");
        LOG_INFO("Please try again\n");
    }
}
