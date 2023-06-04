
#ifndef SHOWCONSOLE_H
# define SHOWCONSOLE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "cursor.h"

void    clearText();
void    showDeveloper();
void    showMenu();
void    showLevelMenu();


void    showFinish(int);
void	showleftTime(int);
void    showNowLocation(int);
void    showPerson(int);
void    showSenario(int);

void    showText(char*);
void    showMyText(char*);

void    showLocation(int, int);
void	showSmile(int, int);

void    makeBox(int, int, int, int);

#endif