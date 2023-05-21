#include "main.h"
#include "menu.h"
#include "cursor.h"


int selectMenu() {
	COORD menuItem[] = { {6,15},{32,15},{55,15} };
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
			switch(ch)
			{
			case 77:
				if(x==6)
				{
					x = 32;
				}
				else if(x==32)
				{
					x = 55;
				}
				break;
			case 75:
				if(x==32)
				{
					x = 6;
				}
				else if(x==55)
				{
					x = 32;
				}
				break;				

			}
		}
		printf("\b ");
	}
	
	switch (x)
	{
	case 6:
		return 0;
	case 32:
		return 1;
	case 55:
		return 2;
	}
}
int selectLevel() {
	int level=0;
	COORD menuItem[] = { {6,15},{32,15},{55,15} };
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
			switch (ch)
			{
			case 77:
				if (x == 6)
				{
					x = 32;
				}
				else if (x == 32)
				{
					x = 55;
				}
				break;
			case 75:
				if (x == 32)
				{
					x = 6;
				}
				else if (x == 55)
				{
					x = 32;
				}
				break;

			}
		}
		printf("\b ");
	}
	switch (x)
	{
	case 6:
		level = 1;
		break;
	case 32:
		level = 2;
		break;
	case 75:
		level = 3;
		break;
	}
	return level;
}