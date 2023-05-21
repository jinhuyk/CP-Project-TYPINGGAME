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

void append(char* text, char c) {
	char* p = text;
	while (*p != '\0') p++;
	*p = c;
	*(p + 1) = '\0';
}

void init(int level, int* time, int* location) {
	*time = 1000;
	*location = 0;
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

void inputText(char* myText,char* nowText, int* time,int* location) {
	int t = *time;
	char key = 0;
	while (1) {
		if (_kbhit() != NULL)
		{
			key = _getch();
			if (key == '\r') {
				break;
			}
			append(myText, key);
			showMyText(myText);
		}
		Sleep(10);
		if (t % 100 == 0)
		{
			if (t/ 100 < 0)
			{
				break;
			}
			system("cls");
			makeBox(0, 0, 80, 20);
			showleftTime(t);
			showText(0, nowText);
			showNowLocation(*location);
			showMyText(myText);
			
		}
		t--;
	}
	*time = t;
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
	
}

int location2score(int level, int location){
	/*
	��� ���� ���� ���ھ� ���� ���
	level 1 -> �� 100ĭ
	level 2 -> �� 200ĭ
	level 3 -> �� 300ĭ
	*/
	int totalLocation;
	if (level == 1)
	{
		totalLocation=100;
	}
	else if (level == 2)
	{
		totalLocation = 200;
	}
	else if (level == 3)
	{
		totalLocation=300;
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