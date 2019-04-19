#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// using namespace std;

int pow(int, int);
int f10_2(int);
int fn_10(int, int);
int f10_n(int, int);
int f11_16(char[], int);
int f10_16_n(int, int);
// void InfCalc();

/*main(){
        InfCalc();
        return 0;
}*/

void InfCalc()
{
    int sys1, sys2, num, res, des;
    char str[20];
    printf("Enter 2 number system: ");
    scanf("%d%d", &sys1, &sys2);
    /*printf("Enter number: ");
    scanf("%d",&num);*/
    if (sys1 >= 11 && sys1 <= 16) {
        printf("Enter number: ");
        scanf("%s", str);
        des = f11_16(str, sys1);
        f10_n(des, sys2);
    } else {
        printf("Enter number: ");
        scanf("%d", &num);
        des = fn_10(num, sys1);
        // printf("des= %d \n",des);
        f10_n(des, sys2);
        // res=f10_2(des);
    }
    // printf("Result: %d",res);
    // return 0;
}

int pow(int x, int n)
{
    int a = 1;
    while (n != 0) {
        if (n % 2 != 0) {
            a *= x;
            n--;
        } else {
            x *= x;
            n /= 2;
        }
    }
    return a;
}

/*int f10_2(int num){
        int k=1, b=0;
        while (num!=0){
                b+=num%2*k;
                num/=2;
                k*=10;
        }
        return b;
}*/

int fn_10(int num, int sys1)
{
    int p = num, ost, n = 0, i, s = 0, b = 0;
    while (p != 0) {
        n++;
        p /= 10;
        // cout « "p=" « p « endl;
        // printf("n=%d \n",n);
    }
    for (i = 0; i < n; i++) {
        ost = num % 10;
        // cout « "ost=" « ost « endl;
        s = pow(sys1, i);
        // printf("s=%d \n",s);
        b += ost * s;
        num /= 10;
        // printf("num=%d \n",num);
    }
    // cout « "b=" « b « endl;
    return b;
}

int f10_n(int num, int sys2)
{
    int p = num, i, n = 0, *a, k, len;
    char* str;
    while (p != 0) {
        n++;
        p /= sys2;
    }
    // printf("n= %d \n",n);
    if (sys2 >= 2 && sys2 <= 10) {
        a = new int[n];
        for (i = 0; i < n; i++) {
            a[i] = num % sys2;
            // printf("%d",a[i]);
            num /= sys2;
        }
        for (i = n - 1; i >= 0; i--)
            printf("%d", a[i]);
        delete a;
    } else {
        str = new char[n];
        i = 0;
        while (num > 0) {
            k = num % sys2;
            // printf("k=%d \n",k);
            switch (k) {
            case 1:
                str[i] = '1';
                break;
            case 2:
                str[i] = '2';
                break;
            case 3:
                str[i] = '3';
                break;
            case 4:
                str[i] = '4';
                break;
            case 5:
                str[i] = '5';
                break;
            case 6:
                str[i] = '6';
                break;
            case 7:
                str[i] = '7';
                break;
            case 8:
                str[i] = '8';
                break;
            case 9:
                str[i] = '9';
                break;
            case 10:
                str[i] = 'A';
                break;
            case 11:
                str[i] = 'B';
                break;
            case 12:
                str[i] = 'C';
                break;
            case 13:
                str[i] = 'D';
                break;
            case 14:
                str[i] = 'E';
                break;
            case 15:
                str[i] = 'F';
                break;
            default:
                printf("Error \n");
                return 0;
            }
            num /= sys2;
            i++;
        }
        len = strlen(str);
        // printf("len=%d \n",len);
        i = len - 1;
        while (i >= 0) {
            putchar(str[i]);
            i--;
        }
        delete str;
    }
}

int f11_16(char str[], int sys1)
{
    int len, *a, i, j, b = 0, sp, s;
    len = strlen(str);
    for (i = len - 1; i >= 0; i--) {
        switch (str[i]) {
        case '1':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 1 * s;
            break;
        case '2':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 2 * s;
            break;
        case '3':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 3 * s;
            break;
        case '4':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 4 * s;
            break;
        case '5':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 5 * s;
            break;
        case '6':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 6 * s;
            break;
        case '7':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 7 * s;
            break;
        case '8':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 8 * s;
            break;
        case '9':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 9 * s;
            break;
        case 'A':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 10 * s;
            break;
        case 'B':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 11 * s;
            break;
        case 'C':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 12 * s;
            break;
        case 'D':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 13 * s;
            break;
        case 'E':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 14 * s;
            break;
        case 'F':
            s = pow(sys1, len - 1 - i);
            // printf("s=%d \n",s);
            b += 15 * s;
            break;
        default:
            printf("Error \n");
            return 0;
        }
    }
    return b;
}
