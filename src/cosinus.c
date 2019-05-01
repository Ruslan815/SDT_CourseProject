#include "foo.h"
double cosinus(double x)
{
    double n = 1.0;
    double cos = 0.0;
    double s;
    int i = 1;
    while (x > 2 * 3.14159265)
        x -= 2 * 3.14159265;
    do {
        cos += n;
        n *= -1.0 * x * x / ((2 * i - 1) * (2 * i));
        i++;
        if (n < 0)
            s = -1.0 * n;
        else
            s = n;
    } while (s > 0.0000001);
    return cos;
}
