#include "util.h"
#include "Game.h"

//플레이어, 적 공격 모션
void AttackMotion(int n)
{
	if (n == 0) // 플레이어 공격
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
	else if (n == 1) // 적 공격
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

//1. 몬스터와 싸우는 코드
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
		cout << "[ 플레이어 몬스터 ]" << endl;
		gotoxy(x, y);
		cout << "  이름 : " << playerMonster[0]->Name;
		gotoxy(x, y + 2);
		cout << "  레벨 : " << playerMonster[0]->Level;
		gotoxy(x, y + 4);
		cout << "공격력 : " << playerMonster[0]->Ad;
		gotoxy(x, y + 6);
		cout << "방어력 : " << playerMonster[0]->Dp;
		gotoxy(x, y + 8);
		cout << "  체력 : " << playerMonster[0]->Hp << " / " << playerMonster[0]->HpMax;
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
		cout << "[ 적 몬스터 ]" << endl;
		gotoxy(x, y);
		cout << "  이름 : " << EnemyMonster[Random]->Name;
		gotoxy(x, y + 2);
		cout << "  레벨 : " << EnemyMonster[Random]->Level;
		gotoxy(x, y + 4);
		cout << "공격력 : " << EnemyMonster[Random]->Ad;
		gotoxy(x, y + 6);
		cout << "방어력 : " << EnemyMonster[Random]->Dp;
		gotoxy(x, y + 8);
		cout << "  체력 : " << EnemyMonster[Random]->Hp << " / " << EnemyMonster[Random]->HpMax;
		gotoxy(x, y + 10);
		int px = 3, mx = 30;
		setColor(white, black);

		//플레이어 공격
		
		int playerDamage = (playerMonster[0]->Ad - EnemyMonster[Random]->Dp); //플레이어 데미지

		if (playerMonster[0]->skillCount == 3) //스킬 사용 (쿨타임 3턴)
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

		if (playerCri <= 10) // 치명타 발생 (플레이어)
		{
			gotoxy(px, py);
			cout << "치명타!!";
			playerDamage *= 1.5;
			Sleep(300);
			gotoxy(px, py);
			cout << "          ";
		}
		

		if (playerDamage <= 0)
		{
			AttackMotion(0);

			EnemyMonster[Random]->Hp -= 1; // 데미지가 0보다 작으면 1데미지
			gotoxy(px, py);
			cout << playerMonster[0]->Name << "가 " << EnemyMonster[Random]->Name << "에게 " << "1의 피해를 입혔습니다.";
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
			cout << playerMonster[0]->Name << "가 " << EnemyMonster[Random]->Name << "에게 " << playerDamage << "의 피해를 입혔습니다.";
			Sleep(1000);
			gotoxy(px, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
			//Sleep(500);
		}

		if (EnemyMonster[Random]->Hp <= 0) // 적 사망 처리
		{
			EnemyMonster[Random]->Hp = 0;
			gotoxy(57, 10);
			cout << "                           ";
			gotoxy(57, 10);
			setColor(lightpurple, black);
			cout << "  체력 : " << '0' << " / " << '0';
			setColor(white, black);
			gotoxy(px + 10, py + 3);
			cout << EnemyMonster[Random]->Name <<"가(이) 사망하였습니다." << endl;
			gotoxy(px + 10, py + 5);
			cout << EnemyMonster[Random]->giveExp << "Exp 획득" << endl;
			playerMonster[0]->Exp += EnemyMonster[Random]->giveExp;
			while (playerMonster[0]->Exp >= playerMonster[0]->ExpMax)
			{
				playerMonster[0]->Exp -= playerMonster[0]->ExpMax;
				playerMonster[0]->Level++;
				gotoxy(px + 10, py + 7);
				cout << playerMonster[0]->Name << "가 레벨 " << playerMonster[0]->Level << "이 되었습니다" << endl;
				playerMonster[0]->Hp = playerMonster[0]->HpMax;
				playerMonster[0]->LevelUp(playerMonster);
				py += 2;
			}
			gotoxy(px + 10, py + 2);
			system("pause");
			EnemyMonster[Random]->Hp = EnemyMonster[Random]->HpMax; // 저장되어 있는 몬스터 체력 다시 원상복귀
			return;
		}

		//적의 공격
		int EnemyDamage = (EnemyMonster[Random]->Ad - playerMonster[0]->Dp);

		if (EnemyMonster[Random]->skillCount == 3) //적 몹 스킬 사용 (쿨타임 3턴)
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
			cout << "치명타!!";
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
			cout << EnemyMonster[Random]->Name << "가 " << playerMonster[0]->Name << "에게 1의 피해를 입혔습니다.";
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
			cout << EnemyMonster[Random]->Name << "가 " << playerMonster[0]->Name << "에게 " << EnemyDamage << "의 피해를 입혔습니다.";
			Sleep(1000);
			gotoxy(mx, py);
			cout << "                                                            ";
			//Sleep(500);
			//py++;
		}
		if (playerMonster[0]->Hp <= 0) // 플레이어 사망 처리
		{
			playerMonster[0]->Hp = 0;
			gotoxy(px + 10, py + 3);
			cout << playerMonster[0]->Name << "가 사망하였습니다." << endl;
			gotoxy(px + 10, py + 5);
			system("pause");
			return;
		}
		system("cls");
	}
}

//3 몬스터볼
int MonsterBall(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int RandomMonster, Player &player)
{
	int monsterGet = rand() % 10 + 1;
	if (playerMonster.size() < 11)
	{
		if (player.MonsterBall > 0)
		{
			player.MonsterBall--;
			if (monsterGet <= 3) // 30퍼센트 확률
			{
				playerMonster.push_back(EnemyMonster[RandomMonster]);
				cout << EnemyMonster[RandomMonster]->Name << "을 잡았다~!!" << endl;
				Sleep(1000);
				system("cls");
				int x = 30, y = 5;
				gotoxy(x, y - 2);
				cout << "[ 잡은 몬스터 ]" << endl;
				gotoxy(x, y);
				cout << "  이름 : " << EnemyMonster[RandomMonster]->Name;
				gotoxy(x, y + 2);
				cout << "  레벨 : " << EnemyMonster[RandomMonster]->Level;
				gotoxy(x, y + 4);
				cout << "공격력 : " << EnemyMonster[RandomMonster]->Ad;
				gotoxy(x, y + 6);
				cout << "방어력 : " << EnemyMonster[RandomMonster]->Dp;
				gotoxy(x, y + 8);
				cout << "  체력 : " << EnemyMonster[RandomMonster]->Hp << " / " << EnemyMonster[RandomMonster]->HpMax;
				gotoxy(x, y + 10);
				Sleep(1000);
				return 0;
			}
			else
			{
				cout << "못잡았다." << endl;
				Sleep(1000);
				return 1;
			}
		}
		else
		{
			cout << "몬스터볼이 없다. " << endl;
			Sleep(1000);
			return 1;
		}
	}
	else
	{
		cout << "인벤토리가 꽉찼습니다." << endl;
		Sleep(1000);
		return 1;
	}
}

//태초 마을 선택시 몬스터가 나왔을 때
void battle(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, Player &player, int number)
{
	int RandomMonster = rand() % EnemyMonster.size();
	while (1)
	{
		system("cls");
		setColor(lightblue, black);
		int x = 3, y = 2;
		gotoxy(3, 0);
		cout << "[ 플레이어 몬스터 ]" << endl;
		gotoxy(x, y);
		cout << "  이름 : " << playerMonster[0]->Name;
		gotoxy(x, y + 2);
		cout << "  레벨 : " << playerMonster[0]->Level;
		gotoxy(x, y + 4);
		cout << "공격력 : " << playerMonster[0]->Ad;
		gotoxy(x, y + 6);
		cout << "방어력 : " << playerMonster[0]->Dp;
		gotoxy(x, y + 8);
		cout << "  체력 : " << playerMonster[0]->Hp << " / " << playerMonster[0]->HpMax;
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
		cout << "[ 적 몬스터 ]" << endl;
		gotoxy(x, y);
		cout << "  이름 : " << EnemyMonster[RandomMonster]->Name;
		gotoxy(x, y + 2);
		cout << "  레벨 : " << EnemyMonster[RandomMonster]->Level;
		gotoxy(x, y + 4);
		cout << "공격력 : " << EnemyMonster[RandomMonster]->Ad;
		gotoxy(x, y + 6);
		cout << "방어력 : " << EnemyMonster[RandomMonster]->Dp;
		gotoxy(x, y + 8);
		cout << "  체력 : " << EnemyMonster[RandomMonster]->Hp << " / " << EnemyMonster[RandomMonster]->HpMax;
		gotoxy(x, y + 10);

		x = 50;
		y = 30;
		setColor(white, black);

		gotoxy(x, y);
		cout << "1. 싸운다" << endl;
		gotoxy(x, y+2);
		cout << "2. 도망간다" << endl;
		gotoxy(x, y+4);
		cout << "3. 몬스터볼" << endl;
		gotoxy(x, y + 6);
		cout << "입력 : ";
		int n = cinKey<int>();

		if (n < MB_BATTLE || n > MB_MONSTERCATCH)
		{
			continue;
		}

		if (n == MB_BATTLE) // 싸운다
		{
			Dual(playerMonster, EnemyMonster, RandomMonster);
			if (number == 1 && playerMonster[0]->Hp > 0)
			{
				int RandomGold = rand() % 100 + 1;
				player.gold += RandomGold;
				system("cls");
				gotoxy(23, 10);
				cout << "플레이어가 " << RandomGold << "골드를 획득했습니다." << endl;
				Sleep(1000);
			}
			break;
		}
		else if (n == MB_ESCAPE) // 도망간다
		{
			return;
		}
		else if (n == MB_MONSTERCATCH) // 몬스터볼
		{
			if (number == 0) // 트레이너와 싸움은 몬스터볼 못던짐
			{
				int ball = MonsterBall(playerMonster, EnemyMonster, RandomMonster, player);
				if (ball == 0) //몬스터 잡음
				{
					break;
				}
				else if (ball == 1) //못잡음
				{

				}
			}
		}

	}
}

//몬스터 트레이닝 소스
void training(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	gotoxy(60, 0);
	cout << "현재 GOLD : " << player.gold;
	gotoxy(23, 15);
	cout << "포켓몬을 훈련시키겠습니까? (100 Gold)" << endl;
	int x = 23, y = 17;
	gotoxy(x - 2, y);
	cout << "> 네, 훈련을 받겠습니다." << endl;
	gotoxy(x, y + 2);
	cout << "아니요, 돈이 없습니다. ㅠㅠ" << endl;

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
					if (Random == 0) // hp 상승
					{
						playerMonster[0]->HpMax += 10;
						gotoxy(23, 15);
						cout << "최대 체력이 10 상승합니다." << endl;
						Sleep(500);
					}
					else if (Random == 1) // ad 상승
					{
						playerMonster[0]->Ad += 1;
						gotoxy(23, 15);
						cout << "공격력이 1 상승합니다." << endl;
						Sleep(500);
					}
					else if (Random == 2) // dp 상승
					{
						playerMonster[0]->Dp += 1;
						gotoxy(23, 15);
						cout << "방어력이 1 상승합니다." << endl;
						Sleep(500);
					}
				}
				else
				{
					system("cls");
					gotoxy(23, 15);
					cout << "돈이 없습니다. ㅠㅠ" << endl;
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



//아이템 줍기 소스
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
		cout << playerMonster[0]->Name << "가 열매를 먹어 25의 체력을 회복했습니다." << endl;
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
		cout << playerMonster[0]->Name << "가 빨간포션를 먹어 50의 체력을 회복했습니다." << endl;
		Sleep(800);
	}
	else if (Random == 2)
	{
		itemMotion();
		int MoneyGet = rand() % 50 + 1;
		gotoxy(23, 15);
		cout << MoneyGet << "Gold를 주웠다,, 행복하다." << endl;
		player.gold += MoneyGet;
		Sleep(800);
	}
	else if (Random == 3)
	{
		itemMotion();
		int MoneyGet = rand() % 50 + 1;
		gotoxy(23, 15);
		cout << MoneyGet << "Gold를 주웠다,, 행복하다." << endl;
		player.gold += MoneyGet;
		Sleep(800);
	}
	else if (Random == 4)
	{
		itemMotion();
		gotoxy(23, 15);
		cout << "몬스터볼을 주웠다. 행복하다.";
		player.MonsterBall += 1;
		Sleep(800);
	}
}

//맵 선택
void FirstMap(Player &player, vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster)
{
	int Random = rand() % 4;
	AdventureMotion();
	if (Random == 0)
	{
		//포켓몬과 대전
		battle(playerMonster, EnemyMonster, player, 0);
	}
	else if (Random == 1)
	{
		//포켓몬과 대전
		battle(playerMonster, EnemyMonster, player, 0);
	}
	else if (Random == 2)
	{
		//포켓몬 트레이닝
		training(player, playerMonster);
	}
	else if (Random == 3)
	{
		//아이템 획득 (효과는 ??) -- 1. 체력 회복   2. 돈 줍기
		ItemGet(player, playerMonster);
	}
}

void trainer(Player &player, vector<Monster*> &playerMonster)
{
	vector<Monster*> trainerMonsterList;
	Monster *trainerMonster = new Monster[3]; //나중에 수정
	TrinerMonsterSetting(trainerMonsterList, trainerMonster, playerMonster);
	int RandomGold = rand() % 100 + 1;

	battle(playerMonster, trainerMonsterList, player, 1);
	
}

//모험 소스
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
			cout << "1. 태초 마을(1~5)  " << endl;
		}
		else if (count == 1)
		{
			cout << "2. 블루 마을(6~10) ";
		}
		else if (count == 2)
		{
			cout << "3. 그린 마을(11~16)" << endl;
		}
		else if (count == 3)
		{
			cout << "4. 트레이너와 결투" << endl;
		}
		gotoxy(30, 12);
		cout << "마을 넘기기(D키), 선택(SPACE)";
		gotoxy(30, 14);
		cout << "뒤로가기(B키)";

		int n = GetKey();

		if (n == RIGHT) // 마을 넘기기
		{
			count++;
			if (count > 3)
				count = 0;
		}
		else if (n == SPACE)
		{
			if (playerMonster[0]->Hp > 0)
			{
				if (count == 0) //태초 마을 선택
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
				cout << playerMonster[0]->Name << "가 체력이 없습니다." << endl;
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
		if (playerMonster.size() <= 1) //장착 몬스터만 있음..
		{
			cout << "인벤토리에 몬스터가 없습니다." << endl;
			Sleep(1000);
			return;
		}
		else
		{
			gotoxy(60, 35);
			cout << playerMonster.size()-1 << " / " << 10 << endl;

			gotoxy(30, 5);
			cout << "[ 인 벤 토 리 ]";
			int x = 30, y = 7;
			for (int i = 1; i < playerMonster.size(); i++)
			{
				gotoxy(x, y);
				cout << i << "번. " << playerMonster[i]->Name << "  Level : " << playerMonster[i]->Level << endl;
				y += 2;
			}


			gotoxy(x, y + 2);
			cout << "교체할 포켓몬의 번호를 선택하세요( "<< playerMonster.size() << " 종료) : ";
			int n = cinKey<int>();

			if (n > playerMonster.size()-1) //몬스터가 2마리일 경우 size = 3
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
				cout << "교체 완료" << endl;
				monsterSwap.erase(monsterSwap.begin());
				Sleep(1000);
				break;
			}
		}
	}
}
//마켓 소스
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
		cout << "☆★☆★☆★☆★☆★ POKET 백화점 ★☆★☆★☆★☆★☆★☆";
		gotoxy(x, y+3);
		cout << "1. 몬스터볼 (80 Gold)";
		gotoxy(x, y + 5);
		cout << "2. 빨간포션 (10 Gold : 50회복)";
		gotoxy(x, y + 7);
		cout << "3. 경험치상자 (50 Gold : 50경험치)";
		gotoxy(x, y + 9);
		cout << "4. 종료";
		gotoxy(x, y + 11);
		cout << "입력 : ";
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
				cout << "정상적으로 구매했습니다." << endl;
				gotoxy(23, 12);
				cout << "몬스터볼 개수 : " << player.MonsterBall << endl;
				Sleep(1000);
			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "돈이 부족합니다.";
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
				cout << playerMonster[0]->Name << "가 체력을 50 회복했습니다.";
				Sleep(1000);
			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "돈이 부족합니다.";
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
				cout << "경험치 50을 획득하셨습니다." << endl;
				Sleep(500);

			}
			else
			{
				gotoxy(x + 7, y + 11);
				cout << "돈이 부족합니다.";
				Sleep(500);
			}
		}
		system("cls");
	}
}

//로비 화면
int lobby(Player &player, vector<Monster*> &playerMonster)
{
	system("cls");
	while (1)
	{
		PlayPoketMon(playerMonster, player);

		int x = 10, y = 5;
		gotoxy(5, y);
		setColor(red, black);
		cout << "★☆★☆★☆★☆★☆★☆★☆ 메 인 화 면 ☆★☆★☆★☆★☆★☆★☆★";
		setColor(white, black);
		gotoxy(x, y + 4);
		cout << "1. 모험";
		gotoxy(x, y + 6);
		cout << "2. 상점";
		gotoxy(x, y + 8);
		cout << "3. 포켓몬센터 (" << playerMonster[0]->Level * 3 << "Gold)" << endl;
		gotoxy(x, y + 10);
		cout << "4. 인벤토리";
		gotoxy(x, y + 12);
		cout << "5. 저장하기";
		gotoxy(x, y + 14);
		cout << "6. 종료";
		gotoxy(x, y + 16); //33 19
		cout << "입력 : ";

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
		//모험
		if (n == MM_ADVENTURE)
		{
			system("cls");
			Adventure(player, playerMonster);
		}
		else if (n == MM_MARKET)
		{
			Market(player, playerMonster);
		}
		//포켓몬 센터 (회복)
		else if (n == MM_POKETMONCENTER)
		{
			if (player.gold >= playerMonster[0]->Level * 3)
			{
				player.gold -= (playerMonster[0]->Level * 3);
				playerMonster[0]->Hp = playerMonster[0]->HpMax;
				gotoxy(x + 10, y + 14);
				cout << "포켓몬이 회복되었습니다. " << endl;
				Sleep(1000);
			}
		}
		//인벤토리
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


//처음 타이틀 화면
void titleDraw()	// 처음 시작 타이틀
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

//키 입력 받기 (처음 화면에서만 받을 꺼임)
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

//타이틀 메뉴 리스트
int titleMenu()
{
	int x = 35;
	int y = 20;
	gotoxy(x - 2, y); // >때문에 -2 해줌
	cout << "> 게 임 시 작 " << endl;
	gotoxy(x, y + 2);
	cout << "이 어 하 기 " << endl;
	gotoxy(x, y + 4);
	cout << "게 임 정 보" << endl;
	gotoxy(x, y + 6);
	cout << "게 임 종 료" << endl;
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
			return y - 20;		// 0, 2, 4, 6 값을 받을 수 있음.
		}
	}
}

// 입력 받는 것
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

//메인 화면에서 포켓몬과 플레이어 보여주기
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
	cout << " ※ 파 트 너 포 켓 몬 ※ ";
	gotoxy(x, y);
	cout << "  이름 : " << plmon[0]->Name;
	gotoxy(x, y + 2);
	cout << "  레벨 : " << plmon[0]->Level;
	gotoxy(x, y + 4);
	cout << "공격력 : " << plmon[0]->Ad;
	gotoxy(x, y + 6);
	cout << "방어력 : " << plmon[0]->Dp;
	gotoxy(x, y + 8);
	cout << "  체력 : " << plmon[0]->Hp << " / " << plmon[0]->HpMax;
	gotoxy(x, y + 10);
	cout << "경험치 : " << plmon[0]->Exp << " / " << plmon[0]->ExpMax;
	setColor(lightcyan, black);
	x = 54;
	gotoxy(52, 26);
	cout << " [ 플 레 이 어 ] " << endl;
	gotoxy(x, y);
	cout << " 이름 : " << player.Name << endl;
	gotoxy(x, y + 2);
	cout << " GOLD : " << player.gold << " $" << endl;
	gotoxy(x-3, y + 4);
	cout << "몬스터볼 : " << player.MonsterBall << " 개" <<endl;
	gotoxy(x - 3, y + 6);
	cout << "인벤토리 : " << plmon.size() - 1  << " 개" << endl;
	setColor(white, black);
}


