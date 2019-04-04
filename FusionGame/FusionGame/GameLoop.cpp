#include "GameLoop.h"
#include "Player.h"
#include "Hero.h"
#include "Util.h"
#include "Stage.h"
#pragma warning (disable : 4996)

time_t startTime;

//���� �߰�
void HeroAdd(Player &player, list<Hero*> &hlist)
{
	int randomH = rand() % AddHeroMax;
	
	list<Hero*>::iterator hiter;
	hiter = hlist.begin();
	for (int i = 0; i < randomH; i++, hiter++) //���� ������ ���õ��� ++
	{
	}
	Hero* hero = new Hero;
	
	//���� �޾��ֱ� (hero = (*hiter) �ϴϱ� �ɷ�ġ ������ ;;)
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
	cout << "�̸� : " << hero->Name << endl;
	gotoxy(x, y + 2);
	cout << "���� : " << hero->Level << endl;
	gotoxy(x, y + 4);
	cout << "���ݷ� : " << hero->Ad << endl;
	gotoxy(x, y + 6);
	cout << "�������ݷ� : " << hero->Ap << endl;
	gotoxy(x, y + 8);
	cout << "���� : " << hero->Dp << endl;
	gotoxy(x, y + 10);
	cout << "ü�� : " << hero->Hp << "/" << hero->HpMax << endl;
	gotoxy(x, y + 12);
	cout << "���� : " << hero->Mp << "/" << hero->MpMax << endl;
	gotoxy(x, y + 14);
	setColor(white, black);
	system("pause");
}

//���� ����Ʈ
void HeroList(Player &player)
{
	list<Hero*>::iterator hiter;
	int i;
	while (1)
	{
		system("cls");
		for (i = 0, hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++, i++)
		{
			cout << i + 1 << ". �̸� : " << (*hiter)->Name << " ���� : " << (*hiter)->Level << endl << endl;
		}

		cout << "�ڼ��� ����(����-99) : ";
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
		cout << "�̸� : " << (*hiter)->Name << endl;
		gotoxy(x, y+2);
		cout << "���� : " << (*hiter)->Level << endl;
		gotoxy(x, y+4);
		cout << "���ݷ� : " << (*hiter)->Ad << endl;
		gotoxy(x, y+6);
		cout << "�������ݷ� : " << (*hiter)->Ap << endl;
		gotoxy(x, y+8);
		cout << "���� : " << (*hiter)->Dp << endl;
		gotoxy(x, y+10);
		cout << "ü�� : " << (*hiter)->Hp << "/" << (*hiter)->HpMax << endl;
		gotoxy(x, y+12);
		cout << "���� : " << (*hiter)->Mp << "/" << (*hiter)->MpMax << endl;
		gotoxy(x, y + 14);
		cout << "����ġ : " << (*hiter)->Exp << "/" << (*hiter)->ExpMax << endl;
		gotoxy(x, y + 16);
		system("pause");
		
	}

	
}

//���� ������
void HeroDel(Player &player)
{
	list<Hero*>::iterator hiter;
	int i;
	while (1)
	{
		system("cls");
		for (i = 0, hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++, i++)
		{
			cout << i + 1 << ". �̸� : " << (*hiter)->Name << " ���� : " << (*hiter)->Level << "  Gold : " << (*hiter)->giveGold*(*hiter)->Level << endl << endl;
		}

		cout << "���� ĳ���͸� �����ϼ���(����-99) : ";
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
		cout << ((*hiter)->giveGold*(*hiter)->Level) << " Gold�� ȹ���ϼ̽��ϴ�." << endl;
		Sleep(500);
		player.HeroInven.erase(hiter);
		
	}
}

//���� ����
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
			cout << i + 1 << ". �̸� : " << (*hiter)->Name << " ���� : " << (*hiter)->Level << "  Exp : " << (*hiter)->Exp << "/" << (*hiter)->ExpMax << endl << endl;
		}

		cout << "����ġ�� �ø� ĳ���͸� �����ϼ���(����-99) : ";
		int iSel1 = cinKey<int>();

		if (iSel1 < 1 || iSel1 > player.HeroInven.size())
		{
			if (iSel1 == 99)
				break;

			system("cls");
			continue;
		}

		cout << "���� ĳ���͸� �����ϼ���(����-99) : ";
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

//���� ����
void HeroFusion(Player &player)
{
	system("cls");
	// ���� �� �� �ִ� ����� �����ش�.
	int count = 0;
	int count2 = 0;
	int fusionCount[HeroMax] = { 0, };

	list<Hero*>::iterator hiter;

	for (hiter = player.HeroInven.begin(); hiter != player.HeroInven.end(); hiter++)
	{
		if ((*hiter)->Name == "���")
		{
			fusionCount[Goblin]++;
		}
		else if ((*hiter)->Name == "������")
		{
			fusionCount[Slime]++;
		}
		else if ((*hiter)->Name == "���̷���")
		{
			fusionCount[Skeleton]++;
		}
		else if ((*hiter)->Name == "��")
		{
			fusionCount[Fairy]++;
		}
		else if ((*hiter)->Name == "�ΰ�����")
		{
			fusionCount[soldier]++;
		}
	}

	cout << "���� ������ ���� : " << endl;
	if (fusionCount[Goblin] >= 2)	{	cout << "������� ";	}
	if (fusionCount[Slime] >= 2)	{	cout << " �꼺������ ";	}
	if (fusionCount[Skeleton] >= 2)	{	cout << " ���̷�������� ";	}
	if (fusionCount[Fairy] >= 2)	{	cout << " ������ ";	}
	if (fusionCount[soldier] >= 2)	{	cout << " ��� ";	}
	if (fusionCount[Fairy] >= 1 && fusionCount[soldier] >= 1)	{	cout << " �߽������� ";	}

	cout << "������ ���� �̸��� �Է��ϼ��� : ";
	string N = cinKey<string>();
	
	//������� ����
	if (N == "�������" && fusionCount[Goblin] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "���")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "������� �߰�" << endl;
		Hero* hero = new Hero("�������", 1,50, 50, 15, 15, 10, 5, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "�꼺������" && fusionCount[Slime] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "������")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "�꼺������ �߰�" << endl;
		Hero* hero = new Hero("�꼺������", 1, 60, 60, 20, 20, 8, 8, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "���̷��������" && fusionCount[Skeleton] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "���̷���")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "���̷�������� �߰�" << endl;
		Hero* hero = new Hero("���̷��������", 1, 70, 70, 20, 20, 15, 5, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "������" && fusionCount[Fairy] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "��")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "������ �߰�" << endl;
		Hero* hero = new Hero("������", 1, 40, 40, 30, 30, 5, 12, 3);
		player.HeroInven.push_back(hero);
	}
	else if (N == "���" && fusionCount[soldier] >= 2)
	{
		hiter = player.HeroInven.begin();
		while (hiter != player.HeroInven.end())
		{
			if ((*hiter)->Name == "�ΰ�����")
			{
				player.HeroInven.erase(hiter++);
				count++;
				if (count == 2)
					break;
			}
			else
				hiter++;
		}

		cout << "��� �߰�" << endl;
		Hero* hero = new Hero("���", 1, 60, 60, 20, 20, 12, 10, 4);
		player.HeroInven.push_back(hero);
	}
	else if (N == "�߽�������" && fusionCount[Fairy] >= 1 && fusionCount[soldier] >= 1)
	{
	hiter = player.HeroInven.begin();
	while (hiter != player.HeroInven.end())
	{
		if ((*hiter)->Name == "�ΰ�����" && count < 1)
		{
			player.HeroInven.erase(hiter++);
			count++;
			if (count == 1)
				continue;
		}
		if ((*hiter)->Name == "��" && count2 < 1)
		{
			player.HeroInven.erase(hiter++);
			count++;
			if (count2 == 1)
				continue;
		}
		
		hiter++;
	}
		cout << "�߽������� �߰�" << endl;
		Hero* hero = new Hero("�߽�������", 1, 40, 40, 30, 30, 5, 15, 3);
		player.HeroInven.push_back(hero);

	}
	else
	{
		cout << "�߸��Է��ϼ̽��ϴ�." << endl;
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
		cout << "�̸� : " << player.Name << endl;
		gotoxy(0, 2);
		cout << "���� �ܾ� : " << player.Gold << endl;

		Title();

		gotoxy(x, y);
		cout << "1. Stroy Mode";
		gotoxy(x, y+2);
		cout << "2. ���� �̱� (10 Gold)";
		gotoxy(x, y+4);
		cout << "3. ���� ����Ʈ ����";
		gotoxy(x, y + 6);
		cout << "4. ���� ����";
		gotoxy(x, y + 8);
		cout << "5. ���� ������";
		gotoxy(x, y + 10);
		cout << "6. ���� ����";
		gotoxy(x, y + 12);
		cout << "7. ���չ�";
		gotoxy(x, y + 14);
		cout << "8. ����";
		gotoxy(x, y + 16);
		cout << "�Է� : ";
		iMenu = cinKey<int>();
		getchar();

		if (iMenu <= SM_NONE || iMenu >= SM_END)
		{
			if (SM_END == iMenu)
				break;

			continue;
		}

		if (iMenu == SM_Stroy)						//�� ������ ���
		{
			time(&startTime);
			stage->RoundStart(player);
		}
		else if(iMenu == SM_ADD)				// ���� �߰�
		{
			if (player.Gold >= 10)
			{
				player.Gold -= 10;
				HeroAdd(player, hlist);
				Save(player);
			}
		}
		else if (iMenu == SM_LIST)				// ���� ����
		{
			HeroList(player);
			Save(player);
		}
		else if (iMenu == SM_FUSION)			// ���� ����
		{
			HeroFusion(player);
			Save(player);
		}
		else if (iMenu == SM_DEL)				// ���� ������ (�� ȹ��)
		{
			HeroDel(player);
			Save(player);
		}
		else if (iMenu == SM_Offerings)			// ���� ���� (����ġ ����)
		{
			HeroOff(player);
			Save(player);
		}
		else if (iMenu == SM_FINFO)				// ���չ� ����
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
	else // ����
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

