#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Square_Solvation.h"

int iszero(double a) {
    double e = 1e-8;
    return fabs(a) < e;
}

/*
    @brief ax + b = 0
    @detail solving linear equation ax + b = 0
    @param a - 1st quotient
    @param b - 2nd quotient
    @param x - root's adress
    @returns number of roots
    @errors a, b if nan and x if inf
*/

int Linear_Solution(double a, double b, double* x) {
    assert (isfinite(a));
    assert (isfinite(b));

    assert (x != 0);

    if (iszero(a)) return iszero(b)? SS_INF_ROOTS : 0;

    *x = -b / a;
    return 1;
}

/*
    @brief ax^2 + bx + c = 0
    @detail solving square equation ax^2 + bx + c = 0
    @param a - 1st quotient
    @param b - 2nd quotient
    @param c - 3rd quotient
    @param x1 - & 1st root
    @param x2 - & 2nd root
    @returns number of roots
    @errors a, b, c if nan and x1, x2 if inf
*/

int Square_Solution (double a, double b, double c, double* x1, double* x2) {
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != 0);
    assert (x2 != 0);
    assert (x1 != x2);
    
    
    if (iszero(a)) return Linear_Solution(b, c, x1);

    double d = b * b - 4 * a * c;
    
    if (iszero(d)) {
        *x1 = -b / (2 * a);
        return 1;
    }
    if (d < 0) {
        return 0;
    }
    a = 1 / (2*a);
    d = sqrt(d);
    *x1 = (-b + d) * a;
    *x2 = (-b - d) * a;
    return iszero(*x1 - *x2)? 1 : 2;
}
