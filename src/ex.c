#include "foo.h"
#include <stdio.h>
double exponentiation(double x, int n)
{
    int i;
    double f = 1;
    if (n > 0) {
        for (i = 1; i <= n; i++) {
            f *= x;
        }
    }
    if (n < 0) {
        for (i = 1; i <= n; i++) {
            f *= 1 / x;
        }
    }
    return f;
}
