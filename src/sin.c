#include "foo.h"
#include <math.h>
#include <stdio.h>
double sinus(double x)
{
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

    return f;
}
