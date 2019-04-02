#include "util.h"

void gotoxy(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void GameGo()
{
	system("cls");
	int x = 30;
	int y = 10;
	gotoxy(x, y);
	cout << " 게 임 스 타 트 !!";
	for (int i = 0; i < 50; i++)
	{
		gotoxy(x-20, y);
		x++;
		cout << "▶" << endl;
		Sleep(5);
	}
}

void itemMotion()
{
	for (int i = 10; i < 70; i++)
	{
		gotoxy(i, 10);
		setColor(blue, blue);
		cout << "#";
		
	}
	for (int i = 10; i < 70; i++)
	{
		gotoxy(i, 20);
		cout << "#";

	}

	setColor(white, black);
}

void AdventureMotion()
{
	system("cls");
	setColor(black, white);
	int x = 22, y = 13;
	int slp = 200;
	/*
	for (int i = 10; i < 70; i++) //x+60
	{
		gotoxy(i, 5);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 5; i < 30; i++) //y+25
	{
		gotoxy(70, i);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 70; i > 10; i--) //x-60
	{
		gotoxy(i, 30);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 30; i > 10; i--) //y-20
	{
		gotoxy(10, i);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 10; i < 55; i++) //x+45
	{
		gotoxy(i, 10);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 10; i < 25; i++)
	{
		gotoxy(55, i);
		cout << "#";
		Sleep(slp);
	}
	for (int i = 55; i > 30; i--)
	{
		gotoxy(i, 25);
		cout << "#";
		Sleep(slp);
	}

	for (int i = 25; i > 15; i--)
	{
		gotoxy(30, i);
		cout << "#";
		Sleep(slp);
	}
	*/
	for (int i = 0; i < 3; i++)
	{
		setColor(lightgreen, black);
		
		gotoxy(x, y - 1);
		cout << "#########       #      #     ######### ";
		gotoxy(x, y);
		cout << "#       #    ########  #        # #    ";
		gotoxy(x, y+1);
		cout << "#       #      ###     #       #   #   ";
		gotoxy(x, y+2);
		cout << "#########     #   # ####     ######### ";
		gotoxy(x, y+3);
		cout << "    #          ###     #         #     ";
		gotoxy(x, y+4);
		cout << "    #           ###### #        ###    ";
		gotoxy(x, y+5);
		cout << "#########       #    #         #   #   ";
		gotoxy(x, y+6);
		cout << "                ######          ###    ";

		Sleep(slp);
		gotoxy(x, y - 1);
		cout << "                                       ";
		gotoxy(x, y);
		cout << "                                       ";
		gotoxy(x, y + 1);
		cout << "                                       ";
		gotoxy(x, y + 2);
		cout << "                                       ";
		gotoxy(x, y + 3);
		cout << "                                       ";
		gotoxy(x, y + 4);
		cout << "                                       ";
		gotoxy(x, y + 5);
		cout << "                                       ";
		gotoxy(x, y + 6);
		cout << "                                       ";
		Sleep(slp);
	}
	setColor(white, black);

}

void Init()
{
	system("mode con: cols=80 lines=40");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;	// false 또는 0 : 숨기기
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void GameInfo()
{
	system("cls");
	gotoxy(23, 10);
	cout << "W(↑) A(←) S(→) D(↓) 키와 숫자를 이용한 입력 받기";
	gotoxy(23, 12);
	cout << "SPACE키는 선택";
	gotoxy(23, 14);
	cout << "제작 : 윤현규";
	gotoxy(23, 16);
	system("pause");
}