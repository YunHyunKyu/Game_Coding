#include "Player.h"
#include "util.h"


Player::Player()
{
	gold = 10;
	MonsterBall = 1;
	partMon = new Monster;
}


Player::~Player()
{
	delete partMon;
}

void Player::EqPoket(vector<Monster*> &eqMon)
{
	//번호 입력하게 만들고 그 해당 번호의 포켓몬을 얻는다.
	partMon->Level = 5;
	partMon->Ad = 4 * partMon->Level;
	partMon->Dp = 1.5 * partMon->Level;
	partMon->Hp = 20 * partMon->Level;
	partMon->HpMax = 20 * partMon->Level;
	partMon->Exp = 0;
	partMon->ExpMax = 10 * partMon->Level;
	partMon->skillDamage = partMon->Ad * 3;
	partMon->skillCount = 0;
	
	cout << "파트너 포켓몬스몬을 선택하세요" << endl;
	cout << "1, 이상해씨  2, 파이리  3, 꼬부기" << endl;
	cout << "입력 : ";

	int iInput = 0;
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		partMon->SetName("이상해씨");
		partMon->SetSkillName("덩쿨채찍");
		break;
	case 2:
		partMon->SetName("파이리");
		partMon->SetSkillName("불꽃발사");
		break;
	case 3:
		partMon->SetName("꼬부기");
		partMon->SetSkillName("물대포");
		break;
	default:
		partMon->SetName("파이리");
		partMon->SetSkillName("불꽃발사");
		break;
	}

	cout << "이름 : " << partMon->Name << endl;
	cout << "공격력 : " << partMon->Ad << endl;
	cout << "방어력 : " << partMon->Dp << endl;
	cout << "  체력 : " << partMon->Hp << " / " << partMon->HpMax << endl;
	cout << "경험치 : " << partMon->ExpMax << " / " << partMon->Exp << endl;

	eqMon.push_back(partMon);
	system("pause");
}
