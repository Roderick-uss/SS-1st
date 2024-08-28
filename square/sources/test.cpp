#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>

#include "colors.h"
#include "square_solvator.h"

#define FREE(data) {free(data); data = NULL;}

static bool check(int num, equation eq);
static void tester_struct();
static void tester_file();

int main () {
    LOG_INFO("\nEnter txt file name with .txt\n");
    tester_file();
    tester_struct();

    return 0;
}

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
static bool check(int num, equation eq_exp) {
    equation eq = eq_exp;
    solve_square(&eq);

    if (eq.n_roots != eq_exp.n_roots || !is_zero(eq.x1 - eq_exp.x1) || !is_zero(eq.x2 - eq_exp.x2)) {

        LOG_FATAL("RUINED\nTest %d\n"
        "Args:        a  = %lg, b  = %lg, c      = %lg\n"
        "Prog answer: x1 = %lg, x2 = %lg, nRoots = %d\n"
        "Test answer: x1 = %lg, x2 = %lg, nRoots = %d\n\n",
        num,
        eq.a, eq.b, eq.c,
        eq.x1, eq.x2, eq.n_roots,
        eq_exp.x1, eq_exp.x2, (int)eq_exp.n_roots);

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
static void tester_struct() {

    equation test_pool[] = {
        {1, 0, -5,       -2.23606797749, 2.23606797749, SS_TWO_ROOTS},
        {1, 2, -3,       -3,             1,             SS_TWO_ROOTS},
        {0, 0,  0,        0,             0,             SS_INF_ROOTS},
        {2, 3,  1,       -1,          -0.5,             SS_TWO_ROOTS},
        {1, 0, -9,       -3,             3,             SS_TWO_ROOTS},
        {0, 0,  7.953293, 0,             9,             SS_ZERO_ROOTS},
        {0, 25, 100,     -4,             3,             SS_ONE_ROOT},
        {4, 10, 34,       0,             7,             SS_ZERO_ROOTS},
    };
    int error_cnt = 0;

    LOG_INFO("\nRun on tests from test_pool in test.cpp\n\n");

    for (size_t i = 0; i < sizeof(test_pool) / sizeof(equation); ++i) {
        bool is_failed = !check((int)i + 1, test_pool[i]);
        if (is_failed) error_cnt++;
    }

    LOG_INFO("\nTests failed:");
    LOG_FATAL(" %d\n", error_cnt);
    LOG_INFO("End of test_pool\n\n");
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

static void tester_file() { // todo filename as arg
    char* file_name = (char *)calloc((size_t)MAX_LINE, sizeof(char));

    LOG_INFO("\nEnter the name of file with tests\nIt must be with ");
    printf(".txt");
    LOG_INFO(" extension\n");
    FILE* fp = get_file_name(file_name);
    assert(fp);

    equation eq = {};
    int num = 1;
    int error_cnt = 0;
    int n_roots = 0;

    LOG_INFO("\nRun on tests from file %s\n\n", file_name);

    while (fscanf(fp, "%lg %lg %lg %lg %lg %d", &(eq.a), &(eq.b), &(eq.c), &(eq.x1), &(eq.x2), &n_roots) != EOF) {
        eq.n_roots = (SQUARE_CONST) n_roots;

        bool is_failed = !check(num++, eq);
        if (is_failed) error_cnt++; // todo more smooth
    }

    LOG_INFO("\nTests failed:");
    LOG_FATAL(" %d\n", error_cnt);
    LOG_INFO("End of file %s\n\n", file_name);

    FREE(file_name);
    fclose(fp);
    return;
}
