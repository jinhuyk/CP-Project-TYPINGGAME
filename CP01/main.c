#include "main.h"
#include "cursor.h"
#include "game.h"
#include "menu.h"
#include "showConsole.h"

int main(void) {
	int menu;
	int level;
	int location=0;
	int time=0;
	int equal;
	char nowText[100] ="";
	char myText[100]="";
	char key = 0;
	system("mode con: cols=82 lines=22");

	while (1) {
		system("cls");
		
		showMenu();
		menu = selectMenu();
		if (menu == 0) {
			showLevelMenu();
			showSenario(level = selectLevel());
			init(level, &time, &location);
			system("cls");
			makeBox(0, 0, 80, 20);
			
			
			while (1) {
				strcpy_s(myText,100 ,"");
				strcpy_s(nowText, 100, makeText(level));
				inputText(myText,nowText, &time,&location);
				equal = isTextEqual(myText, nowText);
				processTurn(equal, level, &time, &location);
			}
		}
		else if (menu == 1) {
			return 0;
		}
		else if (menu == 2) {
			showDeveloper();
		}
	}
}
