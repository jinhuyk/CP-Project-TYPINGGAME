#ifndef GAME_H
# define GAME_H


# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "cursor.h"
# include "menu.h"
# include "showConsole.h"
# include "sound.h"


void    menu();

void	next(int,int);


void    init(int, int*, int*);
void    inputText(char*,char*,int*,int*,int,int,int,int);
void    stringInit(char*, int);
void    processTurn(int,int,int*, int*,int*,int);

int     makeFinishCode();
int     getTotalLocation(int);
void	game(int);
int     isFinish(int,int);
int     isTextEqual(char*,char*);
int     location2score(int, int);

char*   makeText(int);

#endif