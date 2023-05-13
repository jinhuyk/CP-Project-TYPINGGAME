#include "header.h"
// all game function write here



void showGame(int level) {
	/*
		TODO:
		게임 진행 함수 순차적으로 나열
	*/
	
	
}

void showSenario(int level) {
	/*
		TODO:
		게임 시작 전, 해당 레벨에 대한 시나리오(설명)

		시나리오 텍스트 출력후

		n초 후 게임 시작할 수 있게 진행.
	*/
}

void showleftTime(int time)
{
	/*
		TODO:
		콘솔에 정해논 좌표에 시간 출력
	*/
}

void showNowLocation(int loc)
{
	/*
		TODO:
		현재 캐릭터의 위치 출력
	*/
}
void showText(int level) {
	/*
		TODO:
		랜덤으로 단어 출력
	*/
}

char* inputText() {
	/*
		TODO:
		단어 입력 후 입력받은 단어 반환
	*/

}
int equalText(char* text) {
	/*
		TODO:
		inputText() 에서 반환받은 문자열과 비교

		같으면 1
		다르면 0

		반환
	*/

}
void processTurn(int eql, int level) {

	/*
	*	TODO:
	*	eql 인자를 통해 텍스트 동일 여부 판단 및, 
	*	level에 맞는 시간 등 업데이트
	*/

}
int isFinish() {
	/*
	* TODO:
	* 시간초과 및 게임 승패여부 변별 
	*/
}