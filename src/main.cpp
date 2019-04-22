#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
	bool flag = 1;
	int mode, code;
	char ch;
	POINT cursorPosition;
	FILE *p;

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

	initwindow(250, 300);
	while (flag == 1) {
		switch (mode) {
			case 1:
				code = 1;
				while (code == 1) {
					code = getch();
				}
				if (code == 27) {
					ch = '1';
					flag = 0;
					closegraph();
					break;
				} else if (code == 49) {
					break;
				}
				break;
			case 2:
				code = 1;
				while (code == 1) {
					code = getch();
				}
				if (code == 27) {
					ch = '2';
					flag = 0;
					closegraph();
					break;
				} else if (code == 49) {
					break;
				}
				break;
			case 3:
				code = 1;
				while (code == 1) {
					code = getch();
				}
				if (code == 27) {
					ch = '3';
					flag = 0;
					closegraph();
					break;
				} else if (code == 49) {
					break;
				}
				break;
			default:
				return 0;
		}
	}

	p = fopen("mode.txt", "w");
	putc(ch, p);
	fclose(p);
	free(p);
	return 0;
}
