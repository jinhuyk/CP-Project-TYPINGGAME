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

int *wordLevel1Check;

int *wordLevel2Check;

int *wordLevel3Check;


void next(int level, int rst) {
	int menu;
	showFinish(rst);
	free(wordLevel1Check);
	free(wordLevel2Check);
	free(wordLevel3Check);
	menu = selectLevel();
	if (menu == 1) game(level);
	else if (menu == 2) {
		game((level==3)?level:level+1);
	}
	else return;
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
		wordLevel1Check = (int*)calloc(25, sizeof(int));
	}

	else if (level == 2) {
		*time = 100;
		*location = 0;
		wordLevel2Check = (int*)calloc(19, sizeof(int));
	}

	else if (level == 3) {
		*time = 100;
		*location = 0;
		wordLevel3Check = (int*)calloc(20, sizeof(int));
	}
}

void stringInit(char* str, int len) {
	for (int i = 0; i < len; i++) {
		str[i] = '\0';
	}
}



void game(int isContinue) {
	int level = 0, location = 0, stime = 0, equal = 0;
	int state = 0;
	int item = 0;
	char nowText[100] = "";
	char myText[100] = "";
	char key = 0;
	
	if (isContinue == 0) {
		showLevelMenu();
		showSenario(level = selectLevel());
	}
	else {
		level = isContinue;
		showSenario(level);
	}
	init(level, &stime, &location);
	system("cls");
	makeBox(0, 0, 80, 20);
	init(level, &stime, &location);
	system("cls");
	makeBox(0, 0, 80, 20);
	starting_sound();

	while (stime >= 0) {

		equal = 0;
		item = rand() % 10;
		if ((item == 2  || item ==3) && stime > 30) {
			item = 1;
		}
		if (item >= 4) item = 0;
		if (isFinish(location2score(level, location), stime)) {
			sprintf(nowText, "%d", makeFinishCode());
			while (1)
			{
				stringInit(myText, 100);
				inputText(myText, nowText, &stime, &location, level, 1,state,0);
				equal = isTextEqual(myText, nowText);
				if (equal == 1) break;
			}
			break;
		}
		stringInit(myText, 100);
		strcpy_s(nowText, 100, makeText(level));
		inputText(myText, nowText, &stime, &location, level , 0,state,item);
		equal = isTextEqual(myText, nowText);
		processTurn(equal, level, &stime, &location,&state,item);
	}
	next(level, equal);
	
}


char* makeText(int level) {
	char* text = "";
	int index = 0;
	switch (level) {
	case 1:
		do {
			index = rand() % 25;
		} while (wordLevel1Check[index] != 0);
		wordLevel1Check[index] = 1;
		text = wordLevel1[index];
		break;

	case 2:
		do {
			index = rand() % 19;
		} while (wordLevel2Check[index] != 0);
		wordLevel2Check[index] = 1;
		text = wordLevel2[index];
		break;
	case 3:
		do {
			index = rand() % 20;
		} while (wordLevel3Check[index] != 0);
		wordLevel3Check[index] = 1;
		text = wordLevel3[index];
		break;
	}
	return text;
}


void inputText(char* myText,char* nowText, int* stime,int* location, int level, int isCode, int state,int item) {
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
			showPerson(state);
			showleftTime(t,level);
			showText(nowText, isCode, item);
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
void processTurn(int eql, int level,int* time, int* location,int* state, int item) {
	if (eql == 1)
	{
		showItem(item);
		if (item == 1) {
			*location = *location + 10;
		}
		else if(item == 2) {
			*time = *time + 10;
		}

		else if (item == 3){
			*location = *location + 10;
			*time = *time + 10;
		}
		*location = *location + 10;
		*state = 0;
		answer_sound();
	}
	else {
		*time = *time - 10;
		*state = 1;
		wrong_sound();
	}
	if(*location < 0)
		*location = 0;
}

int location2score(int level, int location){
	return((int)(location * (100.0 / getTotalLocation(level))));
	
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