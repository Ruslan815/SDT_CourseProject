#include "foo.h"
#include <math.h>
#include <stdio.h>
double cosinus(double x)
{
    double n = 1.0;
    double cos = 0.0;
    int i = 1;
    while (x > 2 * 3.14159265)
        x -= 2 * 3.141592;
    do {
        cos += n;
        n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        i++;
    } while (fabs(n) > 0.0001);

    return cos;
}
