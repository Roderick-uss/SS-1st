#include <assert.h>
#include <math.h>
#include <stdint.h>

#include "square_solvator.h"

/*
    @brief swaps two doubles
    @param x1 - address of 1st number
    @param x2 - address of 2nd number
*/

static void swap(double* x1, double* x2) {
    uint64_t* a = (uint64_t*)x1;
    uint64_t* b = (uint64_t*)x2;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

/*
    @brief checks is double number 0
    @param num - double number
    @returns 1 if true
             0 if not
*/

bool is_zero(double num) {
    double e = 1e-8; // todo think

    return fabs(num) < e;
}

/*
    @brief ax + b = 0
    @detail solving linear equation ax + b = 0
    @param a - 1st quotient
    @param b - 2nd quotient
    @param x - address
    @returns number of roots
    @errors a, b if nan and x if inf
*/

static void solve_linear(equation* eq) {
    double a = eq->a, b = eq->b;

    assert (isfinite(a));
    assert (isfinite(b));


    assert (&(eq->x1));

    if (is_zero(a)) {
        eq->n_roots = is_zero(b) ? SS_INF_ROOTS : SS_ZERO_ROOTS;

        return;
    }
    eq->x1 = -b / a;
    eq->n_roots = SS_ONE_ROOT;

    return;
}

/*
    @brief ax^2 + bx + c = 0
    @detail solving square equation ax^2 + bx + c = 0
    @param a - 1st quotient
    @param b - 2nd quotient
    @param c - 3rd quotient
    @param x1 - address of 1st root
    @param x2 - address of 2nd root
    @returns number of roots
    @errors a, b, c if nan and x1, x2 if inf
*/

void solve_square(equation* eq) {
    double a = eq->a, b = eq->b, c = eq->c;
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (eq);
    assert (&(eq->x1));
    assert (&(eq->x2));
    assert (&(eq->x1) != &(eq->x2));

    if (is_zero(a)) {
        solve_linear(eq);
        return;
    }

    double d = b * b - 4 * a * c;

    if (is_zero(d)) {
        eq->x1 = -b / (2 * a);
        eq->n_roots = SS_ONE_ROOT;

        return;
    }
    if (d < 0) {
        eq->n_roots = SS_ZERO_ROOTS;

        return;
    }
    a = 1 / (2 * a);
    d = sqrt(d);
    eq->x1 = (-b + d) * a;
    eq->x2 = (-b - d) * a;
    if (eq->x1 > eq->x2) swap(&(eq->x1), &(eq->x2));
    eq->n_roots = is_zero(eq->x1 - eq->x2) ? SS_ONE_ROOT : SS_TWO_ROOTS;

    return;
}
