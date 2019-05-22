#include "foo.h"
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    bool flag = 1, s, num, point;
    int mode, code, x, y, massx[5], massy[8], i, j, position, n = 0, a[20], arrow, i1, j1, sys1, sys2, Z = 0;
    long number;
    double first, second, result, drob, drob1, zero, buffer;
    char ch, deystvie, outp[10], str[20], output[20];
    POINT cursorposition;
    FILE* p;

    p = fopen("mode.txt", "r");
    system("CLS");
    rewind(p);
    ch = getc(p);
    fclose(p);

    if (ch == '1') {
        mode = 1;
    } else if (ch == '2') {
        mode = 2;
    } else if (ch == '3') {
        mode = 3;
    } else {
        return 0;
    }

    for (i = 0; i < 5; i++) {
        massx[i] = i * 60;
    }
    for (j = 0; j < 7; j++) {
        massy[j] = 60 + j * 30;
    }
    massy[7] = 300;

    while (flag == 1) {
        switch (mode) {
        case 1:
            initwindow(240, 300);
            simple_calculator();
            first = 0.000000;
            second = 0.000000;
            result = 0.0000000;
            deystvie = '0';
            drob = 0.000000;
            drob1 = 0.000000;
            point = 0;
            num = 1;
            zero = 1;
            while (1) {
                code = 1;
                s = 1;
                if (kbhit()) {
                    code = getch();
                    if (code == 27) {
                        ch = '1';
                        flag = 0;
                        break;
                    } else if (code == 49) {
                        menu();
                        delay(10);
                        while (s == 1) {
                            if (GetAsyncKeyState(VK_LBUTTON)) {
                                GetCursorPos(&cursorposition);
                                x = cursorposition.x - 8;
                                y = cursorposition.y - 30;
                                if (x > 0 && y > 0 && x < 175 && y < 25) {
                                    simple_calculator();
                                    break;
                                } else if (x > 0 && y > 25 && x < 175 && y < 50) {
                                    s = 0;
                                    mode = 2;
                                    break;
                                } else if (x > 0 && y > 50 && x < 175 && y < 75) {
                                    s = 0;
                                    mode = 3;
                                    break;
                                }
                            }
                        }
                        if (s == 0) {
                            break;
                        }
                    } else if (code == 13) {
                        switch (deystvie) {
                        case '%':
                            result = percent(first, second);
                            break;
                        case 'v':
                            result = sqrt(first);
                            break;
                        case '0':
                            result = 0;
                            break;
                        default:
                            result = calc(first, second, deystvie);
                            break;
                        }
                        first = result;
                        second = 0.000000;
                        num = 0;
                        point = 0;
                        drob1 = 0.000000;
                        drob = 0.000000;
                        zero = 1;
                        deystvie = '0';

                        setfillstyle(1, 0);
                        bar(1, 1, 239, 59);
                        buffer = result;
                        buffer = snprintf(outp, 10, "%f", buffer);
                        outtextxy(10, 25, outp);
                        delay(1000);
                    } else {
                        continue;
                    }
                } else {
                    if (GetAsyncKeyState(VK_LBUTTON)) {
                        GetCursorPos(&cursorposition);
                        x = cursorposition.x - 8;
                        y = cursorposition.y - 30;
                        for (i = 0; i < 5; i++) {
                            if (x > massx[i]) {
                                continue;
                            } else if (x < massx[i]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        for (j = 0; j < 8; j++) {
                            if (y > massy[j]) {
                                continue;
                            } else if (y < massy[j]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        if (i > 0 && i < 4) {
                            switch (j) {
                            case 2:
                                j = 1;
                                break;
                            case 4:
                                j = 3;
                                break;
                            case 6:
                                j = 5;
                                break;
                            case 8:
                                j = 7;
                                break;
                            }
                        }
                        if (j == 7 && i == 2) {
                            i = 1;
                        }
                        position = i * 10 + j;

                        switch (position) {
                        case 11:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 7;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 7;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 7;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 7;
                                    delay(1000);
                                }
                            }
                            break;
                        case 21:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 8;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 8;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 8;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 8;
                                    delay(1000);
                                }
                            }
                            break;
                        case 31:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 9;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 9;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 9;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 9;
                                    delay(1000);
                                }
                            }
                            break;
                        case 41:
                            deystvie = '+';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 42:
                            deystvie = '-';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 13:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 4;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 4;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 4;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 4;
                                    delay(1000);
                                }
                            }
                            break;
                        case 23:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 5;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 5;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 5;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 5;
                                    delay(1000);
                                }
                            }
                            break;
                        case 33:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 6;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 6;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 6;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 6;
                                    delay(1000);
                                }
                            }
                            break;
                        case 43:
                            deystvie = '*';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 44:
                            deystvie = '/';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 15:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 1;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 1;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 1;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 1;
                                    delay(1000);
                                }
                            }
                            break;
                        case 25:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 2;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 2;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 2;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 2;
                                    delay(1000);
                                }
                            }
                            break;
                        case 35:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 3;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 3;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 3;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 3;
                                    delay(1000);
                                }
                            }
                            break;
                        case 45:
                            deystvie = '%';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 46:
                            deystvie = 'v';
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 17:
                            if (point && drob == 0) {
                                zero *= 0.1;
                                delay(1000);
                            } else if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = drob * 10;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = drob * 10;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = first * 10;
                                    delay(1000);
                                } else {
                                    second = second * 10;
                                    delay(1000);
                                }
                            }
                            break;
                        case 37:
                            point = 1;
                            delay(1000);
                            break;
                        case 47:
                            buffer = 0.000000;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            outtextxy(10, 25, outp);
                            first = 0.000000;
                            second = 0.000000;
                            result = 0.0000000;
                            deystvie = '0';
                            drob = 0.000000;
                            drob1 = 0.000000;
                            point = 0;
                            num = 1;
                            zero = 1;
                            break;
                        }

                        if (num) {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = first;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                        } else {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = second;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                        }
                    }
                }
            }

            closegraph();
            break;
        case 2:
            initwindow(240, 300);
            engineering_calculator();
            first = 0.000000;
            second = 0.000000;
            result = 0.0000000;
            deystvie = '0';
            drob = 0.000000;
            drob1 = 0.000000;
            point = 0;
            num = 1;
            zero = 1;
            while (1) {
                code = 1;
                s = 1;
                if (kbhit()) {
                    code = getch();
                    if (code == 27) {
                        ch = '2';
                        flag = 0;
                        break;
                    } else if (code == 49) {
                        menu();
                        delay(10);
                        while (s == 1) {
                            if (GetAsyncKeyState(VK_LBUTTON)) {
                                GetCursorPos(&cursorposition);
                                x = cursorposition.x - 8;
                                y = cursorposition.y - 30;
                                if (x > 0 && y > 0 && x < 175 && y < 25) {
                                    s = 0;
                                    mode = 1;
                                    break;
                                } else if (x > 0 && y > 25 && x < 175 && y < 50) {
                                    engineering_calculator();
                                    break;
                                } else if (x > 0 && y > 50 && x < 175 && y < 75) {
                                    s = 0;
                                    mode = 3;
                                    break;
                                }
                            }
                        }
                        if (s == 0) {
                            break;
                        }
                    } else if (code == 13) {
                        switch (deystvie) {
                        case 'e':
                            if (drob != 0) {
                                second -= drob1;
                            }
                            result = exponentiation(first, second);
                            break;
                        case '0':
                            result = 0;
                            break;
                        default:
                            break;
                        }
                        first = result;
                        second = 0.000000;
                        num = 1;
                        point = 0;
                        drob1 = 0.000000;
                        drob = 0.000000;
                        zero = 1;
                        deystvie = '0';

                        setfillstyle(1, 0);
                        bar(1, 1, 239, 59);
                        buffer = result;
                        buffer = snprintf(outp, 10, "%f", buffer);
                        outtextxy(10, 25, outp);
                        delay(1000);
                    } else {
                        continue;
                    }
                } else {
                    if (GetAsyncKeyState(VK_LBUTTON)) {
                        GetCursorPos(&cursorposition);
                        x = cursorposition.x - 8;
                        y = cursorposition.y - 30;
                        for (i = 0; i < 5; i++) {
                            if (x > massx[i]) {
                                continue;
                            } else if (x < massx[i]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        for (j = 0; j < 8; j++) {
                            if (y > massy[j]) {
                                continue;
                            } else if (y < massy[j]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        if (i > 0 && i < 4) {
                            switch (j) {
                            case 2:
                                j = 1;
                                break;
                            case 4:
                                j = 3;
                                break;
                            case 6:
                                j = 5;
                                break;
                            case 8:
                                j = 7;
                                break;
                            }
                        }
                        if (j == 7 && i == 2) {
                            i = 1;
                        }
                        position = i * 10 + j;

                        switch (position) {
                        case 11:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 7;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 7;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 7;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 7;
                                    delay(1000);
                                }
                            }
                            break;
                        case 21:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 8;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 8;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 8;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 8;
                                    delay(1000);
                                }
                            }
                            break;
                        case 31:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 9;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 9;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 9;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 9;
                                    delay(1000);
                                }
                            }
                            break;
                        case 41:
                            num = 1;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            result = sinus(first);
                            first = result;
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = result;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                            break;
                        case 42:
                            num = 1;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            result = cosinus(first);
                            first = result;
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = result;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                            break;
                        case 13:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 4;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 4;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 4;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 4;
                                    delay(1000);
                                }
                            }
                            break;
                        case 23:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 5;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 5;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 5;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 5;
                                    delay(1000);
                                }
                            }
                            break;
                        case 33:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 6;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 6;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 6;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 6;
                                    delay(1000);
                                }
                            }
                            break;
                        case 43:
                            num = 1;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            result = tangent(first);
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            if (result == 10) {
                                result = 0;
                                outtextxy(10, 25, "Not exist!");
                            } else {
                                buffer = result;
                                buffer = snprintf(outp, 10, "%f", buffer);
                                outtextxy(10, 25, outp);
                            }
                            first = result;
                            delay(1000);
                            break;
                        case 44:
                            num = 1;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            result = cotangent(first);
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            if (result == 10) {
                                result = 0;
                                outtextxy(10, 25, "Not exist!");
                            } else {
                                buffer = result;
                                buffer = snprintf(outp, 10, "%f", buffer);
                                outtextxy(10, 25, outp);
                            }
                            first = result;
                            delay(1000);
                            break;
                        case 15:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 1;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 1;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 1;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 1;
                                    delay(1000);
                                }
                            }
                            break;
                        case 25:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 2;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 2;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 2;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 2;
                                    delay(1000);
                                }
                            }
                            break;
                        case 35:
                            if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = (drob * 10) + 3;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = (drob * 10) + 3;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = (first * 10) + 3;
                                    delay(1000);
                                } else {
                                    second = (second * 10) + 3;
                                    delay(1000);
                                }
                            }
                            break;
                        case 45:
                            num = 1;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            if (drob != 0) {
                                first -= drob1;
                            }
                            result = factorial(first);
                            first = result;
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = result;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                            break;
                        case 46:
                            deystvie = 'e';
                            num = 0;
                            point = 0;
                            drob1 = 0.000000;
                            drob = 0.000000;
                            zero = 1;
                            delay(1000);
                            break;
                        case 17:
                            if (point && drob == 0) {
                                zero *= 0.1;
                                delay(1000);
                            } else if (point) {
                                if (num) {
                                    first -= drob1;
                                    drob = drob * 10;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    first += drob1;
                                    delay(1000);
                                } else {
                                    second -= drob1;
                                    drob = drob * 10;
                                    drob1 = drob;
                                    while (drob1 >= 0.1) {
                                        drob1 /= 10;
                                    }
                                    drob1 *= 10;
                                    drob1 *= zero;
                                    second += drob1;
                                    delay(1000);
                                }
                            } else {
                                if (num) {
                                    first = first * 10;
                                    delay(1000);
                                } else {
                                    second = second * 10;
                                    delay(1000);
                                }
                            }
                            break;
                        case 37:
                            point = 1;
                            delay(1000);
                            break;
                        case 47:
                            buffer = 0.000000;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            outtextxy(10, 25, outp);
                            first = 0.000000;
                            second = 0.000000;
                            result = 0.0000000;
                            deystvie = '0';
                            drob = 0.000000;
                            drob1 = 0.000000;
                            point = 0;
                            num = 1;
                            zero = 1;
                            break;
                        }

                        if (num) {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = first;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                        } else {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = second;
                            buffer = snprintf(outp, 10, "%f", buffer);
                            outtextxy(10, 25, outp);
                            delay(1000);
                        }
                    }
                }
            }

            closegraph();
            break;

        case 3:
            initwindow(240, 300);
            calculator_ons();
            sys1 = 0;
            sys2 = 0;
            result = 0;
            number = 0;
            arrow = 0;
            i1 = 0;
            snprintf(output, 2, "%d", Z);
            memset(str, 0, 20);
            while (1) {
                code = 1;
                s = 1;
                if (kbhit()) {
                    code = getch();
                    if (code == 27) {
                        ch = '3';
                        flag = 0;
                        break;
                    } else if (code == 49) {
                        menu();
                        delay(1000);
                        while (s == 1) {
                            if (GetAsyncKeyState(VK_LBUTTON)) {
                                GetCursorPos(&cursorposition);
                                x = cursorposition.x - 8;
                                y = cursorposition.y - 30;
                                if (x > 0 && y > 0 && x < 175 && y < 25) {
                                    s = 0;
                                    mode = 1;
                                    break;
                                } else if (x > 0 && y > 25 && x < 175 && y < 50) {
                                    s = 0;
                                    mode = 2;
                                    break;
                                } else if (x > 0 && y > 50 && x < 175 && y < 75) {
                                    calculator_ons();
                                    break;
                                }
                            }
                        }
                        if (s == 0) {
                            break;
                        }
                    } else if (code == 13) {
                        snprintf(output, 2, "%d", Z);
                        setfillstyle(1, 0);
                        bar(1, 1, 239, 59);
                        n = 0;
                        number = inf_calc(a, str, &n, sys1, sys2, number);
                        if (number == -1) {
                            outtextxy(10, 25, "Error!");
                            delay(1000);
                            break;
                        }
                        if (sys2 >= 2 && sys2 <= 10) {
                            memset(str, 0, 20);
                            for (i = n - 1; i >= 0; i--) {
                                snprintf(outp, 2, "%d", a[i]);
                                output[n - i - 1] = outp[0];
                            }
                            for (i = n; i < 20; i++) {
                                output[i] = ' ';
                            }
                            outtextxy(10, 25, output);
                            delay(1000);
                        } else {
                            for (i = 0; i < 20; i++) {
                                output[i] = ' ';
                            }
                            i = n - 1;
                            while (i >= 0) {
                                output[n - i - 1] = str[i];
                                i--;
                            }
                            memset(str, 0, 20);
                            outtextxy(10, 25, output);
                            delay(2000);
                        }
                        delay(1000);
                    } else {
                        continue;
                    }
                } else {
                    if (GetAsyncKeyState(VK_LBUTTON)) {
                        GetCursorPos(&cursorposition);
                        x = cursorposition.x - 8;
                        y = cursorposition.y - 30;

                        for (i = 0; i < 5; i++) {
                            if (x > massx[i]) {
                                continue;
                            } else if (x < massx[i]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        for (j = 0; j < 8; j++) {
                            if (y > massy[j]) {
                                continue;
                            } else if (y < massy[j]) {
                                break;
                            } else {
                                break;
                            }
                        }

                        if (i > 0 && i < 4) {
                            switch (j) {
                            case 2:
                                j = 1;
                                break;
                            case 4:
                                j = 3;
                                break;
                            case 6:
                                j = 5;
                                break;
                            case 8:
                                j = 7;
                                break;
                            }
                        }
                        if (j == 7 && i == 2) {
                            i = 1;
                        }
                        position = i * 10 + j;

                        switch (position) {
                        case 11:
                            j1 = 7;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 7;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 7;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '7';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 7;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 21:
                            j1 = 8;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 8;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 8;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '8';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 8;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 31:
                            j1 = 9;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 9;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 9;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '9';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 9;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 41:
                            j1 = 10;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'A';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 42:
                            j1 = 11;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'B';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 13:
                            j1 = 4;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 4;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 4;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '4';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 4;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 23:
                            j1 = 5;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 5;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 5;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '5';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 5;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 33:
                            j1 = 6;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 6;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 6;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '6';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 6;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 43:
                            j1 = 12;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'C';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 44:
                            j1 = 13;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'D';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 15:
                            j1 = 1;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 1;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 1;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '1';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 1;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 25:
                            j1 = 2;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 2;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 2;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '2';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 2;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 35:
                            j1 = 3;
                            if (arrow == 0) {
                                sys1 = (sys1 * 10) + 3;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = (sys2 * 10) + 3;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '3';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = (number * 10) + 3;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 45:
                            j1 = 14;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'E';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 46:
                            j1 = 15;
                            if (arrow > 1) {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = 'F';
                                        i1++;
                                        delay(1000);
                                    } else {
                                        break;
                                    }
                                } else {
                                    break;
                                }
                            } else {
                                break;
                            }
                            break;
                        case 17:
                            j1 = 0;
                            if (arrow == 0) {
                                sys1 = sys1 * 10;
                                delay(1000);
                            } else if (arrow == 1) {
                                sys2 = sys2 * 10;
                                delay(1000);
                            } else {
                                if (j1 < sys1) {
                                    if (sys1 >= 11 && sys1 <= 16) {
                                        str[i1] = '0';
                                        i1++;
                                        delay(1000);
                                    } else if (sys1 >= 2 && sys1 <= 10) {
                                        number = number * 10;
                                        delay(1000);
                                    }
                                } else {
                                    break;
                                }
                            }
                            break;
                        case 37:
                            arrow += 1;
                            delay(1000);
                            break;
                        case 47:
                            buffer = 0;
                            buffer = snprintf(
                                    output,
                                    10,
                                    "%"
                                    "f",
                                    buffer);
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            outtextxy(10, 25, output);
                            sys1 = 0;
                            sys2 = 0;
                            result = 0;
                            arrow = 0;
                            i1 = 0;
                            number = 0;
                            snprintf(
                                    output,
                                    2,
                                    "%"
                                    "d",
                                    Z);
                            memset(str, 0, 20);
                            break;

                        default:
                            continue;
                        }

                        if (arrow == 0) {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = sys1;
                            buffer = snprintf(output, 10, "%f", buffer);
                            outtextxy(10, 25, output);
                            delay(1000);
                        } else if (arrow == 1) {
                            setfillstyle(1, 0);
                            bar(1, 1, 239, 59);
                            buffer = sys2;
                            buffer = snprintf(output, 10, "%f", buffer);
                            outtextxy(10, 25, output);
                            delay(1000);
                        } else {
                            if (sys1 >= 2 && sys1 <= 16 && sys2 >= 2 && sys2 <= 16) {
                                if (sys1 >= 2 && sys1 <= 10) {
                                    setfillstyle(1, 0);
                                    bar(1, 1, 239, 59);
                                    snprintf(output, 10, "%ld", number);
                                    outtextxy(10, 25, output);
                                    snprintf(output, 2, "%d", Z);
                                    delay(1000);
                                } else {
                                    setfillstyle(1, 0);
                                    bar(1, 1, 239, 59);
                                    printf("\n");
                                    outtextxy(10, 25, str);

                                    snprintf(output, 2, "%d", Z);
                                    bar(205, 1, 239, 59);
                                    delay(1000);
                                }

                            } else {
                                outtextxy(10, 25, "Invalid number system!");
                                delay(2000);
                                break;
                            }
                        }
                    }
                }
            }

            closegraph();
            break;

        default:
            printf("Unknown kind of mode!");
            return 0;
        }
    }
    p = fopen("mode.txt", "w");
    putc(ch, p);
    fclose(p);
    system("PAUSE");
    return 0;
}
