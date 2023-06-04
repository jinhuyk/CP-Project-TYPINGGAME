#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "game.h"


int main(void) {
	srand((unsigned int)time(NULL));
	system("mode con: cols=82 lines=22");
	menu();
	return 0;
}
