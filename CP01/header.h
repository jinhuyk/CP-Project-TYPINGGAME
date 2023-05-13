// function, header file declare here

#include <stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int, int);
COORD getxy();
int selectxy(COORD*,int);

//definition on menu.c
void printMenu();
void selectMenu();
void selectLevel();

//definition on game.c
void showGame(int);
void showSenario(int);
void showleftTime(int);
void showNowLocation(int);
void showText(int);
char* inputText();
int  equalText(char*);
void processTurn(int, int);
int isFinish();
