#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "showConsole.h"
#include "cursor.h"
#include "menu.h"

void makeBox(int x1, int y1, int x2, int y2) {
	int i;
	gotoxy(x1, y1); 
	printf("┌");
	for (i = 1; i < (x2 - x1) - 1; i++) 
		printf("─");
	printf("┐");

	for (i = 1; i < (y2 - y1); i++) {
		gotoxy(x1, y1 + i); 
		printf("│");
		gotoxy(x2 - 1, y1 + i); 
		printf("│");
	}
	gotoxy(x1, y2); 
	printf("└");
	for (i = 1; i < (x2 - x1) - 1; i++) 
		printf("─");
	printf("┘");
}

void showMenu() {
	makeBox(0, 0, 80, 20);
	gotoxy(8, 15);
	printf("1. 수업 가기");
	gotoxy(34, 15);
	printf("2. 수업 째기");
	gotoxy(57, 15);
	printf("3. 개발자 보기");
	gotoxy(81, 20);

}

void typingEffect(char* str, int delay) {
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		printf("%c", str[i]);
		Sleep(delay); 
	}
}

void showLevelMenu() {
	system("cls");
	makeBox(0, 0, 80, 20);
	gotoxy(8, 15);
	printf("1단계 -공학관");
	gotoxy(34, 15);
	printf("2단계 -새천년관");
	gotoxy(57, 15);
	printf("3단계 -신공학관");
}

void showGame(int level) {

}
void showSenario(int level) {
	system("cls");
	makeBox(0, 0, 80, 20);
	if (level == 1) {
		gotoxy(30, 5);
		typingEffect("1단계 공학관", 100);
		gotoxy(10, 8);
		printf("1교시 시작하기 5분전에 공학관 1층에 도착했다.");
		gotoxy(10, 10);
		printf("늦지 않게 단어를 입력하여 계단을 올라가자");
		gotoxy(10, 12);
		printf("계단을 다 올라가서 제한시간안에 출석번호를 입력하자");
		gotoxy(81, 20);

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2단계 새천년관", 100);
		gotoxy(10, 8);
		printf("3교시 시작하기 5분전에 새천년관 1층에 도착했다.");
		gotoxy(10, 10);
		printf("아니 엘리베이터 줄이 이렇게 길다고?");
		gotoxy(10, 12);
		printf("계단으로 올라가서 제한시간안에 출석번호를 입력하자");
		gotoxy(81, 20);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3단계 신공학관", 100);
		gotoxy(10, 8);
		typingEffect("5교시 시작하기 5분전에 신공학관 1층에 도착했다.", 70);
		gotoxy(10, 10);
		typingEffect("뭐야? 엘리베이터가 수리중이라고?", 70);
		gotoxy(10, 12);
		typingEffect("계단을 빨리 올라가서 제한시간안에 출석번호를 입력하자", 70);
		gotoxy(81, 20);
	}
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

void showText(int level,char* text) {
	/*
		TODO:
		랜덤으로 단어 출력
	*/
}