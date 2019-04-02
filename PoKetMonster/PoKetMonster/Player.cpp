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
	//��ȣ �Է��ϰ� ����� �� �ش� ��ȣ�� ���ϸ��� ��´�.
	partMon->Level = 5;
	partMon->Ad = 4 * partMon->Level;
	partMon->Dp = 1.5 * partMon->Level;
	partMon->Hp = 20 * partMon->Level;
	partMon->HpMax = 20 * partMon->Level;
	partMon->Exp = 0;
	partMon->ExpMax = 10 * partMon->Level;
	partMon->skillDamage = partMon->Ad * 3;
	partMon->skillCount = 0;
	
	cout << "��Ʈ�� ���ϸ󽺸��� �����ϼ���" << endl;
	cout << "1, �̻��ؾ�  2, ���̸�  3, ���α�" << endl;
	cout << "�Է� : ";

	int iInput = 0;
	cin >> iInput;

	switch (iInput)
	{
	case 1:
		partMon->SetName("�̻��ؾ�");
		partMon->SetSkillName("����ä��");
		break;
	case 2:
		partMon->SetName("���̸�");
		partMon->SetSkillName("�Ҳɹ߻�");
		break;
	case 3:
		partMon->SetName("���α�");
		partMon->SetSkillName("������");
		break;
	default:
		partMon->SetName("���̸�");
		partMon->SetSkillName("�Ҳɹ߻�");
		break;
	}

	cout << "�̸� : " << partMon->Name << endl;
	cout << "���ݷ� : " << partMon->Ad << endl;
	cout << "���� : " << partMon->Dp << endl;
	cout << "  ü�� : " << partMon->Hp << " / " << partMon->HpMax << endl;
	cout << "����ġ : " << partMon->ExpMax << " / " << partMon->Exp << endl;

	eqMon.push_back(partMon);
	system("pause");
}
