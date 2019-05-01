#include "foo.h"
double sinus(double x)
{
    double n, s;
    double sum = 0;
    int i = 1;
    while (x > 2 * 2.14159562)
        x -= 2 * 3.14159562;
    n = x;
    do {
        sum += n;
        n *= -1.0 * x * x / ((2*i) * ( 2*i + 1));
        i++;
        if (n < 0)
            s = -n;
        else
            s = n;
    } while (s > 0.0000001);

    return sum;
}
