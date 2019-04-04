#include "GameLoop.h"
#include "Player.h"
#include "Hero.h"
#include "Util.h"
#include "Stage.h"
#pragma warning (disable : 4996)

time_t startTime;

//영웅 추가
void HeroAdd(Player &player, list<Hero*> &hlist)
{
	int randomH = rand() % AddHeroMax;
	
	list<Hero*>::iterator hiter;
	hiter = hlist.begin();
	for (int i = 0; i < randomH; i++, hiter++) //랜덤 유닛이 나올동안 ++
	{
	}
	Hero* hero = new Hero;
	
	//새로 받아주기 (hero = (*hiter) 하니까 능력치 공유함 ;;)
	hero->Name = (*hiter)->Name;
	hero->Level = (*hiter)->Level;
	hero->Ad = (*hiter)->Ad;
	hero->Ap = (*hiter)->Ap;
	hero->Dp = (*hiter)->Dp;
	hero->Hp = (*hiter)->Hp;
	hero->HpMax = (*hiter)->HpMax;
	hero->Mp = (*hiter)->Mp;
	hero->MpMax = (*hiter)->MpMax;
	hero->Exp = (*hiter)->Exp;
	hero->ExpMax = (*hiter)->ExpMax;
	hero->giveExp = (*hiter)->giveExp;
	hero->giveGold = (*hiter)->giveGold;

	player.HeroInven.push_back(hero);
	system("cls");
	int x = 40, y = 15;
	setColor(lightblue, black);
	gotoxy(x, y);
	cout << "이름 : " << hero->Name << endl;
	gotoxy(x, y + 2);
	cout << "레벨 : " << hero->Level << endl;
	gotoxy(x, y + 4);
	cout << "공격력 : " << hero->Ad << endl;
	gotoxy(x, y + 6);
	cout << "마법공격력 : " << hero->Ap << endl;
	gotoxy(x, y + 8);
	cout << "방어력 : " << hero->Dp << endl;
	gotoxy(x, y + 10);
	cout << "체력 : " << hero->Hp << "/" << hero->HpMax << endl;
	gotoxy(x, y + 12);
	cout << "마나 : " << hero->Mp << "/" << hero->MpMax << endl;
	gotoxy(x, y + 14);
	setColor(white, black);
	system("pause");
}

//영웅 리스트
void HeroList(Player &player)
{
	list<Hero*>::iterator hiter;
	int i;
	while (1)
	{
		system("cls");
		for (i = 0, hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++, i++)
		{
			cout << i + 1 << ". 이름 : " << (*hiter)->Name << " 레벨 : " << (*hiter)->Level << endl << endl;
		}

		cout << "자세히 보기(종료-99) : ";
		int iSel = cinKey<int>();

		if (iSel < 1 || iSel > player.HeroInven.size())
		{
			if (iSel == 99)
				break;

			system("cls");
			continue;
		}
		hiter = player.HeroInven.begin();
		advance(hiter, iSel - 1);
		//for(int i = 0; i< (iSel-1); i++, hiter++)
		//{ }
		

		system("cls");
		int x = 40, y = 15;
		gotoxy(x, y);
		cout << "이름 : " << (*hiter)->Name << endl;
		gotoxy(x, y+2);
		cout << "레벨 : " << (*hiter)->Level << endl;
		gotoxy(x, y+4);
		cout << "공격력 : " << (*hiter)->Ad << endl;
		gotoxy(x, y+6);
		cout << "마법공격력 : " << (*hiter)->Ap << endl;
		gotoxy(x, y+8);
		cout << "방어력 : " << (*hiter)->Dp << endl;
		gotoxy(x, y+10);
		cout << "체력 : " << (*hiter)->Hp << "/" << (*hiter)->HpMax << endl;
		gotoxy(x, y+12);
		cout << "마나 : " << (*hiter)->Mp << "/" << (*hiter)->MpMax << endl;
		gotoxy(x, y + 14);
		cout << "경험치 : " << (*hiter)->Exp << "/" << (*hiter)->ExpMax << endl;
		gotoxy(x, y + 16);
		system("pause");
		
	}

	
}

//영웅 버리기
void HeroDel(Player &player)
{
	list<Hero*>::iterator hiter;
	int i;
	while (1)
	{
		system("cls");
		for (i = 0, hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++, i++)
		{
			cout << i + 1 << ". 이름 : " << (*hiter)->Name << " 레벨 : " << (*hiter)->Level << "  Gold : " << (*hiter)->giveGold*(*hiter)->Level << endl << endl;
		}

		cout << "버릴 캐릭터를 선택하세요(종료-99) : ";
		int iSel = cinKey<int>();

		if (iSel < 1 || iSel > player.HeroInven.size())
		{
			if (iSel == 99)
				break;

			system("cls");
			continue;
		}

		hiter = player.HeroInven.begin();
		advance(hiter, iSel - 1);
		//for (int i = 0; i < (iSel - 1); i++, hiter++)
		//{
		//}
		player.Gold += ((*hiter)->giveGold*(*hiter)->Level);
		cout << ((*hiter)->giveGold*(*hiter)->Level) << " Gold를 획득하셨습니다." << endl;
		Sleep(500);
		player.HeroInven.erase(hiter);
		
	}
}

//영웅 제물
void HeroOff(Player &player)
{
	list<Hero*>::iterator hiter;
	list<Hero*>::iterator hiter2;
	int i;
	while (1)
	{
		system("cls");
		for (i = 0, hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++, i++)
		{
			cout << i + 1 << ". 이름 : " << (*hiter)->Name << " 레벨 : " << (*hiter)->Level << "  Exp : " << (*hiter)->Exp << "/" << (*hiter)->ExpMax << endl << endl;
		}

		cout << "경험치를 올릴 캐릭터를 선택하세요(종료-99) : ";
		int iSel1 = cinKey<int>();

		if (iSel1 < 1 || iSel1 > player.HeroInven.size())
		{
			if (iSel1 == 99)
				break;

			system("cls");
			continue;
		}

		cout << "제물 캐릭터를 선택하세요(종료-99) : ";
		int iSel2 = cinKey<int>();

		if (iSel2 < 1 || iSel2 > player.HeroInven.size())
		{
			if (iSel2 == 99)
				break;

			system("cls");
			continue;
		}


		hiter = player.HeroInven.begin();
		advance(hiter, iSel1 - 1);
		//for (int i = 0; i < (iSel1 - 1); i++, hiter++)
		//{}

		hiter2 = player.HeroInven.begin();
		advance(hiter2, iSel2 - 1);
		//for (int i = 0; i < (iSel2 - 1); i++, hiter2++)
		//{}

		(*hiter)->Exp += ( (*hiter2)->giveExp * (*hiter2)->Level );
		while ((*hiter)->ExpMax <= (*hiter)->Exp)
		{
			(*hiter)->LevelUp(*hiter);
			(*hiter)->Exp = 0;
		}

		player.HeroInven.erase(hiter2);

	}
}

//영웅 조합
void HeroFusion(Player &player)
{
	system("cls");
	// 조합 할 수 있는 목록을 보여준다.
	int count = 0;
	int count2 = 0;
	int fusionCount[HeroMax] = { 0, };

	list<Hero*>::iterator hiter;

	for (hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++)
	{
		if ((*hiter)->Name == "고블린")
		{
			fusionCount[Goblin]++;
		}
		else if ((*hiter)->Name == "슬라임")
		{
			fusionCount[Slime]++;
		}
		else if ((*hiter)->Name == "스켈레톤")
		{
			fusionCount[Skeleton]++;
		}
		else if ((*hiter)->Name == "페어리")
		{
			fusionCount[Fairy]++;
		}
		else if ((*hiter)->Name == "인간병사")
		{
			fusionCount[soldier]++;
		}
	}

	cout << "조합 가능한 유닛 : " << endl;
	if (fusionCount[Goblin] >= 2)	{	cout << "고블린전사 ";	}
	if (fusionCount[Slime] >= 2)	{	cout << " 산성슬라임 ";	}
	if (fusionCount[Skeleton] >= 2)	{	cout << " 스켈레톤워리어 ";	}
	if (fusionCount[Fairy] >= 2)	{	cout << " 붉은페어리 ";	}
	if (fusionCount[soldier] >= 2)	{	cout << " 기사 ";	}
	if (fusionCount[Fairy] >= 1 && fusionCount[soldier] >= 1)	{	cout << " 견습마법사 ";	}

	cout << "조합할 유닛 이름을 입력하세요 : ";
	string N = cinKey<string>();
	
	//고블린전사 조합
	if (N == "고블린전사" && fusionCount[Goblin] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "고블린")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "고블린전사 추가" << endl;
		Hero* hero = new Hero("고블린전사", 1,50, 50, 15, 15, 10, 5, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "산성슬라임" && fusionCount[Slime] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "슬라임")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "산성슬라임 추가" << endl;
		Hero* hero = new Hero("산성슬라임", 1, 60, 60, 20, 20, 8, 8, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "스켈레톤워리어" && fusionCount[Skeleton] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "스켈레톤")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "스켈레톤워리어 추가" << endl;
		Hero* hero = new Hero("스켈레톤워리어", 1, 70, 70, 20, 20, 15, 5, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "붉은페어리" && fusionCount[Fairy] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "페어리")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "붉은페어리 추가" << endl;
		Hero* hero = new Hero("붉은페어리", 1, 40, 40, 30, 30, 5, 12, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "기사" && fusionCount[soldier] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "인간병사")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "기사 추가" << endl;
		Hero* hero = new Hero("기사", 1, 60, 60, 20, 20, 12, 10, 4);
		player.HeroInven.push_back(hero);
	}
	else if (N == "견습마법사" && fusionCount[Fairy] >= 1 && fusionCount[soldier] >= 1)
	{
	hiter = player.HeroInven.begin();
	while (hiter != player.HeroInven.end())
	{
		if ((*hiter)->Name == "인간병사" && count < 1)
		{
			player.HeroInven.erase(hiter++);
			count++;
			if (count == 1)
				continue;
		}
		if ((*hiter)->Name == "페어리" && count2 < 1)
		{
			player.HeroInven.erase(hiter++);
			count++;
			if (count2 == 1)
				continue;
		}
		
		hiter++;
	}
		cout << "견습마법사 추가" << endl;
		Hero* hero = new Hero("견습마법사", 1, 40, 40, 30, 30, 5, 15, 3);
		player.HeroInven.push_back(hero);

	}
	else
	{
		cout << "잘못입력하셨습니다." << endl;
	}


	cout << endl;
	system("pause");
}

int StartMenu(Player &player)
{
	list<Hero*> hlist;
	//list<Hero*>::iterator hiter;
	Hero* rHero = new Hero;
	rHero->HeroSetting(hlist);
	Stage* stage = new Stage;

	/*for (hiter = hlist.begin(); hiter != hlist.end(); hiter++)
	{
		cout << (*hiter)->Name << endl;
	}
	system("pause");*/

	int iMenu = 0;
	int x = 43, y = 20;
	while (1)
	{
		gotoxy(0, 0);
		cout << "이름 : " << player.Name << endl;
		gotoxy(0, 2);
		cout << "현재 잔액 : " << player.Gold << endl;

		Title();

		gotoxy(x, y);
		cout << "1. Stroy Mode";
		gotoxy(x, y+2);
		cout << "2. 영웅 뽑기 (10 Gold)";
		gotoxy(x, y+4);
		cout << "3. 영웅 리스트 보기";
		gotoxy(x, y + 6);
		cout << "4. 영웅 조합";
		gotoxy(x, y + 8);
		cout << "5. 영웅 버리기";
		gotoxy(x, y + 10);
		cout << "6. 영웅 제물";
		gotoxy(x, y + 12);
		cout << "7. 조합법";
		gotoxy(x, y + 14);
		cout << "8. 종료";
		gotoxy(x, y + 16);
		cout << "입력 : ";
		iMenu = cinKey<int>();
		getchar();

		if (iMenu <= SM_NONE || iMenu >= SM_END)
		{
			if (SM_END == iMenu)
				break;

			continue;
		}

		if (iMenu == SM_Stroy)						//뭘 만들지 고민
		{
			time(&startTime);
			stage->RoundStart(player);
		}
		else if(iMenu == SM_ADD)				// 영웅 추가
		{
			if (player.Gold >= 10)
			{
				player.Gold -= 10;
				HeroAdd(player, hlist);
				Save(player);
			}
		}
		else if (iMenu == SM_LIST)				// 영웅 보기
		{
			HeroList(player);
			Save(player);
		}
		else if (iMenu == SM_FUSION)			// 영웅 조합
		{
			HeroFusion(player);
			Save(player);
		}
		else if (iMenu == SM_DEL)				// 영웅 버리기 (돈 획득)
		{
			HeroDel(player);
			Save(player);
		}
		else if (iMenu == SM_Offerings)			// 영웅 제물 (경험치 제물)
		{
			HeroOff(player);
			Save(player);
		}
		else if (iMenu == SM_FINFO)				// 조합법 보기
		{
			FusionInfo();
		}


		system("cls");
	}

	return 0;
}

//string Name;
//int Level;
//int Hp;
//int HpMax;
//int Mp;
//int MpMax;
//int Ad;
//int Ap;
//int Dp;
//int Exp;
//int ExpMax;
//int giveGold;
//int giveExp;

void Save(Player &player)
{
	FILE* wfp;

	fopen_s(&wfp, "Save.txt", "wt");
	

	if (wfp != NULL)
	{
		int Round = Stage::Round;

		fprintf_s(wfp, "%d\n", Round);
		fprintf_s(wfp, "%d\n", player.HeroInven.size());
		fprintf_s(wfp, "%s %d\n", player.Name.c_str(), player.Gold);
		list<Hero*>::iterator iter;
		for (iter = player.HeroInven.begin(); iter != player.HeroInven.end(); iter++)
		{
			fprintf_s(wfp, "%s %d %d %d %d %d %d %d %d %d %d %d %d\n",
				(*iter)->Name.c_str(), (*iter)->Level, (*iter)->Hp, (*iter)->HpMax, (*iter)->Mp, (*iter)->MpMax,
				(*iter)->Ad, (*iter)->Ap, (*iter)->Dp, (*iter)->Exp, (*iter)->ExpMax, (*iter)->giveGold, (*iter)->giveExp);
		}

		fclose(wfp);
	}
	else // 실패
	{

	}
}

void Load(Player &player)
{
	FILE* rfp;

	fopen_s(&rfp, "Save.txt", "rt");
	int Round = 0;
	int size = 0;
	Hero* hero = new Hero;
	if (rfp != NULL)
	{
		fscanf_s(rfp, "%d", &Round);
		Stage::Round = Round;
		fscanf_s(rfp, "%d", &size);
		char Name[128];
		fscanf_s(rfp, "%s %d", Name, sizeof(Name),&player.Gold);
		player.Name = Name;

		for (int i = 0; i < size; i++)
		{
			hero = new Hero;
			fscanf_s(rfp, "%s %d %d %d %d %d %d %d %d %d %d %d %d", Name,sizeof(Name),
				&hero->Level, &hero->Hp, &hero->HpMax, &hero->Mp, &hero->MpMax,
				&hero->Ad, &hero->Ap, &hero->Dp, &hero->Exp, &hero->ExpMax, &hero->giveGold, &hero->giveExp);
			hero->Name = Name;
			player.HeroInven.push_back(hero);
		}

		fclose(rfp);
	}
	else
	{

	}
}



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

