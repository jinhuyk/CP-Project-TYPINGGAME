#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

#define MAX_SCORE 100

char wordLevel1[][100] = {
	"printf", "scanf", "overflow", "kilo", "giga", "mega", "static", "hello-world", "switch", "while", "float", "include", "return", "extern", "break", "default", "rand", "define", "download", "program", "cloud", "request", "compile", "object", "monitor", "class"
};

char wordLevel2[][100] = {
		"register", "flash-drive", "ROTATE", "SHIFT", "memory", "process", "refactor", "argument", "parameter", "query", "gateway", "terminal", "buffering", "pipeline", "instructions", "processor", "iterator", "frame", "cache", "exception"
};

char wordLevel3[][100] = {
	"program-counter", "operating-system", "lab-assignment", "programming-practice", "instruction-set-architectures", "parallelism", "multiflexer", "memory", "unsigned-integer", "data-segment-pointer", "pseudodirect-addressing", "base-addressing", "assembly", "pseudoinstruction", "artificial-intelligence",
	"buffering", "flash-drive", "pipeline", "processor", "iterator"
};


void next(int level) {

}
void menu() {
	int menu;

	while (1) {
			showMenu();
	menu = selectMenu();
	if (menu == 0) {
		game(0);
	}
	else if (menu == 1) {
		system("cls");
		exit(0);
	}
	else if (menu == 2) {
		showDeveloper();
	}
	}

}

void init(int level, int* time, int* location) {
	if (level == 1) {
		*time = 100;
		*location = 0;
	}

	else if (level == 2) {
		*time = 80;
		*location = 0;
	}

	else if (level == 3) {
		*time = 60;
		*location = 0;
	}
}

void stringInit(char* str, int len) {
	for (int i = 0; i < len; i++) {
		str[i] = '\0';
	}
}



void game(int isContinue) {
	int level = 1, location = 0, stime = 0, equal = 0;
	char nowText[100] = "";
	char myText[100] = "";
	char key = 0;

	if (isContinue == 0) {
		showLevelMenu();
		showSenario(level = selectLevel());
	}
	else {
		level = isContinue;
	}
	init(level, &stime, &location);
	system("cls");
	makeBox(0, 0, 80, 20);
	init(level, &stime, &location);
	system("cls");
	makeBox(0, 0, 80, 20);


	while (stime >= 0) {
		equal = 0;
		if (isFinish(location2score(level, location), stime)) {
			sprintf(nowText, "%d", makeFinishCode());
			while (1)
			{
				stringInit(myText, 100);
				
				inputText(myText, nowText, &stime, &location, level, 1);
				equal = isTextEqual(myText, nowText);
				if (equal == 1) break;
			}
			showFinish(equal);
			return;
		}
		stringInit(myText, 100);
		strcpy_s(nowText, 100, makeText(level));
		inputText(myText, nowText, &stime, &location, level , 0);
		equal = isTextEqual(myText, nowText);
		processTurn(equal, level, &stime, &location);
	}
	showFinish(equal);
}


char* makeText(int level) {
	char* text ="";
	switch (level) {
	case 1:
		text = wordLevel1[rand() % 25];
		break;
	case 2:
		text = wordLevel2[rand() % 19];
		break;
	case 3:
		text = wordLevel3[rand() % 20];
		break;
	}
	return text;
}

void inputText(char* myText,char* nowText, int* stime,int* location, int level, int isCode) {
	int t = *stime;
	int nowTime = 5;
	char key = 0;
	int pos = 0;
	int s_time = time(0);

	if (isCode) nowTime = t;
	while (1) {
		if (nowTime <= 0 || t  <= 0) {
			break;
		}
		if (_kbhit())
		{
			key = _getch();
			if (key == '\r') {
				gotoxy(0, 0);
				printf("Enter!");
				break;
			}
			else if (key == '\b') {
				if (pos > 0) {
					pos--;
					myText[pos] = '\0';
				}
			}
			else {
				myText[pos] = key;
				pos++;
			}
			clearText();
			showMyText(myText);

			
		}
		if (time(0) - s_time >= 1) {
			s_time = time(0);
			t-=1;
			nowTime-=1;
			system("cls");
			makeBox(0, 0, 80, 20);

			showleftTime(t);
			showText(nowText);
			showNowLocation(*location);
			showLocation(getTotalLocation(level),*location);
			showMyText(myText);
		}
		
	}
	*stime = t;
}
int isTextEqual(char* text, char* correctText) {
	int result = strcmp(text, correctText);
	if (result == 0)
		result = 1;
	else
		result = 0;
	
	return result;
}
void processTurn(int eql, int level,int* time, int* location) {
	if (eql == 1)
	{
		*location = *location + 10;
	}
	else {
		*time = *time - 10;
	}
	
}

int location2score(int level, int location){
	return(location * (100 / getTotalLocation(level)));
	
}

int isFinish(int score, int time) {
	int isFinish=0;
	if((score >= 100) && (time > 0)) // 100점 이상이면 승리 or 남은시간 0초 이상이면 승리
	{
		isFinish = 1;
		return isFinish;
	}
	else return isFinish;

}

int makeFinishCode() {
 int code;
 code = rand() % 900 + 100;
 return code;
}

int getTotalLocation(int level) {
	if (level == 1)
		return 100;
	else if (level == 2)
		return 150;
	else if (level == 3)
		return 200;
	return 0;
}