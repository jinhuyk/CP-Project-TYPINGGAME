#include "main.h"
#include "game.h"
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

char* inputText() {
	char text[] = "";
	/*
		TODO:
		단어 입력 후 입력받은 단어 반환
	*/
	return text;
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
void processTurn(int eql, int level) {

	/*
	*	TODO:
	*	eql 인자를 통해 텍스트 동일 여부 판단 및, 
	*	level에 맞는 시간 등 업데이트
	*/

}
int isFinish(int score) {
	int isFinish=0;
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
	return isFinish;
}