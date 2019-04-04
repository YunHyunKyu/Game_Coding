#include "Util.h"
#include "Player.h"
#include "GameLoop.h"

//���� ���� �׽�Ʈ, list ����� ����

int main()
{
	system("mode con cols=100 lines=50");
	srand((unsigned int)time(0));

	int iMenu = 0;
	Player* player = new Player;
	while (1)
	{
		Title();

		gotoxy(45, 20);
		cout << "1. ���ӽ���" << endl;
		gotoxy(45, 22);
		cout << "2. �̾��ϱ�" << endl;
		gotoxy(45, 24);
		cout << "3. ����" << endl;
		gotoxy(45, 26);
		cout << "�Է� : ";
		cin >> iMenu;
		getchar();

		if (cin.fail())					//�̰� �ϴ� ������ �Է¿��� ���ڸ� ������ �����Ծ �����ϸ� cin ����ְ� �ٽ� ����
		{
			cin.clear();
			cin.ignore(256, '\n');
			system("cls");
			continue;
		}

		if (iMenu <= MM_NONE || iMenu >= MM_END)
		{
			if (iMenu == MM_END)
				break;

			continue;
		}

		if (iMenu == MM_START)
		{
			//start �޴��� �̵� - �̸� �Է� �ް� �ʱ� ���� ȹ��
			player->PlayerSetting();
			int n = StartMenu(*player);
			if (n == 0)
			{
				return 0;
			}
		}
		else if (iMenu == MM_CONTINUE)
		{
			//���� �� ���� �ҷ����� �޴��� �̵�
			Load(*player);
			int n = StartMenu(*player);
			if (n == 0)
			{
				return 0;
			}
		}
	}
	return 0;
}