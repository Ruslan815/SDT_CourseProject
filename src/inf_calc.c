#include "foo.h"
#include <string.h>

int power(int, int);
int fn_10(int, int);
int f10_n(int, int, int[], char[], int*);
int f11_16(char[], int);

int inf_calc(int a[], char str[], int* n, int sys1, int sys2, int num)
{
    int des;
    long res;
    if (sys1 >= 11 && sys1 <= 16) {
        des = f11_16(str, sys1);
        res = f10_n(des, sys2, a, str, &(*n));
    } else if (sys1 >= 1 && sys1 <= 10) {
        des = fn_10(num, sys1);
        res = f10_n(des, sys2, a, str, &(*n));
    } else
        res = -1;
    return res;
}

int power(int x, int n)
{
    int a = 1;
    while (n != 0) {
        a *= x;
        n--;
    }
    return a;
}

int fn_10(int num, int sys1)
{
    int p = num, ost, n = 0, i, s = 0, b = 0;
    while (p != 0) {
        n++;
        p /= 10;
    }
    for (i = 0; i < n; i++) {
        ost = num % 10;
        s = power(sys1, i);
        b += ost * s;
        num /= 10;
    }
    return b;
}

int f10_n(int num, int sys2, int a[], char str[], int* n)
{
    int i, k;
    long p = num;
    while (p != 0) {
        (*n)++;
        p /= sys2;
    }
    p = 0;
    if (sys2 >= 2 && sys2 <= 10) {
        for (i = 0; i < (*n); i++) {
            a[i] = num % sys2;
            num /= sys2;
        }
        for (i = *(n)-1; i >= 0; i--) {
            p = p * 10 + a[i];
        }
    } else if (sys2 >= 11 && sys2 <= 16) {
        i = 0;
        while (num > 0) {
            k = num % sys2;
            switch (k) {
            case 1:
                str[i] = '1';
                p += 1;
                break;
            case 2:
                str[i] = '2';
                p += 2;
                break;
            case 3:
                str[i] = '3';
                p += 3;
                break;
            case 4:
                str[i] = '4';
                p += 4;
                break;
            case 5:
                str[i] = '5';
                p += 5;
                break;
            case 6:
                str[i] = '6';
                p += 6;
                break;
            case 7:
                str[i] = '7';
                p += 7;
                break;
            case 8:
                str[i] = '8';
                p += 8;
                break;
            case 9:
                str[i] = '9';
                p += 9;
                break;
            case 0:
                str[i] = '0';
                break;
            case 10:
                str[i] = 'A';
                p += 10;
                break;
            case 11:
                str[i] = 'B';
                p += 11;
                break;
            case 12:
                str[i] = 'C';
                p += 12;
                break;
            case 13:
                str[i] = 'D';
                p += 13;
                break;
            case 14:
                str[i] = 'E';
                p += 14;
                break;
            case 15:
                str[i] = 'F';
                p += 15;
                break;
            }
            num /= sys2;
            i++;
        }
    } else
        p = -1;
    return p;
}

int f11_16(char str[], int sys1)
{
    int len, i, b = 0, s;
    len = strlen(str);
    for (i = len - 1; i >= 0; i--) {
        switch (str[i]) {
        case '1':
            s = power(sys1, len - 1 - i);
            b += 1 * s;
            break;
        case '2':
            s = power(sys1, len - 1 - i);
            b += 2 * s;
            break;
        case '3':
            s = power(sys1, len - 1 - i);
            b += 3 * s;
            break;
        case '4':
            s = power(sys1, len - 1 - i);
            b += 4 * s;
            break;
        case '5':
            s = power(sys1, len - 1 - i);
            b += 5 * s;
            break;
        case '6':
            s = power(sys1, len - 1 - i);
            b += 6 * s;
            break;
        case '7':
            s = power(sys1, len - 1 - i);
            b += 7 * s;
            break;
        case '8':
            s = power(sys1, len - 1 - i);
            b += 8 * s;
            break;
        case '9':
            s = power(sys1, len - 1 - i);
            b += 9 * s;
            break;
        case '0':
            break;
        case 'A':
            s = power(sys1, len - 1 - i);
            b += 10 * s;
            break;
        case 'B':
            s = power(sys1, len - 1 - i);
            b += 11 * s;
            break;
        case 'C':
            s = power(sys1, len - 1 - i);
            b += 12 * s;
            break;
        case 'D':
            s = power(sys1, len - 1 - i);
            b += 13 * s;
            break;
        case 'E':
            s = power(sys1, len - 1 - i);
            b += 14 * s;
            break;
        case 'F':
            s = power(sys1, len - 1 - i);
            b += 15 * s;
            break;
        }
    }
    return b;
}
