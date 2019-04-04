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
	cout << "플레이어의 이름을 입력하세요 : ";
	cin >> Name;
	Gold = 100;
	system("cls");

	gotoxy(40, 20);
	cout << "환영합니다. " << Name << " 님" << endl;
	Sleep(1000);
	system("cls");
}
