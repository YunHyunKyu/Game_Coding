#include "Monster.h"



Monster::Monster()
{
}


Monster::~Monster()
{
}

void Monster::SetMonster(int round)
{
	//1~5  6~10 11~15
	int RandomLevel = rand() % ((5*round) - (5*(round-1))) + 1+(5*(round-1)); // 1 ~ 10=> 6 ~ 10,,, 
	Level = RandomLevel;
	Ad = 4 * Level;
	Dp = 1.5 * Level;
	HpMax = 20 * Level;
	Hp = 20 * Level;
	Exp = 0;
	ExpMax = Level * 10;
	giveGold = Level * 50;
	giveExp = Level * 7;
	skillDamage = 2 * Ad;
	skillCount = 0;
}

void Monster::SetName(const char * _name)
{
	strcpy_s(Name, strlen(_name) + 1, _name);
}

void Monster::SetSkillName(const char * _name)
{
	strcpy_s(skillName, strlen(_name) + 1, _name);
}

void Monster::LevelUp(vector<Monster*> plMon)
{
	plMon[0]->Ad += (1 * plMon[0]->Level);
	plMon[0]->Dp += (1 * plMon[0]->Level);
	plMon[0]->Hp += (5 * plMon[0]->Level);
	plMon[0]->HpMax += (5 * plMon[0]->Level);
	plMon[0]->ExpMax = (10 * plMon[0]->Level);
	plMon[0]->skillDamage = plMon[0]->Ad * 3;
	plMon[0]->skillCount = 0;

	if (strcmp(plMon[0]->Name, "�̻��ؾ�") == 0 && plMon[0]->Level == 10)
	{
		plMon[0]->SetName("�̻���Ǯ");
		plMon[0]->SetSkillName("�ٳ�������");
		plMon[0]->Ad += 10;
		system("cls");
		gotoxy(30, 10);
		cout << "��ȭ" << endl;
	}
	else if (strcmp(plMon[0]->Name, "���̸�") == 0 && plMon[0]->Level == 10)
	{
		plMon[0]->SetName("���ڵ�");
		plMon[0]->SetSkillName("�Ҳɼ���");
		plMon[0]->Ad += 10;
		system("cls");
		gotoxy(30, 10);
		cout << "��ȭ" << endl;
	}
	else if (strcmp(plMon[0]->Name, "���α�") == 0 && plMon[0]->Level == 10)
	{
		plMon[0]->SetName("��Ϻα�");
		plMon[0]->SetSkillName("������");
		plMon[0]->Ad += 10;
		system("cls");
		gotoxy(30, 10);
		cout << "��ȭ" << endl;
	}

	
	Sleep(1000);
}

