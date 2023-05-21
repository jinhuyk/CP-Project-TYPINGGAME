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

void inputText(char* text, int time) {
	char key = 0;
	while (1) {

		if (_kbhit() != NULL)
		{
			key = _getch();
			if (key == '\r') {
				break;
			}
			append(text, key);
			showMyText(text);
		}
		Sleep(10);
		if (time % 100 == 0)
		{
			if (time / 100 < 0)
			{
				printf("게임 끝. ");
				break;
			}
			system("cls");
			showMyText(text);
		}
		time--;
	}
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
void processTurn(int eql, int level,int time, int location) {

	/*
	*	TODO:
	*	eql 인자를 통해 텍스트 동일 여부 판단 및, 
	*	level에 맞는 시간 등 업데이트
	*   location -> 계단 수
	*/
	if (eql == 1)
	{
		location = location + 10;
	}
	
}

int location2score(int level, int location){
	/*
	계단 수에 따라서 스코어 점수 계산
	level 1 -> 총 100칸
	level 2 -> 총 200칸
	level 3 -> 총 300칸
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