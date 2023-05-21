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

void showDeveloper() {
	system("cls");
	makeBox(0, 0, 80, 20);
	gotoxy(30, 5);
	typingEffect("개발자 정보", 100);
	gotoxy(10, 8);
	typingEffect("컴퓨터 공학부 202210748 문진혁", 100);
	gotoxy(10, 10);
	typingEffect("컴퓨터 공학부 202111256 김석진", 100);
	gotoxy(10, 12);
	typingEffect("컴퓨터 공학부 202311262 김민규", 100);
	gotoxy(10, 14);
	typingEffect("컴퓨터 공학부 202311302 변수혁", 100);
	gotoxy(10, 16);
	typingEffect("KONKUK Univ. Computer Science & Engineering, C-Programming Team Project 01 Team", 100);
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
		typingEffect("1교시 시작하기 5분전에 공학관 1층에 도착했다.",100);
		gotoxy(10, 10);
		typingEffect("늦지 않게 단어를 입력하여 계단을 올라가자",100);
		gotoxy(10, 12);
		typingEffect("계단을 다 올라가서 제한시간안에 출석번호를 입력하자",100);
		gotoxy(81, 20);

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2단계 새천년관", 100);
		gotoxy(10, 8);
		typingEffect("3교시 시작하기 5분전에 새천년관 1층에 도착했다.",100);
		gotoxy(10, 10);
		typingEffect("아니 엘리베이터 줄이 이렇게 길다고?",100);
		gotoxy(10, 12);
		typingEffect("계단으로 올라가서 제한시간안에 출석번호를 입력하자",100);
		gotoxy(81, 20);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3단계 신공학관", 100);
		gotoxy(10, 8);
		typingEffect("5교시 시작하기 5분전에 신공학관 1층에 도착했다.", 100);
		gotoxy(10, 10);
		typingEffect("뭐야? 엘리베이터가 수리중이라고?", 100);
		gotoxy(10, 12);
		typingEffect("계단을 빨리 올라가서 제한시간안에 출석번호를 입력하자", 100);
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
	gotoxy(0, 0); // 좌표 추후 수정 필요
	printf("%d\n", time); // 시간출력
	/*
		TODO:
		콘솔에 정해논 좌표에 시간 출력 
	*/
}

void showNowLocation(int loc)
{

		// 좌하단 언더바
		gotoxy(20, 17);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		printf("__________");

		// 중앙 언더바
		gotoxy(40, 13);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		printf("__________");

		// 우상단 언더바
		gotoxy(60, 9);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		printf("__________");

}

void showPerson(int e) {
	// 사람 손 아래로 내리기
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 하얀색
	gotoxy(22, 14);
	printf("\\ O /");
	gotoxy(22, 15);
	printf("  |   ");
	gotoxy(23, 16);
	printf("/ \\");

	Sleep(500); // 0.5초 대기

	// 사람 손 위로 올리기
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 하얀색
	gotoxy(22, 14);
	printf("  O  ");
	gotoxy(22, 15);
	printf("/ | \\");
	gotoxy(23, 16);
	printf("/ \\");
	Sleep(500); // 0.5초 대기
}

void showText(int level,char* text) {
	/*
		TODO:
		랜덤으로 단어 출력
	*/
	
	gotoxy(34, 17);
	printf("%s", text);
}
void showMyText(char* text) {
	gotoxy(34, 19);
	printf("%s", text);
}

void showFinish(int isFinish) {
	if(isFinish == 0) // 실패
	{
		printf("지각이다..."); 
	}
	else // 성공
		printf("정상 출석 완료! 늦지않고 잘 도착했다!");
}