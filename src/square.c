#include "foo.h"
double sqrt(double v)
{
    double L = 0, R = v, r;
    double M = (L + R) / 2;
    while (R - L > 1) {
        if (M * M <= v) {
            L = M;
        } else {
            R = M;
        }
        M = (L + R) / 2;
    }
    do {
        if ((M * M) > v)
            M -= 0.000001;
        else
            M += 0.0000001;
        if ((M * M - v) > 0)
            r = M * M - v;
        if ((M * M - v) < 0)
            r = (M * M - v) * (-1);
    } while (r > 0.000001);
    return M + 0.00001;
}
