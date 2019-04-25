#include "foo.h"

double Calc(double num1, double num2, char s)
{
    double sum = 0;
    switch (s) {
    case '*':
        sum = num1 * num2;
        break;
    case '/':
        sum = num1 / num2;
        break;
    case '+':
        sum = num1 + num2;
        break;
    case '-':
        sum = num1 - num2;
        break;
    }
    return sum;
}
