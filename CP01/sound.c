#include "sound.h"

void cursormoving_sound() // 커서움직
{
	Beep(260, 150);
}

void answer_sound() // 정답
{
	Beep(260, 80);
	Sleep(10);
	Beep(330, 80);
	Sleep(10);
	Beep(260, 80);
	Sleep(10);
	Beep(330, 80);
	Sleep(10);
}

void wrong_sound() // 오답
{
	Beep(510, 100);
	Sleep(10);
	Beep(510, 100);
	Sleep(10);
}

void missionclear_sound() // 성공()
{
	Beep(510, 100);
	Sleep(10);
	Beep(510, 100);
	Sleep(10);
	Beep(260, 150);
	Sleep(10);
	Beep(430, 150);
	Sleep(10);
	Beep(340, 150);
	Sleep(10);
	Beep(430, 150);
	Sleep(10);
	Beep(340, 150);
	Sleep(10);
	Beep(290, 150);
	Sleep(10);
	Beep(290, 150);
	Sleep(10);
	Beep(330, 150);
	Sleep(10);
	Beep(340, 150);
	Sleep(10);
	Beep(340, 200);
	Sleep(10);

}
void late_sound() // 실패(지각)
{
	Beep(510, 230);
	Sleep(10);
	Beep(510, 230);
	Sleep(10);
	Beep(430, 150);
	Sleep(10);
	Beep(330, 250);
	Sleep(10);
	Beep(260, 400);
	Sleep(10);
	Beep(330, 250);
	Sleep(10);
}

void starting_sound() // 시작음악
{
	Beep(260, 280);
	Sleep(10);
	Beep(290, 200);
	Sleep(10);
	Beep(330, 250);
	Sleep(10);
	Beep(510, 200);
	Sleep(10);
	Beep(510, 200);
	Sleep(10);
	Beep(380, 230);
	Sleep(10);
	Beep(510, 200);
}