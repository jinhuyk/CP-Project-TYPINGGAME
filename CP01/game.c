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
		�ܾ� �Է� �� �Է¹��� �ܾ� ��ȯ
	*/
	return text;
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
void processTurn(int eql, int level) {

	/*
	*	TODO:
	*	eql ���ڸ� ���� �ؽ�Ʈ ���� ���� �Ǵ� ��, 
	*	level�� �´� �ð� �� ������Ʈ
	*/

}
int isFinish(int score) {
	int isFinish=0;
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
	return isFinish;
}