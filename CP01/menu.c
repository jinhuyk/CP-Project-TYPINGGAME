#include "menu.h"

int selectMenu() {
	int x = 6, y = 15, ch;

	while(1)
	{

		gotoxy(x, y);
		printf(">");
		ch=_getch();
		if (ch == '\r') {
			break;
		}
		if (ch == 224)
		{
			ch = _getch();
			cursormoving_sound();
			switch(ch)
			{
			case 77:
				if(x==6) x = 29;
				else if(x==29) x = 55;
				break;
			case 75:
				if(x==29) x = 6;
				else if(x==55) x = 29;
				break;				
			}
		}
		printf("\b ");
	}
	
	switch (x)
	{
	case 6: return 0;
	case 29: return 1;
	case 55: return 2;
	}
}


int selectLevel() {
	int level=0;
	int x = 6, y = 15, ch;

	while (1)
	{

		gotoxy(x, y);
		printf(">");
		ch = _getch();
		if (ch == '\r') {
			break;
		}
		if (ch == 224)
		{
			ch = _getch();
			cursormoving_sound();
			switch (ch)
			{
			case 77:
				if (x == 6)
				{
					x = 29;
				}
				else if (x == 29)
				{
					x = 55;
				}
				break;
			case 75:
				if (x == 29)
				{
					x = 6;
				}
				else if (x == 55)
				{
					x = 29;
				}
				break;

			}
		}
		printf("\b ");
	}
	switch (x)
	{
	case 6: return 1;
	case 29: return 2;
	case 55: return 3;
	}
}

