#include "Setting.h"

void PlayerSetting(Player & player, vector<Monster*> &Pmonster)
{
	cout << "플레이어의 이름 : ";
	cin.getline(player.Name, sizeof(player.Name));

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(256, '\n');
		PlayerSetting(player, Pmonster);
	}

	player.EqPoket(Pmonster);
}

void NormalMonsterSetting(vector<Monster*>& monList, Monster * monster, int n)
{
	monster[0].SetName("구구");
	monster[0].SetSkillName("날개치기");
	monster[0].SetMonster(n);
	monList.push_back(&monster[0]);

	monster[1].SetName("꼬렛");
	monster[1].SetSkillName("물어뜯기");
	monster[1].SetMonster(n);
	monList.push_back(&monster[1]);

	monster[2].SetName("캐터피");
	monster[2].SetSkillName("실뿜기");
	monster[2].SetMonster(n);
	monList.push_back(&monster[2]);

	monster[3].SetName("뿔충이");
	monster[3].SetSkillName("연속찌르기");
	monster[3].SetMonster(n);
	monList.push_back(&monster[3]);

	monster[4].SetName("깨비참");
	monster[4].SetSkillName("쪼기");
	monster[4].SetMonster(n);
	monList.push_back(&monster[4]);

	monster[5].SetName("아보");
	monster[5].SetSkillName("물어뜯기");
	monster[5].SetMonster(n);
	monList.push_back(&monster[5]);

	monster[6].SetName("모래두지");
	monster[6].SetSkillName("구르기");
	monster[6].SetMonster(n);
	monList.push_back(&monster[6]);

	monster[7].SetName("뚜벅쵸");
	monster[7].SetSkillName("박치기");
	monster[7].SetMonster(n);
	monList.push_back(&monster[7]);

	monster[8].SetName("발챙이");
	monster[8].SetSkillName("거품");
	monster[8].SetMonster(n);
	monList.push_back(&monster[8]);

	monster[9].SetName("모다피");
	monster[9].SetSkillName("나뭇잎날리기");
	monster[9].SetMonster(n);
	monList.push_back(&monster[9]);
}

void EvMonsterSetting(vector<Monster*>& monList, Monster * monster, int n)
{
	monster[0].SetName("피죤");
	monster[0].SetSkillName("바람일으키기");
	monster[0].SetMonster(n);
	monList.push_back(&monster[0]);

	monster[1].SetName("리트라");
	monster[1].SetSkillName("물어뜯기");
	monster[1].SetMonster(n);
	monList.push_back(&monster[1]);

	monster[2].SetName("단대기");
	monster[2].SetSkillName("단단해지기");
	monster[2].SetMonster(n);
	monList.push_back(&monster[2]);

	monster[3].SetName("딱충이");
	monster[3].SetSkillName("단단해지기");
	monster[3].SetMonster(n);
	monList.push_back(&monster[3]);

	monster[4].SetName("깨비드릴조");
	monster[4].SetSkillName("쪼기");
	monster[4].SetMonster(n);
	monList.push_back(&monster[4]);

	monster[5].SetName("아보크");
	monster[5].SetSkillName("물어뜯기");
	monster[5].SetMonster(n);
	monList.push_back(&monster[5]);

	monster[6].SetName("고지");
	monster[6].SetSkillName("구르기");
	monster[6].SetMonster(n);
	monList.push_back(&monster[6]);

	monster[7].SetName("냄새꼬");
	monster[7].SetSkillName("냄새");
	monster[7].SetMonster(n);
	monList.push_back(&monster[7]);

	monster[8].SetName("슈륙챙이");
	monster[8].SetSkillName("거품");
	monster[8].SetMonster(n);
	monList.push_back(&monster[8]);

	monster[9].SetName("우츠동");
	monster[9].SetSkillName("나뭇잎날리기");
	monster[9].SetMonster(n);
	monList.push_back(&monster[9]);
}

void TrinerMonsterSetting(vector<Monster*>& monList, Monster * monster, vector<Monster*> playerMonster)
{
	int trinerMonLevel = (playerMonster[0]->Level / 5) + 1;
	monster[0].SetName("피죤");
	monster[0].SetSkillName("모래바람");
	monster[0].SetMonster(trinerMonLevel);
	monList.push_back(&monster[0]);

	monster[1].SetName("피죤투");
	monster[1].SetSkillName("바람일으키기");
	monster[1].SetMonster(trinerMonLevel);
	monList.push_back(&monster[1]);

	monster[2].SetName("이브이");
	monster[2].SetSkillName("순보");
	monster[2].SetMonster(trinerMonLevel);
	monList.push_back(&monster[2]);
}

void SAVE(Player &player, vector<Monster*> &playerMonster)
{
	FILE* fp;
	FILE* fp2;

	fopen_s(&fp, "User.txt", "wt");
	fopen_s(&fp2, "Monster.txt", "wt");

	if (fp != NULL && fp2 != NULL)
	{
		fprintf(fp, "%s %d %d\n", player.Name, player.gold, player.MonsterBall);
		fprintf(fp2, "%d\n", playerMonster.size());
		for (int i = 0; i < playerMonster.size(); i++)
		{
			fprintf(fp2, "%s %d %d %d %d %d %d %d %s %d %d\n", playerMonster[i]->Name, playerMonster[i]->Level, playerMonster[i]->Ad, playerMonster[i]->Dp, playerMonster[i]->HpMax, playerMonster[i]->Hp,
				playerMonster[i]->ExpMax, playerMonster[i]->Exp, playerMonster[i]->skillName, playerMonster[i]->skillDamage, playerMonster[i]->skillCount);
		}
		gotoxy(40, 19);
		cout << "저장되었습니다.";
		Sleep(1000);
		fclose(fp);
		fclose(fp2);
	}
	else
	{
		cout << "파일 저장 실패" << endl;
	}
	system("cls");
}

int LOAD(Player & player, vector<Monster*>& playerMonster)
{
	FILE* fp;
	FILE* fp2;

	fopen_s(&fp, "User.txt", "rt");
	fopen_s(&fp2, "Monster.txt", "rt");
	
	Monster* mon = new Monster[12]; //최대 몬스터 갯수
	if (fp != NULL && fp2 != NULL)
	{
		fscanf_s(fp, "%s %d %d", &player.Name, sizeof(char)*20, &player.gold, &player.MonsterBall);
		int size = 0;
		fscanf_s(fp2, "%d", &size);
		for (int i = 0; i < size; i++)
		{
			fscanf_s(fp2, "%s %d %d %d %d %d %d %d %s %d %d", &mon[i].Name, sizeof(char)*20 ,&mon[i].Level, &mon[i].Ad, &mon[i].Dp, &mon[i].HpMax, &mon[i].Hp,
				&mon[i].ExpMax, &mon[i].Exp, &mon[i].skillName,sizeof(char)*40, &mon[i].skillDamage, &mon[i].skillCount);

			playerMonster.push_back(&mon[i]);
		}

		fclose(fp);
		fclose(fp2);
		return 1;
	}
	else
	{
		cout << "파일 로드 실패" << endl;
		Sleep(1000);
		return 0;
	}
}
