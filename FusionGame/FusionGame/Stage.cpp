#include "Stage.h"
#include "Hero.h"
#include "Player.h"
#include <Windows.h>
#include <conio.h>

int Stage::Round = 0;
extern time_t startTime;


Stage::Stage()
{
	Hero* enemy = new Hero("������", 1, 50, 50, 0, 0, 0, 0, 1);
	enemyList.push_back(enemy);

	enemy = new Hero("������2", 2, 100, 100, 0, 0, 0, 0, 2);
	enemyList.push_back(enemy);

	enemy = new Hero("������3", 3, 150, 150, 0, 0, 0, 0, 3);
	enemyList.push_back(enemy);

	enemy = new Hero("������4", 4, 250, 250, 0, 0, 0, 0, 4);
	enemyList.push_back(enemy);

	enemy = new Hero("������5", 5, 300, 300, 0, 0, 0, 0, 5);
	enemyList.push_back(enemy);

	enemy = new Hero("������6", 6, 350, 350, 0, 0, 0, 0, 6);
	enemyList.push_back(enemy);

	enemy = new Hero("������7", 7, 400, 400, 0, 0, 0, 0, 7);
	enemyList.push_back(enemy);

	enemy = new Hero("������8", 8, 450, 450, 0, 0, 0, 0, 8);
	enemyList.push_back(enemy);

	enemy = new Hero("������9", 9, 500, 500, 0, 0, 0, 0, 9);
	enemyList.push_back(enemy);

	enemy = new Hero("ŷ������", 10, 1000, 1000, 0, 0, 0, 0, 10);
	enemyList.push_back(enemy);
}


Stage::~Stage()
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		if (enemyList[i] != NULL)
		{
			delete enemyList[i];
		}
	}
	
	enemyList.clear();
}

void MonsterTemp(int &monX)
{
	
	setColor(blue, black);
	gotoxy(monX, 10);
	cout << "              ##" << endl;
	gotoxy(monX, 11);
	cout << "            #####" << endl;
	gotoxy(monX, 12);
	cout << "           ##########" << endl;
	gotoxy(monX, 13);
	cout << "         #############" << endl;
	gotoxy(monX, 14);
	cout << "         ##  ###   ###" << endl;
	gotoxy(monX, 15);
	cout << "        ###  ###   ####" << endl;
	gotoxy(monX, 16);
	cout << "        ###############" << endl;
	gotoxy(monX, 17);
	cout << "        ## ####### ###" << endl;
	gotoxy(monX, 18);
	cout << "         ##       ##" << endl;
	gotoxy(monX, 19);
	cout << "          #########" << endl;
	setColor(white, black);
}

void PlayerTemp()
{
	int x = 20, y = 13;
	gotoxy(x, y);
	cout << "###############" << endl;
	gotoxy(x, y+1);
	cout << "#             #" << endl;
	gotoxy(x, y+2);
	cout << "#             #" << endl;
	gotoxy(x, y+3);
	cout << "#             #" << endl;
	gotoxy(x, y+4);
	cout << "###############" << endl;
	gotoxy(x, y+5);
	cout << "#" << endl;
	gotoxy(x, y+6);
	cout << "#" << endl;
	gotoxy(x, y+7);
	cout << "#" << endl;
	gotoxy(x, y+8);
	cout << "#" << endl;
}

void AttackTemp()
{
	int x = 36, y = 17;
	
	for (int i = 5; i < 20; i++)
	{
		gotoxy(x+i, y);
		cout << "->";
		Sleep(10);
		gotoxy(x+i, y);
		cout << "  ";
	}
}

void Stage::RoundStart(Player & player)
{
	system("cls");
	list<Hero*>::iterator hiter;
	int AttackDamage = 0;
	int MagDamage = 0;
	int HeroNum = 0;
	int x = 5, y = 32;
	int LoopMon = 0;
	int MagicAttack = 0;
	time_t LoseTime;
	bool RoundClear = false;
	Hero* RoundMonster = new Hero[10];
	for (int i = 0; i < 10; i++)
	{
		RoundMonster[i].Name = enemyList[Round]->Name;
		RoundMonster[i].Hp = enemyList[Round]->Hp;
		RoundMonster[i].HpMax = enemyList[Round]->HpMax;
		RoundMonster[i].Dp = enemyList[Round]->Dp;
	}

	gotoxy(0, 28);
	setColor(lightgray, lightgray);
	cout << "###################################################################################################~";
	setColor(white, black);
	gotoxy(15, 30);
	cout << "======================== ���� ����Ʈ =================================";
	gotoxy(x, y);
	for (hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++)
	{

		AttackDamage += (*hiter)->Ad;
		MagDamage += (*hiter)->Ap;
		HeroNum++;
		gotoxy(x, y);
		cout << HeroNum << ". " << (*hiter)->Name << " ���ݷ� : " << (*hiter)->Ad << " �������ݷ� : " << (*hiter)->Ap;
		if (x < 50)
		{
			x += 45;
		}
		else if (x >= 50)
		{
			x = 5;
			y += 1;
		}
	}

	PlayerTemp();

	gotoxy(20, 23);
	cout << "�� ���ݷ� : " << AttackDamage << endl;
	gotoxy(20, 24);
	cout << "�� �ο��� : " << HeroNum << endl;

	int monX = 58;
	MonsterTemp(monX);
	gotoxy(monX + 7, 23);
	cout << "���� : " << RoundMonster[LoopMon].Name << " ( " << LoopMon+1 << " )" << endl;
	gotoxy(monX + 7, 24);
	cout << "ü�� : " << RoundMonster[LoopMon].Hp << "/" << RoundMonster[LoopMon].HpMax << endl;
	gotoxy(monX + 7, 25);
	cout << "���� : " << RoundMonster[LoopMon].Dp << endl;

	gotoxy(x, y + 1);
	cout << "Enter �Է� ��,, ���� ����" << endl;
	getchar();
	Sleep(100);
	while (1)
	{
		gotoxy(15, 30);
		cout << "======================== ���� ü�� =================================";
		for (int i = 0; i < 10; i++)
		{
			gotoxy(20, 32+i);
			cout << i + 1 << ". ü�� : " << RoundMonster[i].Hp << endl;
		}

		//Round ǥ��
		gotoxy(5, 0);
		cout << Round+1 << "  Round";

		//==========���� �ð��� ����ֱ�================
		time(&LoseTime);
		int ti = difftime(LoseTime, startTime);
		int waitTime = 30;
		waitTime -= ti;
		gotoxy(50, 1);
		cout << waitTime << " ��";
		if (waitTime <= 0)
		{
			waitTime = 0;
			system("cls");
			gotoxy(40, 20);
			cout << "���� Ŭ���� ����, �� �� ��ȭ�ϼ���" << endl;
			gotoxy(40, 21);
			system("pause");
			break;
		}
		//--------------------------------
		//����================
		if (_kbhit() && _getch() == 27)
		{
			break;
		}
		//=====================
		PlayerTemp();	//�÷��̾� ���

		gotoxy(20, 23);
		cout << "�� ���ݷ� : " << AttackDamage << endl;
		gotoxy(20, 24);
		cout << "�� �ο��� : " << HeroNum << endl;
		gotoxy(20, 25);
		cout << "���� : ESC" << endl;

		int monX = 58;
		MonsterTemp(monX);	//���� ���

		gotoxy(monX+7, 23);
		cout << "���� : " << RoundMonster[LoopMon].Name << " ( " << LoopMon+1 << " )" << endl;
		gotoxy(monX + 7, 24);
		cout << "ü�� : " << RoundMonster[LoopMon].Hp << "/" << RoundMonster[LoopMon].HpMax << endl;
		gotoxy(monX + 7, 25);
		cout << "���� : " << RoundMonster[LoopMon].Dp << endl;

		MagicAttack = rand() % 10;
		int Damage = AttackDamage;
		if (MagicAttack > 6)		// 7,8,9 ������ ��ų �ߵ� (Ȯ�� 30��)
		{
			gotoxy(30, 10);
			cout << "��ų �ߵ�";
			Sleep(500);
			gotoxy(30, 10);
			cout << "          ";
			Damage += MagDamage;
		}

		if (RoundMonster[LoopMon].Hp > 0)			//���� ü�� 0���� Ŭ���� ����
		{
			Damage -= RoundMonster[LoopMon].Dp;
			if (Damage <= 0)
				Damage = 1;
			RoundMonster[LoopMon].Hp -= Damage;
			AttackTemp();
		}
		
		if (RoundMonster[LoopMon].Hp <= 0)	//���� ����
		{
			RoundMonster[LoopMon].Hp = 0;	//ü�� -�� �Ȱ���
		}

		LoopMon++;

		if (LoopMon > 9)	//���ʹ� 10���� 0~9���� ���� 9 �Ѿ�� 0���� ����
		{
			LoopMon = 0;
		}

		for (int i = 0; i < 10; i++)		//���� �� ������ ���� Ŭ���� TRUE, �ƴϸ� False
		{
			if (RoundMonster[i].Hp <= 0)
				RoundClear = true;
			else
			{
				RoundClear = false;
				break;
			}
		}
		
		if (RoundClear)		// �������� Ŭ����
		{
			Round++;
			player.Gold += (Round * 100);
			system("cls");
			cout << "Round Ŭ����" << endl;
			cout << "��� ( " << Round * 100 << " ) ȹ��" << endl;
			system("pause");
			break;
		}

		Sleep(500);
		system("cls");
	}
}

