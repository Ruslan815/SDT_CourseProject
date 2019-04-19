#include "foo.h"
#include <math.h>
#include <stdio.h>
double tan(double x)
{
    double t;
    double sum = 0, c, f, e, z = 1;
    int n = 2;
    while (x > 2 * 3.14159265)
        x -= 2 * 3.141592;
    c = x;
    do {
        e = c / f;
        sum += e * z;
        z = -z;
        c *= x * x;
        f *= n * (n + 1);
        n = n + 2;
    } while (e > 0.0001);
    n = 1.0;
    c = 0.0;
    int i = 1;
    do {
        c += n;
        n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        i++;
    } while (fabs(n) > 0.0001);
    t = f / c;
    return t;
}
