#include "main.h"
#include "cursor.h"
#include "game.h"
#include "menu.h"
#include "showConsole.h"

int main(void) {
	system("mode con: cols=82 lines=22");
	showMenu();
	if (selectMenu() == 0) {
		showLevelMenu();
		showSenario(selectLevel());
	}

	return 0;
}
