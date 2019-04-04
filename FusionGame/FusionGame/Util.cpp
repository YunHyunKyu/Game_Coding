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
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ� �ڵ� ��������
	int code = forground + background * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void FusionInfo()
{
	system("cls");
	int x = 10, y = 2;
	gotoxy(40, 0);
	cout << "�� �� �� �� �� " << endl;
	setColor(green, black);
	gotoxy(x, y);
	cout << "������ + ������ = �꼺 ������";
	gotoxy(x + 40, y);
	cout << "��� + ��� = ��� ����";

	gotoxy(x, y + 2);
	cout << "���̷��� + ���̷��� = ���̷��� ������";
	gotoxy(x + 40, y + 2);
	cout << "�� + �� = ���� ��";

	gotoxy(x, y + 4);
	cout << "�ΰ����� + �ΰ����� = ���";
	gotoxy(x + 40, y + 4);
	cout << "�ΰ����� + �� = �߽�������";

	setColor(lightblue, black);
	gotoxy(x, y + 6);
	cout << "��� + ���̷��� ������ = ������";

	setColor(white, black);
	

	gotoxy(0, 49);
	system("pause");
}