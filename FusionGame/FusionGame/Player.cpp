#include "Player.h"
#include "Util.h"


Player::Player()
{
}


Player::~Player()
{
}

Player::Player(std::string _name, int _Gold)
{
	Name = _name;
	Gold = _Gold;
}

void Player::PlayerSetting()
{
	system("cls");
	gotoxy(35, 20);
	cout << "�÷��̾��� �̸��� �Է��ϼ��� : ";
	cin >> Name;
	Gold = 100;
	system("cls");

	gotoxy(40, 20);
	cout << "ȯ���մϴ�. " << Name << " ��" << endl;
	Sleep(1000);
	system("cls");
}
