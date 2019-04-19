#include <stdio.h>
#include <stdlib.h>

// void Calc();

/*main(){
        Calc();
        return 0;
}*/

void Calc()
{
    int code, sum = 0, num1, num2, numS;
    char s;
    printf("Enter first number, sign, second number: \n");
    scanf("%d", &num1);
    // printf("Enter s: \n");
    scanf("%c", &s);
    scanf("%c", &s);
    // cin » s;
    // printf("Enter num2: \n");
    scanf("%d", &num2);
    // printf("\n");
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
    printf("%d", sum);
    while (1) {
        // printf("\nEnter sign and number for continue \nEnter 'e' for escape
        // \n");
        scanf("%c", &s);
        scanf("%c", &s);
        if (s == 'e')
            break;
        scanf("%d", &numS);
        printf("\n");
        switch (s) {
        case '*':
            sum *= numS;
            break;
        case '/':
            sum /= numS;
            break;
        case '+':
            sum += numS;
            break;
        case '-':
            sum -= numS;
            break;
        }
        printf("%d", sum);
    }
}
