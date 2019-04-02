#include "util.h"
#include "Monster.h"
#include "Player.h"
#include "Setting.h"
#include "Game.h"

int main()
{
	
	Init();
	srand((unsigned int)time(0));
	Player *player = new Player;	 //�÷��̾�
	vector<Monster*> playerMonster;  //���� ������ ����
	while (1)
	{
		titleDraw(); //Ÿ��Ʋ ȭ�� ���
		int n = titleMenu();
		
		//���� ����
		if (n == GAME_START)
		{
			system("cls");
			PlayerSetting(*player, playerMonster);	// �ϴ� �÷��̾� ����
			GameGo();								// ���� ���� �˸���
			int m = lobby(*player, playerMonster);	// ���� ��ŸƮ ( �κ�ȭ�� )

			if (m == 0)
				return 0;
		}
		//�̾� �ϱ�
		else if (n == GAME_CONTINUE)
		{
			int n = LOAD(*player, playerMonster);
			if (n != 0)
			{
				GameGo();								// ���� ���� �˸���
				int m = lobby(*player, playerMonster);	// ���� ��ŸƮ ( �κ�ȭ�� )

				if (m == 0)
					return 0;
			}
		}
		//���� ����
		else if (n == GAME_INFO)
		{
			GameInfo();
		}
		// ���� ����
		else if (n == GAME_EXIT)
		{
			system("cls");
			gotoxy(30, 20);
			cout << "������ �����մϴ�." << endl;
			Sleep(1000);
			return 0;
		}

		system("cls");
	}

	getchar();
	return 0;
}