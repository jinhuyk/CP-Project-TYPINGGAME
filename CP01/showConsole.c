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

void showDeveloper() {
	system("cls");
	makeBox(0, 0, 80, 20);
	gotoxy(30, 5);
	printf("������ ����");
	gotoxy(10, 8);
	typingEffect("��ǻ�� ���к� 202210748 ������", 50);
	gotoxy(10, 10);
	typingEffect("��ǻ�� ���к� 202111256 �輮��", 50);
	gotoxy(10, 12);
	typingEffect("��ǻ�� ���к� 202311262 ��α�", 50);
	gotoxy(10, 14);
	typingEffect("��ǻ�� ���к� 202311302 ������", 50);
	gotoxy(10, 16);
	typingEffect("KONKUK Univ. Computer Science & Engineering, C-Programming Team", 100);
	gotoxy(10, 17);
	printf("5�� �� �������� ���ư��ϴ�...");
	Sleep(5000);

}

void showGame(int level) {

}
void showSenario(int level) {
	system("cls");
	makeBox(0, 0, 80, 20);
	if (level == 1) {
		gotoxy(30, 5);
		typingEffect("1�ܰ� ���а�",70);
		gotoxy(10, 8);
		typingEffect("1���� �����ϱ� 5������ ���а� 1���� �����ߴ�.",50);
		gotoxy(10, 10);
		typingEffect("���� �ʰ� �ܾ �Է��Ͽ� ����� �ö���",50);
		gotoxy(10, 12);
		typingEffect("����� �� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����",50);
		gotoxy(10, 14);
		printf("3�� �� �����մϴ�...");

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2�ܰ� ��õ���", 70);
		gotoxy(10, 8);
		typingEffect("3���� �����ϱ� 5������ ��õ��� 1���� �����ߴ�.",50);
		gotoxy(10, 10);
		typingEffect("�ƴ� ���������� ���� �̷��� ��ٰ�?",50);
		gotoxy(10, 12);
		typingEffect("������� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����",50);
		gotoxy(81, 20);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3�ܰ� �Ű��а�", 70);
		gotoxy(10, 8);
		typingEffect("5���� �����ϱ� 5������ �Ű��а� 1���� �����ߴ�.", 50);
		gotoxy(10, 10);
		typingEffect("����? ���������Ͱ� �������̶��?", 50);
		gotoxy(10, 12);
		typingEffect("����� ���� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����", 50);
		gotoxy(81, 20);
	}
	Sleep(3000);
}

void showleftTime(int time)
{	
	gotoxy(5, 2); // ��ǥ ���� ���� �ʿ�
	printf("���� �ð�: %d��\n", time/100); // �ð����
	/*
		TODO:
		�ֿܼ� ���س� ��ǥ�� �ð� ��� 
	*/
}

void showNowLocation(int loc)
{
	loc = loc / 10;
		// ���ϴ� �����
		gotoxy(24, 13);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		printf("__________");

		// �߾� �����
		gotoxy(34, 11);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		printf("__________");

		// ���� �����
		gotoxy(44, 9);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		printf("__________");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

}

void showPerson(int e) {
	if (e % 2 == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �Ͼ��
		gotoxy(34, 8);
		printf("\\ O /");
		gotoxy(34, 9);
		printf("   |   ");
		gotoxy(34, 10);
		printf("/ \\");
	}
	// ��� �� �Ʒ��� ������
	else {
		// ��� �� ���� �ø���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �Ͼ��
		gotoxy(34, 8);
		printf("  O  ");
		gotoxy(34, 9);
		printf(" / | \\");
		gotoxy(34, 10);
		printf("/ \\");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void showText(int level,char* text) {
	/*
		TODO:
		�������� �ܾ� ���
	*/
	
	gotoxy(25, 4);
	printf("���þ�: %s", text);
}
void showMyText(char* text) {
	makeBox(18, 15, 62, 17);
	gotoxy(20, 16);
	printf("%s", text);
}

void showFinish(int isFinish) {
	if(isFinish == 0) // ����
	{
		printf("�����̴�..."); 
	}
	else // ����
		printf("���� �⼮ �Ϸ�! �����ʰ� �� �����ߴ�!");
}