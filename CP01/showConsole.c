﻿#include "showConsole.h"


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
	system("cls");
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
	printf("1단계 - 공학관");
	gotoxy(34, 15);
	printf("2단계 - 새천년관");
	gotoxy(57, 15);
	printf("3단계 - 신공학관");
}

void showDeveloper() {
	system("cls");
	makeBox(0, 0, 80, 20);
	gotoxy(30, 5);
	printf("개발자 정보");
	gotoxy(10, 8);
	typingEffect("컴퓨터 공학부 202210748 문진혁", 50);
	gotoxy(10, 10);
	typingEffect("컴퓨터 공학부 202111256 김석진", 50);
	gotoxy(10, 12);
	typingEffect("컴퓨터 공학부 202311262 김민규", 50);
	gotoxy(10, 14);
	typingEffect("컴퓨터 공학부 202311302 변수혁", 50);
	gotoxy(10, 16);
	typingEffect("KONKUK Univ. CSE, C-Programming Team 01", 100);
	gotoxy(10,18);
	system("pause");

}

void showSenario(int level) {
	system("cls");
	makeBox(0, 0, 80, 20);
	if (level == 1) {
		gotoxy(30, 5);
		typingEffect("1단계 공학관",70);
		gotoxy(10, 8);
		typingEffect("1교시 시작하기 5분전에 공학관 1층에 도착했다.",50);
		gotoxy(10, 10);
		typingEffect("늦지 않게 단어를 입력하여 계단을 올라가자",50);
		gotoxy(10, 12);
		typingEffect("계단을 다 올라가서 제한시간안에 출석번호를 입력하자",50);

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2단계 새천년관", 70);
		gotoxy(10, 8);
		typingEffect("3교시 시작하기 5분전에 새천년관 1층에 도착했다.",50);
		gotoxy(10, 10);
		typingEffect("아니 엘리베이터 줄이 이렇게 길다고?",50);
		gotoxy(10, 12);
		typingEffect("계단으로 올라가서 제한시간안에 출석번호를 입력하자",50);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3단계 신공학관", 70);
		gotoxy(10, 8);
		typingEffect("5교시 시작하기 5분전에 신공학관 1층에 도착했다.", 50);
		gotoxy(10, 10);
		typingEffect("뭐야? 엘리베이터가 수리중이라고?", 50);
		gotoxy(10, 12);
		typingEffect("계단을 빨리 올라가서 제한시간안에 출석번호를 입력하자", 50);
	}
	//showLoadingBar 구현되면 그것과 교체
	gotoxy(10,14);
	system("pause");
	gotoxy(81,20);
}

void showleftTime(int time)
{	
	gotoxy(5, 2); 
	printf("남은 시간: %d초\n", time); 

}

void showNowLocation(int loc)
{
	loc = loc / 10;
		// 좌하단 언더바
		gotoxy(24, 13);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		printf("__________");

		// 중앙 언더바
		gotoxy(34, 11);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		printf("__________");

		// 우상단 언더바
		gotoxy(44, 9);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // 하얀색
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // 파란색
		}
		printf("__________");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}


//TODO: 사람 위치 조정해야함
void showPerson(int e) {
	if (e % 2 == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 하얀색
		gotoxy(34, 8);
		printf("\\ O /");
		gotoxy(34, 9);
		printf("   |   ");
		gotoxy(34, 10);
		printf("/ \\");
	}
	// 사람 손 아래로 내리기
	else {
		// 사람 손 위로 올리기
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // 하얀색
		gotoxy(34, 8);
		printf("  O  ");
		gotoxy(34, 9);
		printf(" / | \\");
		gotoxy(34, 10);
		printf("/ \\");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void showText(char* text) {
	gotoxy(25, 4);
	printf("제시어: %s", text);
}
void showMyText(char* text) {
	makeBox(18, 15, 62, 17);
	gotoxy(20, 16);
	printf("%s", text);
}

void clearText() {
	gotoxy(20, 16);
	for (int i = 0; i < 20; i++) {
		printf(" ");
	}
}

//TODO: 위치 조정해야함
void showFinish(int isFinish) {
	system("cls");
	makeBox(0, 0, 80, 20);
	gotoxy(25, 4);
	if(isFinish == 0) // 실패
	{
		printf("지각이다..."); 
	}
	else
		printf("정상 출석 완료! 늦지않고 잘 도착했다!");
	showSmile(25, 6);
	
	Sleep(2000);
}
void showSmile(int x, int y) {
	gotoxy(x, y++);
	printf("░░░░░░░░░░░▒▒▒▒░░░░░░░░░░\n");
	gotoxy(x, y++);
	printf("░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░\n");
	gotoxy(x, y++);
	printf("░░░▒▒▒▒▒▒▓▒▒▒▒▒▓▓▒▒▒▒▒░░░\n");
	gotoxy(x, y++);
	printf("░░▒▒▒▒▒▒██▓▒▒▒▓██▒▒▒▒▒▒░░\n");
	gotoxy(x, y++);
	printf("░▒▒▒▒▒▒▒██▓▒▒▒▓██▒▒▒▒▒▒▒░\n");
	gotoxy(x, y++);
	printf("▒▒▒▒▒▒▒▒▓█▒▒▒▒▒█▓▒▒▒▒▒▒▒▒\n");
	gotoxy(x, y++);
	printf("▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒\n");
	gotoxy(x, y++);
	printf("▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒\n");
	gotoxy(x, y++);
	printf("░▒▒▒▒▓▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒░\n");
	gotoxy(x, y++);
	printf("░░▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒░░\n");
	gotoxy(x, y++);
	printf("░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▒▒▒▒▒▒░░░\n");
	gotoxy(x, y++);
	printf("░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░\n");
}

void showLocation(int totalLocation, int nowLocation) {
	gotoxy(5, 3);
	printf("남은 계단 수: %d", totalLocation-nowLocation);
}

/*
void showLoadingBar() {
	int progress;

	for (progress = 0; progress <= 100; progress += 5) {
		int i;
		printf("Progress: [");
		for (i = 0; i < progress / 5; i++) {
			printf("#");
		}
		for (i = progress / 5; i < 20; i++) {
			printf(" ");
		}
		printf("] %d%%\r", progress);
		fflush(stdout);
		Sleep(150);
	}

	printf("\nLoading Complete!\n");
}
*/