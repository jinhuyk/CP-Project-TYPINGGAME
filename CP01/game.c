#include "main.h"
#include "game.h"
#include "showConsole.h"
#include <string.h>
// all game function write here

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



void init(int level, int* time, int* location) {
	if (level == 1) {
		*time = 10000;
		*location = 0;
	}

	else if (level == 2) {
		*time = 8000;
		*location = 0;
	}

	else if (level == 3) {
		*time = 6000;
		*location = 0;
	}
}

void stringInit(char* str, int len) {
	for (int i = 0; i < len; i++) {
		str[i] = '\0';
	}
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

void inputText(char* myText,char* nowText, int* stime,int* location) {
	int t = *stime;
	int nowTime = 500;
	char key = 0;
	int pos = 0;
	int s_time = time(0);
	while (1) {
		if (nowTime / 100 < 0 || t / 100 < 0) {
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
			t-=100;
			nowTime-=100;
			system("cls");
			makeBox(0, 0, 80, 20);

			showleftTime(t);
			showText(0, nowText);
			showNowLocation(*location);
			showMyText(myText);
		}
		
	}
	*stime = t;
}
int isTextEqual(char* text, char* correctText) {
	/*
		TODO: �輮��
		inputText() ���� ��ȯ���� ���ڿ��� ��

		������ 1
		�ٸ��� 0

		��ȯ
	*/
	int result = strcmp(text, correctText);
	if (result == 0)
		result = 1;
	else
		result = 0;
	
	return result;
}
void processTurn(int eql, int level,int* time, int* location) {

	/*
	*	TODO:
	*	eql ���ڸ� ���� �ؽ�Ʈ ���� ���� �Ǵ� ��, 
	*	level�� �´� �ð� �� ������Ʈ
	*   location -> ��� ��
	*/
	if (eql == 1)
	{
		*location = *location + 10;
	}
	else {
		*time = *time - 1000;
	}
	
}

int location2score(int level, int location){
	/*
	��� ���� ���� ���ھ� ���� ���
	level 1 -> �� 100ĭ
	level 2 -> �� 150ĭ
	level 3 -> �� 200ĭ
	*/
	int totalLocation;
	if (level == 1)
	{
		totalLocation=100;
	}
	else if (level == 2)
	{
		totalLocation = 150;
	}
	else if (level == 3)
	{
		totalLocation=200;
	}
	return(location * (100 / totalLocation));
	
}

int isFinish(int score, int time) {
	int isFinish=0;
	if((score >= 100) || (time > 0)) // 100�� �̻��̸� �¸� or �����ð� 0�� �̻��̸� �¸�
	{
		isFinish = 1;
		return isFinish;
	}
	else // 100���̻� or �����ð� 0���̻� �� �ش����� �ʴ� ���
		return isFinish; // isFinish �� 0 ��ȯ
	/*
	* TODO: 
	* �ð��ʰ� �� ���� ���п��� ���� 
	* 
	* time �̿��Ͽ� �ð� �ʰ� �Ǵ�,
	* 
	* score �� MAX_SCORE ���Ͽ� ���� �Ǵ�,
	* 
	* lose : 0
	* win : 1
	* 
	* isFinish�� ��ȯ
	*/
}

int makeFinishCode() {
 int code;
 srand((unsigned)time(NULL));
 code = rand() % 900 + 100; // (0���� 899���� ������ ������ + 100) = 100 ���� 999���� �����ϰ� ����
 return code;
}

int getTotalLocation(level) {
	if (level == 1)
		return 100;
	else if (level == 2)
		return 150;
	else if (level == 3)
		return 200;
}