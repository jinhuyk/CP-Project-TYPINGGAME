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
	printf("��");
	for (i = 1; i < (x2 - x1) - 1; i++) 
		printf("��");
	printf("��");

	for (i = 1; i < (y2 - y1); i++) {
		gotoxy(x1, y1 + i); 
		printf("��");
		gotoxy(x2 - 1, y1 + i); 
		printf("��");
	}
	gotoxy(x1, y2); 
	printf("��");
	for (i = 1; i < (x2 - x1) - 1; i++) 
		printf("��");
	printf("��");
}

void showMenu() {
	makeBox(0, 0, 80, 20);
	gotoxy(8, 15);
	printf("1. ���� ����");
	gotoxy(34, 15);
	printf("2. ���� °��");
	gotoxy(57, 15);
	printf("3. ������ ����");
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
	printf("1�ܰ� -���а�");
	gotoxy(34, 15);
	printf("2�ܰ� -��õ���");
	gotoxy(57, 15);
	printf("3�ܰ� -�Ű��а�");
}

void showGame(int level) {

}
void showSenario(int level) {
	system("cls");
	makeBox(0, 0, 80, 20);
	if (level == 1) {
		gotoxy(30, 5);
		typingEffect("1�ܰ� ���а�", 100);
		gotoxy(10, 8);
		printf("1���� �����ϱ� 5������ ���а� 1���� �����ߴ�.");
		gotoxy(10, 10);
		printf("���� �ʰ� �ܾ �Է��Ͽ� ����� �ö���");
		gotoxy(10, 12);
		printf("����� �� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����");
		gotoxy(81, 20);

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2�ܰ� ��õ���", 100);
		gotoxy(10, 8);
		printf("3���� �����ϱ� 5������ ��õ��� 1���� �����ߴ�.");
		gotoxy(10, 10);
		printf("�ƴ� ���������� ���� �̷��� ��ٰ�?");
		gotoxy(10, 12);
		printf("������� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����");
		gotoxy(81, 20);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3�ܰ� �Ű��а�", 100);
		gotoxy(10, 8);
		typingEffect("5���� �����ϱ� 5������ �Ű��а� 1���� �����ߴ�.", 70);
		gotoxy(10, 10);
		typingEffect("����? ���������Ͱ� �������̶��?", 70);
		gotoxy(10, 12);
		typingEffect("����� ���� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����", 70);
		gotoxy(81, 20);
	}
	/*
		TODO:
		���� ���� ��, �ش� ������ ���� �ó�����(����)

		�ó����� �ؽ�Ʈ �����

		n�� �� ���� ������ �� �ְ� ����.
	*/
}

void showleftTime(int time)
{
	/*
		TODO:
		�ֿܼ� ���س� ��ǥ�� �ð� ���
	*/
}

void showNowLocation(int loc)
{
	/*
		TODO:
		���� ĳ������ ��ġ ���
	*/
}

void showText(int level,char* text) {
	/*
		TODO:
		�������� �ܾ� ���
	*/
}