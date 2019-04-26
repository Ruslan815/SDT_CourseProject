void menu() {
	setcolor(GREEN);
	setfillstyle(1, 0);
	bar(0, 0, 175, 75);
	rectangle(0, 0, 175, 75);
	line(0, 25, 175, 25);
	line(0, 50, 175, 50);
	settextstyle(2, 0, 6);
	outtextxy(5, 5, "Simple calculator");
	outtextxy(5, 30, "Engineering calculator");
	outtextxy(5, 55, "Calculator of NS");
}
