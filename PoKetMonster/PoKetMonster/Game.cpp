#include "util.h"
#include "Game.h"

//�÷��̾�, �� ���� ���
void AttackMotion(int n)
{
	if (n == 0) // �÷��̾� ����
	{
			for (int i = 20; i < 35; i++)
			{
				setColor(lightred, lightred);
				gotoxy(i, 4);
				cout << "####";
				gotoxy(i, 5);
				cout << "####";
				Sleep(20);
				setColor(white, black);
				gotoxy(i, 4);
				cout << "     ";
				gotoxy(i, 5);
				cout << "     ";
				setColor(white, black);
			}
	}
	else if (n == 1) // �� ����
	{
		for (int i = 50; i > 42; --i)
		{
			setColor(lightblue, lightblue);
			gotoxy(i, 4);
			cout << "####";
			gotoxy(i, 5);
			cout << "####";
			Sleep(20);
			setColor(white, black);
			gotoxy(i, 4);
			cout << "     ";
			gotoxy(i, 5);
			cout << "     ";
			setColor(white, black);
		}
	}
}

//1. ���Ϳ� �ο�� �ڵ�
void Dual(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int Random)
{
	system("cls");
	int py = 14;
	int playerCri;
	int EnemyCri;
	while (playerMonster[0]->Hp > 0 && EnemyMonster[Random]->Hp > 0)
	{
		playerCri = rand() % 100 + 1;
		EnemyCri = rand() % 100 + 1;


		setColor(lightblue, black);
		int x = 3, y = 2;
		gotoxy(3, 0);
		cout << "[ �÷��̾� ���� ]" << endl;
		gotoxy(x, y);
		cout << "  �̸� : " << playerMonster[0]->Name;
		gotoxy(x, y + 2);
		cout << "  ���� : " << playerMonster[0]->Level;
		gotoxy(x, y + 4);
		cout << "���ݷ� : " << playerMonster[0]->Ad;
		gotoxy(x, y + 6);
		cout << "���� : " << playerMonster[0]->Dp;
		gotoxy(x, y + 8);
		cout << "  ü�� : " << playerMonster[0]->Hp << " / " << playerMonster[0]->HpMax;
		gotoxy(x, y + 10);

		int gx = 1;
		setColor(white, white);
		for (int i = 0; i < 12; i++)
		{
			gotoxy(40 + gx, i);
			cout << "@";
			if (i % 2 == 0)
			{
				gx = -1;
			}
			else
			{
				gx = 1;
			}
		}

		setColor(lightpurple, black);
		x = 57;
		gotoxy(57, 0);
		cout << "[ �� ���� ]" << endl;
		gotoxy(x, y);
		cout << "  �̸� : " << EnemyMonster[Random]->Name;
		gotoxy(x, y + 2);
		cout << "  ���� : " << EnemyMonster[Random]->Level;
		gotoxy(x, y + 4);
		cout << "���ݷ� : " << EnemyMonster[Random]->Ad;
		gotoxy(x, y + 6);
		cout << "���� : " << EnemyMonster[Random]->Dp;
		gotoxy(x, y + 8);
		cout << "  ü�� : " << EnemyMonster[Random]->Hp << " / " << EnemyMonster[Random]->HpMax;
		gotoxy(x, y + 10);
		int px = 3, mx = 30;
		setColor(white, black);

		//�÷��̾� ����
		
		int playerDamage = (playerMonster[0]->Ad - EnemyMonster[Random]->Dp); //�÷��̾� ������

		if (playerMonster[0]->skillCount == 3) //��ų ��� (��Ÿ�� 3��)
		{
			gotoxy(px, py);
			cout << playerMonster[0]->skillName << endl;
			playerDamage += playerMonster[0]->skillDamage;
			Sleep(300);
			gotoxy(px, py);
			cout << "             ";
			playerMonster[0]->skillCount = 0;
		}
		else
		{
			playerMonster[0]->skillCount++;
		}

		if (playerCri <= 10) // ġ��Ÿ �߻� (�÷��̾�)
		{
			gotoxy(px, py);
			cout << "ġ��Ÿ!!";
			playerDamage *= 1.5;
			Sleep(300);
			gotoxy(px, py);
			cout << "          ";
		}
		

		if (playerDamage <= 0)
		{
			AttackMotion(0);

			EnemyMonster[Random]->Hp -= 1; // �������� 0���� ������ 1������
			gotoxy(px, py);
			cout << playerMonster[0]->Name << "�� " << EnemyMonster[Random]->Name << "���� " << "1�� ���ظ� �������ϴ�.";
			Sleep(1000);
			gotoxy(px, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
		}
		else
		{
			AttackMotion(0);

			EnemyMonster[Random]->Hp -= playerDamage;
			gotoxy(px, py);
			cout << playerMonster[0]->Name << "�� " << EnemyMonster[Random]->Name << "���� " << playerDamage << "�� ���ظ� �������ϴ�.";
			Sleep(1000);
			gotoxy(px, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
			//Sleep(500);
		}

		if (EnemyMonster[Random]->Hp <= 0) // �� ��� ó��
		{
			EnemyMonster[Random]->Hp = 0;
			gotoxy(57, 10);
			cout << "                           ";
			gotoxy(57, 10);
			setColor(lightpurple, black);
			cout << "  ü�� : " << '0' << " / " << '0';
			setColor(white, black);
			gotoxy(px + 10, py + 3);
			cout << EnemyMonster[Random]->Name <<"��(��) ����Ͽ����ϴ�." << endl;
			gotoxy(px + 10, py + 5);
			cout << EnemyMonster[Random]->giveExp << "Exp ȹ��" << endl;
			playerMonster[0]->Exp += EnemyMonster[Random]->giveExp;
			while (playerMonster[0]->Exp >= playerMonster[0]->ExpMax)
			{
				playerMonster[0]->Exp -= playerMonster[0]->ExpMax;
				playerMonster[0]->Level++;
				gotoxy(px + 10, py + 7);
				cout << playerMonster[0]->Name << "�� ���� " << playerMonster[0]->Level << "�� �Ǿ����ϴ�" << endl;
				playerMonster[0]->Hp = playerMonster[0]->HpMax;
				playerMonster[0]->LevelUp(playerMonster);
				py += 2;
			}
			gotoxy(px + 10, py + 2);
			system("pause");
			EnemyMonster[Random]->Hp = EnemyMonster[Random]->HpMax; // ����Ǿ� �ִ� ���� ü�� �ٽ� ���󺹱�
			return;
		}

		//���� ����
		int EnemyDamage = (EnemyMonster[Random]->Ad - playerMonster[0]->Dp);

		if (EnemyMonster[Random]->skillCount == 3) //�� �� ��ų ��� (��Ÿ�� 3��)
		{
			gotoxy(mx+35, py);
			cout << EnemyMonster[Random]->skillName << endl;
			EnemyDamage += EnemyMonster[Random]->skillDamage;
			Sleep(700);
			gotoxy(mx+35, py);
			cout << "             ";
			EnemyMonster[Random]->skillCount = 0;
		}
		else
		{
			EnemyMonster[Random]->skillCount++;
		}

		if (EnemyCri <= 10)
		{
			gotoxy(mx+35, py);
			cout << "ġ��Ÿ!!";
			EnemyDamage *= 1.5;
			Sleep(300);
			gotoxy(mx+35, py);
			cout << "          ";
		}

		if (EnemyDamage <= 0)
		{
			AttackMotion(1);
			playerMonster[0]->Hp -= 1;
			gotoxy(mx, py);
			cout << EnemyMonster[Random]->Name << "�� " << playerMonster[0]->Name << "���� 1�� ���ظ� �������ϴ�.";
			Sleep(1000);
			gotoxy(mx, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
		}
		else
		{
			AttackMotion(1);
			playerMonster[0]->Hp -= EnemyDamage;
			gotoxy(mx, py);
			cout << EnemyMonster[Random]->Name << "�� " << playerMonster[0]->Name << "���� " << EnemyDamage << "�� ���ظ� �������ϴ�.";
			Sleep(1000);
			gotoxy(mx, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
		}
		if (playerMonster[0]->Hp <= 0) // �÷��̾� ��� ó��
		{
			playerMonster[0]->Hp = 0;
			gotoxy(px + 10, py + 3);
			cout << playerMonster[0]->Name << "�� ����Ͽ����ϴ�." << endl;
			gotoxy(px + 10, py + 5);
			system("pause");
			return;
		}
		system("cls");
	}
}

//3 ���ͺ�
int MonsterBall(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int RandomMonster, Player &player)
{
	int monsterGet = rand() % 10 + 1;
	if (playerMonster.size() < 11)
	{
		if (player.MonsterBall > 0)
		{
			player.MonsterBall--;
			if (monsterGet <= 3) // 30�ۼ�Ʈ Ȯ��
			{
				playerMonster.push_back(EnemyMonster[RandomMonster]);
				cout << EnemyMonster[RandomMonster]->Name << "�� ��Ҵ�~!!" << endl;
				Sleep(1000);
				system("cls");
				int x = 30, y = 5;
				gotoxy(x, y - 2);
				cout << "[ ���� ���� ]" << endl;
				gotoxy(x, y);
				cout << "  �̸� : " << EnemyMonster[RandomMonster]->Name;
				gotoxy(x, y + 2);
				cout << "  ���� : " << EnemyMonster[RandomMonster]->Level;
				gotoxy(x, y + 4);
				cout << "���ݷ� : " << EnemyMonster[RandomMonster]->Ad;
				gotoxy(x, y + 6);
				cout << "���� : " << EnemyMonster[RandomMonster]->Dp;
				gotoxy(x, y + 8);
				cout << "  ü�� : " << EnemyMonster[RandomMonster]->Hp << " / " << EnemyMonster[RandomMonster]->HpMax;
				gotoxy(x, y + 10);
				Sleep(1000);
				return 0;
			}
			else
			{
				cout << "����Ҵ�." << endl;
				Sleep(1000);
				return 1;
			}
		}
		else
		{
			cout << "���ͺ��� ����. " << endl;
			Sleep(1000);
			return 1;
		}
	}
	else
	{
		cout << "�κ��丮�� ��á���ϴ�." << endl;
		Sleep(1000);
		return 1;
	}
}

//���� ���� ���ý� ���Ͱ� ������ ��
void battle(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, Player &player, int number)
{
	int RandomMonster = rand() % EnemyMonster.size();
	while (1)
	{
		system("cls");
		setColor(lightblue, black);
		int x = 3, y = 2;
		gotoxy(3, 0);
		cout << "[ �÷��̾� ���� ]" << endl;
		gotoxy(x, y);
		cout << "  �̸� : " << playerMonster[0]->Name;
		gotoxy(x, y + 2);
		cout << "  ���� : " << playerMonster[0]->Level;
		gotoxy(x, y + 4);
		cout << "���ݷ� : " << playerMonster[0]->Ad;
		gotoxy(x, y + 6);
		cout << "���� : " << playerMonster[0]->Dp;
		gotoxy(x, y + 8);
		cout << "  ü�� : " << playerMonster[0]->Hp << " / " << playerMonster[0]->HpMax;
		gotoxy(x, y + 10);

		int gx = 1;
		setColor(white, white);
		for (int i = 0; i < 12; i++)
		{
			gotoxy(40 + gx, i);
			cout << "@";
			if (i % 2 == 0)
			{
				gx = -1;
			}
			else
			{
				gx = 1;
			}
		}

		setColor(lightpurple, black);
		x = 57;
		gotoxy(57, 0);
		cout << "[ �� ���� ]" << endl;
		gotoxy(x, y);
		cout << "  �̸� : " << EnemyMonster[RandomMonster]->Name;
		gotoxy(x, y + 2);
		cout << "  ���� : " << EnemyMonster[RandomMonster]->Level;
		gotoxy(x, y + 4);
		cout << "���ݷ� : " << EnemyMonster[RandomMonster]->Ad;
		gotoxy(x, y + 6);
		cout << "���� : " << EnemyMonster[RandomMonster]->Dp;
		gotoxy(x, y + 8);
		cout << "  ü�� : " << EnemyMonster[RandomMonster]->Hp << " / " << EnemyMonster[RandomMonster]->HpMax;
		gotoxy(x, y + 10);

		x = 50;
		y = 30;
		setColor(white, black);

		gotoxy(x, y);
		cout << "1. �ο��" << endl;
		gotoxy(x, y+2);
		cout << "2. ��������" << endl;
		gotoxy(x, y+4);
		cout << "3. ���ͺ�" << endl;
		gotoxy(x, y + 6);
		cout << "�Է� : ";
		int n = cinKey<int>();

		if (n < MB_BATTLE || n > MB_MONSTERCATCH)
		{
			continue;
		}

		if (n == MB_BATTLE) // �ο��
		{
			Dual(playerMonster, EnemyMonster, RandomMonster);
			if (number == 1 && playerMonster[0]->Hp > 0)
			{
				int RandomGold = rand() % 100 + 1;
				player.gold += RandomGold;
				system("cls");
				gotoxy(23, 10);
				cout << "�÷��̾ " << RandomGold << "��带 ȹ���߽��ϴ�." << endl;
				Sleep(1000);
			}
			break;
		}
		else if (n == MB_ESCAPE) // ��������
		{
			return;
		}
		else if (n == MB_MONSTERCATCH) // ���ͺ�
		{
			if (number == 0) // Ʈ���̳ʿ� �ο��� ���ͺ� ������
			{
				int ball = MonsterBall(playerMonster, EnemyMonster, RandomMonster, player);
				if (ball == 0) //���� ����
				{
					break;
				}
				else if (ball == 1) //������
				{

				}
			}
		}

	}
}

//���� Ʈ���̴� �ҽ�
void training(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	gotoxy(60, 0);
	cout << "���� GOLD : " << player.gold;
	gotoxy(23, 15);
	cout << "���ϸ��� �Ʒý�Ű�ڽ��ϱ�? (100 Gold)" << endl;
	int x = 23, y = 17;
	gotoxy(x - 2, y);
	cout << "> ��, �Ʒ��� �ްڽ��ϴ�." << endl;
	gotoxy(x, y + 2);
	cout << "�ƴϿ�, ���� �����ϴ�. �Ф�" << endl;

	while (1)
	{		
		int n = GetKey();
		
		if (n == UP)
		{
			if (y > 17)
			{
				gotoxy(x - 2, y);
				cout << " ";
				y -= 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
		}
		else if (n == DOWN)
		{
			if (y < 19)
			{
				gotoxy(x - 2, y);
				cout << " ";
				y += 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
		}
		else if (n == SPACE)
		{
			if (y == 17)
			{
				if (player.gold >= 100)
				{
					player.gold -= 100;
					int Random = rand() % 3;
					system("cls");
					if (Random == 0) // hp ���
					{
						playerMonster[0]->HpMax += 10;
						gotoxy(23, 15);
						cout << "�ִ� ü���� 10 ����մϴ�." << endl;
						Sleep(500);
					}
					else if (Random == 1) // ad ���
					{
						playerMonster[0]->Ad += 1;
						gotoxy(23, 15);
						cout << "���ݷ��� 1 ����մϴ�." << endl;
						Sleep(500);
					}
					else if (Random == 2) // dp ���
					{
						playerMonster[0]->Dp += 1;
						gotoxy(23, 15);
						cout << "������ 1 ����մϴ�." << endl;
						Sleep(500);
					}
				}
				else
				{
					system("cls");
					gotoxy(23, 15);
					cout << "���� �����ϴ�. �Ф�" << endl;
					Sleep(1000);
				}
				break;
			}
			else if (y == 19)
			{
				break;
			}
		}
	}
}



//������ �ݱ� �ҽ�
void ItemGet(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	int Random = rand() % 5;
	if (Random == 0)
	{
		itemMotion();
		playerMonster[0]->Hp += 25;
		if (playerMonster[0]->HpMax < playerMonster[0]->Hp)
		{
			playerMonster[0]->Hp = playerMonster[0]->HpMax;
		}
		gotoxy(18, 15);
		cout << playerMonster[0]->Name << "�� ���Ÿ� �Ծ� 25�� ü���� ȸ���߽��ϴ�." << endl;
		Sleep(800);
	}
	else if (Random == 1)
	{
		itemMotion();
		playerMonster[0]->Hp += 50;
		if (playerMonster[0]->HpMax < playerMonster[0]->Hp)
		{
			playerMonster[0]->Hp = playerMonster[0]->HpMax;
		}
		gotoxy(18, 15);
		cout << playerMonster[0]->Name << "�� �������Ǹ� �Ծ� 50�� ü���� ȸ���߽��ϴ�." << endl;
		Sleep(800);
	}
	else if (Random == 2)
	{
		itemMotion();
		int MoneyGet = rand() % 50 + 1;
		gotoxy(23, 15);
		cout << MoneyGet << "Gold�� �ֿ���,, �ູ�ϴ�." << endl;
		player.gold += MoneyGet;
		Sleep(800);
	}
	else if (Random == 3)
	{
		itemMotion();
		int MoneyGet = rand() % 50 + 1;
		gotoxy(23, 15);
		cout << MoneyGet << "Gold�� �ֿ���,, �ູ�ϴ�." << endl;
		player.gold += MoneyGet;
		Sleep(800);
	}
	else if (Random == 4)
	{
		itemMotion();
		gotoxy(23, 15);
		cout << "���ͺ��� �ֿ���. �ູ�ϴ�.";
		player.MonsterBall += 1;
		Sleep(800);
	}
}

//�� ����
void FirstMap(Player &player, vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster)
{
	int Random = rand() % 4;
	AdventureMotion();
	if (Random == 0)
	{
		//���ϸ�� ����
		battle(playerMonster, EnemyMonster, player, 0);
	}
	else if (Random == 1)
	{
		//���ϸ�� ����
		battle(playerMonster, EnemyMonster, player, 0);
	}
	else if (Random == 2)
	{
		//���ϸ� Ʈ���̴�
		training(player, playerMonster);
	}
	else if (Random == 3)
	{
		//������ ȹ�� (ȿ���� ??) -- 1. ü�� ȸ��   2. �� �ݱ�
		ItemGet(player, playerMonster);
	}
}

void trainer(Player &player, vector<Monster*> &playerMonster)
{
	vector<Monster*> trainerMonsterList;
	Monster *trainerMonster = new Monster[3]; //���߿� ����
	TrinerMonsterSetting(trainerMonsterList, trainerMonster, playerMonster);
	int RandomGold = rand() % 100 + 1;

	battle(playerMonster, trainerMonsterList, player, 1);
	
}

//���� �ҽ�
void Adventure(Player &player, vector<Monster*> &playerMonster)
{
	vector<Monster*> FirstMonsterList;
	vector<Monster*> SecondMonsterList;
	vector<Monster*> ThridMonsterList;
	Monster *firstMonster = new Monster[10];
	Monster *secondMonster = new Monster[10];
	Monster *ThridMonster = new Monster[10];
	NormalMonsterSetting(FirstMonsterList, firstMonster, 1);
	NormalMonsterSetting(SecondMonsterList, secondMonster, 2);
	EvMonsterSetting(ThridMonsterList, ThridMonster, 3);


	int count = 0;
	while (1)
	{
		gotoxy(30, 10);
		if (count == 0)
		{
			cout << "1. ���� ����(1~5)  " << endl;
		}
		else if (count == 1)
		{
			cout << "2. ��� ����(6~10) ";
		}
		else if (count == 2)
		{
			cout << "3. �׸� ����(11~16)" << endl;
		}
		else if (count == 3)
		{
			cout << "4. Ʈ���̳ʿ� ����" << endl;
		}
		gotoxy(30, 12);
		cout << "���� �ѱ��(DŰ), ����(SPACE)";
		gotoxy(30, 14);
		cout << "�ڷΰ���(BŰ)";

		int n = GetKey();

		if (n == RIGHT) // ���� �ѱ��
		{
			count++;
			if (count > 3)
				count = 0;
		}
		else if (n == SPACE)
		{
			if (playerMonster[0]->Hp > 0)
			{
				if (count == 0) //���� ���� ����
				{
					FirstMap(player, playerMonster, FirstMonsterList);
				}
				else if (count == 1)
				{
					FirstMap(player, playerMonster, SecondMonsterList);
				}
				else if (count == 2)
				{
					FirstMap(player, playerMonster, ThridMonsterList);
				}
				else if (count == 3)
				{
					trainer(player, playerMonster);
				}
			}
			else
			{
				gotoxy(30, 16);
				cout << playerMonster[0]->Name << "�� ü���� �����ϴ�." << endl;
				Sleep(500);
			}
		}
		else if (n == EX_OUT)
		{
			return;
		}

		
		system("cls");
	}
	delete firstMonster;
	delete secondMonster;
}

void Inventory(vector<Monster*> &playerMonster)
{
	vector<Monster*> monsterSwap;
	while (1)
	{
		if (playerMonster.size() <= 1) //���� ���͸� ����..
		{
			cout << "�κ��丮�� ���Ͱ� �����ϴ�." << endl;
			Sleep(1000);
			return;
		}
		else
		{
			gotoxy(60, 35);
			cout << playerMonster.size()-1 << " / " << 10 << endl;

			gotoxy(30, 5);
			cout << "[ �� �� �� �� ]";
			int x = 30, y = 7;
			for (int i = 1; i < playerMonster.size(); i++)
			{
				gotoxy(x, y);
				cout << i << "��. " << playerMonster[i]->Name << "  Level : " << playerMonster[i]->Level << endl;
				y += 2;
			}


			gotoxy(x, y + 2);
			cout << "��ü�� ���ϸ��� ��ȣ�� �����ϼ���( "<< playerMonster.size() << " ����) : ";
			int n = cinKey<int>();

			if (n > playerMonster.size()-1) //���Ͱ� 2������ ��� size = 3
			{
				if (n == playerMonster.size())
					break;

				continue;
			}
			else
			{
				monsterSwap.push_back(playerMonster[n]);
				monsterSwap[0] = playerMonster[0];
				playerMonster[0] = playerMonster[n];
				playerMonster[n] = monsterSwap[0];

				gotoxy(x, y+4);
				cout << "��ü �Ϸ�" << endl;
				monsterSwap.erase(monsterSwap.begin());
				Sleep(1000);
				break;
			}
		}
	}
}
//���� �ҽ�
void Market(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	int x = 10, y = 5;
	while (1)
	{
		gotoxy(x + 20, y + 30);
		cout << playerMonster[0]->Name << " Level( " << playerMonster[0]->Level << " )";
		gotoxy(x + 40, y + 30);
		cout << playerMonster[0]->Exp << " / " << playerMonster[0]->ExpMax;
		gotoxy(x + 20, y + 32);
		cout << "Gold : " << player.gold;
		gotoxy(x, y);
		cout << "�١ڡ١ڡ١ڡ١ڡ١� POKET ��ȭ�� �ڡ١ڡ١ڡ١ڡ١ڡ١ڡ�";
		gotoxy(x, y+3);
		cout << "1. ���ͺ� (80 Gold)";
		gotoxy(x, y + 5);
		cout << "2. �������� (10 Gold : 50ȸ��)";
		gotoxy(x, y + 7);
		cout << "3. ����ġ���� (50 Gold : 50����ġ)";
		gotoxy(x, y + 9);
		cout << "4. ����";
		gotoxy(x, y + 11);
		cout << "�Է� : ";
		int n = cinKey<int>();

		if (n < MK_MONBALL || n > MK_EXPBOX)
		{
			if (n == MK_END)
				break;

			continue;
		}

		if (n == MK_MONBALL)
		{
			if (player.gold >= 80)
			{
				player.gold -= 80;
				player.MonsterBall++;
				system("cls");
				gotoxy(23, 10);
				cout << "���������� �����߽��ϴ�." << endl;
				gotoxy(23, 12);
				cout << "���ͺ� ���� : " << player.MonsterBall << endl;
				Sleep(1000);
			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "���� �����մϴ�.";
				Sleep(500);
			}
		}
		else if (n == MK_POSITION)
		{
			if (player.gold >= 10)
			{
				player.gold -= 10;
				playerMonster[0]->Hp += 50;
				if (playerMonster[0]->Hp > playerMonster[0]->HpMax)
				{
					playerMonster[0]->Hp = playerMonster[0]->HpMax;
				}
				system("cls");
				gotoxy(23, 10);
				cout << playerMonster[0]->Name << "�� ü���� 50 ȸ���߽��ϴ�.";
				Sleep(1000);
			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "���� �����մϴ�.";
				Sleep(500);
			}
		}
		else if (n == MK_EXPBOX)
		{
			if (player.gold >= 50)
			{
				player.gold -= 50;
				playerMonster[0]->Exp += 50;
				while (playerMonster[0]->Exp >= playerMonster[0]->ExpMax)
				{
					playerMonster[0]->Exp -= playerMonster[0]->ExpMax;
					playerMonster[0]->Level++;
					playerMonster[0]->LevelUp(playerMonster);
				}
				gotoxy(x + 7, y + 11);
				cout << "����ġ 50�� ȹ���ϼ̽��ϴ�." << endl;
				Sleep(500);

			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "���� �����մϴ�.";
				Sleep(500);
			}
		}
		system("cls");
	}
}

//�κ� ȭ��
int lobby(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	while (1)
	{
		PlayPoketMon(playerMonster, player);

		int x = 10, y = 5;
		gotoxy(5, y);
		setColor(red, black);
		cout << "�ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ� �� �� ȭ �� �١ڡ١ڡ١ڡ١ڡ١ڡ١ڡ١�";
		setColor(white, black);
		gotoxy(x, y + 4);
		cout << "1. ����";
		gotoxy(x, y + 6);
		cout << "2. ����";
		gotoxy(x, y + 8);
		cout << "3. ���ϸ��� (" << playerMonster[0]->Level * 3 << "Gold)" << endl;
		gotoxy(x, y + 10);
		cout << "4. �κ��丮";
		gotoxy(x, y + 12);
		cout << "5. �����ϱ�";
		gotoxy(x, y + 14);
		cout << "6. ����";
		gotoxy(x, y + 16); //33 19
		cout << "�Է� : ";

		int n = cinKey<int>();
		getchar();

		if (n < MM_ADVENTURE || n > MM_SAVE)
		{
			if (n == MM_END)
			{
				return 0;
			}
			system("cls");
			continue;
		}
		//����
		if (n == MM_ADVENTURE)
		{
			system("cls");
			Adventure(player, playerMonster);
		}
		else if (n == MM_MARKET)
		{
			Market(player, playerMonster);
		}
		//���ϸ� ���� (ȸ��)
		else if (n == MM_POKETMONCENTER)
		{
			if (player.gold >= playerMonster[0]->Level * 3)
			{
				player.gold -= (playerMonster[0]->Level * 3);
				playerMonster[0]->Hp = playerMonster[0]->HpMax;
				gotoxy(x + 10, y + 14);
				cout << "���ϸ��� ȸ���Ǿ����ϴ�. " << endl;
				Sleep(1000);
			}
		}
		//�κ��丮
		else if (n == MM_INVENTORY)
		{
			system("cls");
			Inventory(playerMonster);
		}
		else if (n == MM_SAVE)
		{
			SAVE(player, playerMonster);
		}
		system("cls");
	}
}


//ó�� Ÿ��Ʋ ȭ��
void titleDraw()	// ó�� ���� Ÿ��Ʋ
{
	setColor(red, black);
	int x = 10;
	int y = 5;
	gotoxy(x, y);
	cout << "############ #######   # #  #######        #       #####    #\n";
	gotoxy(x, y + 1);
	cout << "   #    #          #   # #  #     #        #       #        #\n";
	gotoxy(x, y + 2);
	cout << "   #    #    #######   # #  #######       ##       #        #\n";
	gotoxy(x, y + 3);
	cout << "############       ##### #     #         #  #      #        #\n";
	gotoxy(x, y + 4);
	cout << "     #             #   # #  ########    #    #     ##### ####\n";
	gotoxy(x, y + 5);
	cout << "     #               #       #         #      #    #        #\n";
	gotoxy(x, y + 6);
	cout << "     #              # #      #                     #        #\n";
	gotoxy(x, y + 7);
	cout << "############       #   #     ######  ############# #####    #\n";
	setColor(white, black);
	gotoxy(50, 35);
	cout << "    W\n";
	gotoxy(50, 37);
	cout << "A   S   D   SPACE\n";
	
}

//Ű �Է� �ޱ� (ó�� ȭ�鿡���� ���� ����)
int GetKey()
{
	char key = _getch();
	
	if (key == 'w' || key == 'W') {
		return UP;
	}
	else if (key == 'a' || key == 'A') {
		return LEFT;
	}
	else if (key == 's' || key == 'S') {
		return DOWN;
	}
	else if (key == 'd' || key == 'D') {
		return RIGHT;
	}
	else if (key == ' ') {
		return SPACE;
	}
	else if (key == 'b' || key == 'B') {
		return EX_OUT;
	}
}

//Ÿ��Ʋ �޴� ����Ʈ
int titleMenu()
{
	int x = 35;
	int y = 20;
	gotoxy(x - 2, y); // >������ -2 ����
	cout << "> �� �� �� �� " << endl;
	gotoxy(x, y + 2);
	cout << "�� �� �� �� " << endl;
	gotoxy(x, y + 4);
	cout << "�� �� �� ��" << endl;
	gotoxy(x, y + 6);
	cout << "�� �� �� ��" << endl;
	while (1)
	{
		int n = GetKey();
		switch (n)
		{
		case UP:
			if (y > 20)
			{
				gotoxy(x - 2, y);
				cout << " ";
				y -= 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 26)
			{
				gotoxy(x - 2, y);
				cout << " ";
				y += 2;
				gotoxy(x - 2, y);
				cout << ">";
			}
			break;
		case SPACE:
			return y - 20;		// 0, 2, 4, 6 ���� ���� �� ����.
		}
	}
}

// �Է� �޴� ��
template <typename T>
T cinKey()
{
	T input;
	cin >> input;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		return cinKey<T>();
	}

	return input;
}

//���� ȭ�鿡�� ���ϸ�� �÷��̾� �����ֱ�
void PlayPoketMon(vector<Monster*> &plmon, Player &player)
{
	int x = 9;
	int y = 28;

	for (int i = 0; i < 80; i++)
	{
		setColor(red, red);
		gotoxy(i, 24);
		cout << "#";
	}
	for (int i = 0; i < 16; i++)
	{
		gotoxy(39, 24 + i);
		cout << "#";
		gotoxy(40, 24+i);
		cout << "#";
	}

	setColor(lightcyan, black);
	gotoxy(4, 26);
	cout << " �� �� Ʈ �� �� �� �� �� ";
	gotoxy(x, y);
	cout << "  �̸� : " << plmon[0]->Name;
	gotoxy(x, y + 2);
	cout << "  ���� : " << plmon[0]->Level;
	gotoxy(x, y + 4);
	cout << "���ݷ� : " << plmon[0]->Ad;
	gotoxy(x, y + 6);
	cout << "���� : " << plmon[0]->Dp;
	gotoxy(x, y + 8);
	cout << "  ü�� : " << plmon[0]->Hp << " / " << plmon[0]->HpMax;
	gotoxy(x, y + 10);
	cout << "����ġ : " << plmon[0]->Exp << " / " << plmon[0]->ExpMax;
	setColor(lightcyan, black);
	x = 54;
	gotoxy(52, 26);
	cout << " [ �� �� �� �� ] " << endl;
	gotoxy(x, y);
	cout << " �̸� : " << player.Name << endl;
	gotoxy(x, y + 2);
	cout << " GOLD : " << player.gold << " $" << endl;
	gotoxy(x-3, y + 4);
	cout << "���ͺ� : " << player.MonsterBall << " ��" <<endl;
	gotoxy(x - 3, y + 6);
	cout << "�κ��丮 : " << plmon.size() - 1  << " ��" << endl;
	setColor(white, black);
}


