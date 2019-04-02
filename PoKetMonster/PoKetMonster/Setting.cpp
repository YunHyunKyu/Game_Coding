#include "Setting.h"

void PlayerSetting(Player & player, vector<Monster*> &Pmonster)
{
	cout << "�÷��̾��� �̸� : ";
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
	monster[0].SetName("����");
	monster[0].SetSkillName("����ġ��");
	monster[0].SetMonster(n);
	monList.push_back(&monster[0]);

	monster[1].SetName("����");
	monster[1].SetSkillName("������");
	monster[1].SetMonster(n);
	monList.push_back(&monster[1]);

	monster[2].SetName("ĳ����");
	monster[2].SetSkillName("�ǻձ�");
	monster[2].SetMonster(n);
	monList.push_back(&monster[2]);

	monster[3].SetName("������");
	monster[3].SetSkillName("�������");
	monster[3].SetMonster(n);
	monList.push_back(&monster[3]);

	monster[4].SetName("������");
	monster[4].SetSkillName("�ɱ�");
	monster[4].SetMonster(n);
	monList.push_back(&monster[4]);

	monster[5].SetName("�ƺ�");
	monster[5].SetSkillName("������");
	monster[5].SetMonster(n);
	monList.push_back(&monster[5]);

	monster[6].SetName("�𷡵���");
	monster[6].SetSkillName("������");
	monster[6].SetMonster(n);
	monList.push_back(&monster[6]);

	monster[7].SetName("�ѹ���");
	monster[7].SetSkillName("��ġ��");
	monster[7].SetMonster(n);
	monList.push_back(&monster[7]);

	monster[8].SetName("��ì��");
	monster[8].SetSkillName("��ǰ");
	monster[8].SetMonster(n);
	monList.push_back(&monster[8]);

	monster[9].SetName("�����");
	monster[9].SetSkillName("�����ٳ�����");
	monster[9].SetMonster(n);
	monList.push_back(&monster[9]);
}

void EvMonsterSetting(vector<Monster*>& monList, Monster * monster, int n)
{
	monster[0].SetName("����");
	monster[0].SetSkillName("�ٶ�����Ű��");
	monster[0].SetMonster(n);
	monList.push_back(&monster[0]);

	monster[1].SetName("��Ʈ��");
	monster[1].SetSkillName("������");
	monster[1].SetMonster(n);
	monList.push_back(&monster[1]);

	monster[2].SetName("�ܴ��");
	monster[2].SetSkillName("�ܴ�������");
	monster[2].SetMonster(n);
	monList.push_back(&monster[2]);

	monster[3].SetName("������");
	monster[3].SetSkillName("�ܴ�������");
	monster[3].SetMonster(n);
	monList.push_back(&monster[3]);

	monster[4].SetName("����帱��");
	monster[4].SetSkillName("�ɱ�");
	monster[4].SetMonster(n);
	monList.push_back(&monster[4]);

	monster[5].SetName("�ƺ�ũ");
	monster[5].SetSkillName("������");
	monster[5].SetMonster(n);
	monList.push_back(&monster[5]);

	monster[6].SetName("����");
	monster[6].SetSkillName("������");
	monster[6].SetMonster(n);
	monList.push_back(&monster[6]);

	monster[7].SetName("������");
	monster[7].SetSkillName("����");
	monster[7].SetMonster(n);
	monList.push_back(&monster[7]);

	monster[8].SetName("����ì��");
	monster[8].SetSkillName("��ǰ");
	monster[8].SetMonster(n);
	monList.push_back(&monster[8]);

	monster[9].SetName("������");
	monster[9].SetSkillName("�����ٳ�����");
	monster[9].SetMonster(n);
	monList.push_back(&monster[9]);
}

void TrinerMonsterSetting(vector<Monster*>& monList, Monster * monster, vector<Monster*> playerMonster)
{
	int trinerMonLevel = (playerMonster[0]->Level / 5) + 1;
	monster[0].SetName("����");
	monster[0].SetSkillName("�𷡹ٶ�");
	monster[0].SetMonster(trinerMonLevel);
	monList.push_back(&monster[0]);

	monster[1].SetName("������");
	monster[1].SetSkillName("�ٶ�����Ű��");
	monster[1].SetMonster(trinerMonLevel);
	monList.push_back(&monster[1]);

	monster[2].SetName("�̺���");
	monster[2].SetSkillName("����");
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
		cout << "����Ǿ����ϴ�.";
		Sleep(1000);
		fclose(fp);
		fclose(fp2);
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}
	system("cls");
}

int LOAD(Player & player, vector<Monster*>& playerMonster)
{
	FILE* fp;
	FILE* fp2;

	fopen_s(&fp, "User.txt", "rt");
	fopen_s(&fp2, "Monster.txt", "rt");
	
	Monster* mon = new Monster[12]; //�ִ� ���� ����
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
		cout << "���� �ε� ����" << endl;
		Sleep(1000);
		return 0;
	}
}
