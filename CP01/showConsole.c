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
	typingEffect("������ ����", 100);
	gotoxy(10, 8);
	typingEffect("��ǻ�� ���к� 202210748 ������", 100);
	gotoxy(10, 10);
	typingEffect("��ǻ�� ���к� 202111256 �輮��", 100);
	gotoxy(10, 12);
	typingEffect("��ǻ�� ���к� 202311262 ��α�", 100);
	gotoxy(10, 14);
	typingEffect("��ǻ�� ���к� 202311302 ������", 100);
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
		typingEffect("1�ܰ� ���а�", 100);
		gotoxy(10, 8);
		typingEffect("1���� �����ϱ� 5������ ���а� 1���� �����ߴ�.",100);
		gotoxy(10, 10);
		typingEffect("���� �ʰ� �ܾ �Է��Ͽ� ����� �ö���",100);
		gotoxy(10, 12);
		typingEffect("����� �� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����",100);
		gotoxy(81, 20);

	}
	else if (level == 2) {
		gotoxy(30, 5);
		typingEffect("2�ܰ� ��õ���", 100);
		gotoxy(10, 8);
		typingEffect("3���� �����ϱ� 5������ ��õ��� 1���� �����ߴ�.",100);
		gotoxy(10, 10);
		typingEffect("�ƴ� ���������� ���� �̷��� ��ٰ�?",100);
		gotoxy(10, 12);
		typingEffect("������� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����",100);
		gotoxy(81, 20);
	}
	else if (level == 3) {
		gotoxy(30, 5);
		typingEffect("3�ܰ� �Ű��а�", 100);
		gotoxy(10, 8);
		typingEffect("5���� �����ϱ� 5������ �Ű��а� 1���� �����ߴ�.", 100);
		gotoxy(10, 10);
		typingEffect("����? ���������Ͱ� �������̶��?", 100);
		gotoxy(10, 12);
		typingEffect("����� ���� �ö󰡼� ���ѽð��ȿ� �⼮��ȣ�� �Է�����", 100);
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
	gotoxy(0, 0); // ��ǥ ���� ���� �ʿ�
	printf("%d\n", time); // �ð����
	/*
		TODO:
		�ֿܼ� ���س� ��ǥ�� �ð� ��� 
	*/
}

void showNowLocation(int loc)
{

		// ���ϴ� �����
		gotoxy(20, 17);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		printf("__________");

		// �߾� �����
		gotoxy(40, 13);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		printf("__________");

		// ���� �����
		gotoxy(60, 9);
		if (loc % 2 == 1) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // �Ͼ��
		}
		else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); // �Ķ���
		}
		printf("__________");

}

void showPerson(int e) {
	// ��� �� �Ʒ��� ������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �Ͼ��
	gotoxy(22, 14);
	printf("\\ O /");
	gotoxy(22, 15);
	printf("  |   ");
	gotoxy(23, 16);
	printf("/ \\");

	Sleep(500); // 0.5�� ���

	// ��� �� ���� �ø���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); // �Ͼ��
	gotoxy(22, 14);
	printf("  O  ");
	gotoxy(22, 15);
	printf("/ | \\");
	gotoxy(23, 16);
	printf("/ \\");
	Sleep(500); // 0.5�� ���
}

void showText(int level,char* text) {
	/*
		TODO:
		�������� �ܾ� ���
	*/
	
	gotoxy(34, 17);
	printf("%s", text);
}
void showMyText(char* text) {
	gotoxy(34, 19);
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