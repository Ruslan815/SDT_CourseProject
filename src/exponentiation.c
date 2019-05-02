#include "foo.h"
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
        for (i = -1; i >= n; i--) {
            f *= 1 / x;
        }
    }
    if (x == 0) {
        f = 1;
    }
    return f;
}
