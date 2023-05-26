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
		TODO: 김석진
		inputText() 에서 반환받은 문자열과 비교

		같으면 1
		다르면 0

		반환
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
	*	eql 인자를 통해 텍스트 동일 여부 판단 및, 
	*	level에 맞는 시간 등 업데이트
	*   location -> 계단 수
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
	계단 수에 따라서 스코어 점수 계산
	level 1 -> 총 100칸
	level 2 -> 총 150칸
	level 3 -> 총 200칸
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
	if((score >= 100) || (time > 0)) // 100점 이상이면 승리 or 남은시간 0초 이상이면 승리
	{
		isFinish = 1;
		return isFinish;
	}
	else // 100점이상 or 남은시간 0초이상 에 해당하지 않는 경우
		return isFinish; // isFinish 가 0 반환
	/*
	* TODO: 
	* 시간초과 및 게임 승패여부 변별 
	* 
	* time 이용하여 시간 초과 판단,
	* 
	* score 과 MAX_SCORE 비교하여 점수 판단,
	* 
	* lose : 0
	* win : 1
	* 
	* isFinish를 반환
	*/
}

int makeFinishCode() {
 int code;
 srand((unsigned)time(NULL));
 code = rand() % 900 + 100; // (0부터 899까지 생성된 나머지 + 100) = 100 부터 999까지 랜덤하게 생성
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