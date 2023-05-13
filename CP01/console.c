#include "header.h"

void gotoxy(int x, int y) {
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

COORD getxy() {
	COORD Cur;
	CONSOLE_SCREEN_BUFFER_INFO i;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &i);
	Cur.X = i.dwCursorPosition.X;
	Cur.Y = i.dwCursorPosition.Y;
	return Cur;
}

int selectxy(COORD* locxy,int n) {
	int selectNum;
	int x = getxy().X;
	int y = getxy().Y;
	int eqx, eqy; 

	for (int i = 0; i < n; i++) {
		eqx = locxy[i].X;
		eqy = locxy[i].Y;
		if (x == eqx && y == eqy) {
			return i;
		}
	}
	return 0;
}