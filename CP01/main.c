#include "main.h"
#include "cursor.h"
#include "game.h"
#include "menu.h"
#include "showConsole.h"

int main(void) {
	int menu;


	system("mode con: cols=82 lines=22");
	showMenu();
	menu = selectMenu();
	if (menu == 0) {
		showLevelMenu();
		showSenario(selectLevel());
	}
	else if (menu == 1) {
		return 0;
	}
	else if (menu == 2) {
		showDeveloper();
	}

	return 0;
}
