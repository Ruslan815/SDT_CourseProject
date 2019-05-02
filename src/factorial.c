#include "foo.h"
int factorial(int x)
{
    int f = 1, i;
    if (x < 0)
        f = -1;
    else {
        for (i = 1; i <= x; i++) {
            f *= i;
        }
    }
    return f;
}
