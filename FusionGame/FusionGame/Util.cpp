#include "Util.h"

void Title()
{
	int x = 45, y = 5;
	setColor(red, red);
	gotoxy(x, y);
	cout << "##############";
	gotoxy(x, y+1);
	cout << "#";
	gotoxy(x, y+2);
	cout << "#";
	gotoxy(x, y+3);
	cout << "#";
	gotoxy(x, y+4);
	cout << "############";
	gotoxy(x, y+5);
	cout << "#";
	gotoxy(x, y+6);
	cout << "#";
	gotoxy(x, y+7);
	cout << "#";
	gotoxy(x, y+8);
	cout << "#";
	gotoxy(x, y+9);
	cout << "#";
	setColor(white, black);
}

void gotoxy(int x, int y)
{
	COORD Pos{ x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setColor(int forground, int background)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔 핸들 가져오기
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void FusionInfo()
{
	system("cls");
	int x = 10, y = 2;
	gotoxy(40, 0);
	cout << "※ 조 합 법 ※ " << endl;
	setColor(green, black);
	gotoxy(x, y);
	cout << "슬라임 + 슬라임 = 산성 슬라임";
	gotoxy(x + 40, y);
	cout << "고블린 + 고블린 = 고블린 전사";

	gotoxy(x, y + 2);
	cout << "스켈레톤 + 스켈레톤 = 스켈레톤 워리어";
	gotoxy(x + 40, y + 2);
	cout << "페어리 + 페어리 = 붉은 페어리";

	gotoxy(x, y + 4);
	cout << "인간병사 + 인간병사 = 기사";
	gotoxy(x + 40, y + 4);
	cout << "인간병사 + 페어리 = 견습마법사";

	setColor(lightblue, black);
	gotoxy(x, y + 6);
	cout << "기사 + 스켈레톤 워리어 = 암흑기사";

	setColor(white, black);
	

	gotoxy(0, 49);
	system("pause");
}