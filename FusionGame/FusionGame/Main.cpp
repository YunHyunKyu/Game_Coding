#include "Util.h"
#include "Player.h"
#include "GameLoop.h"

//영웅 조합 테스트, list 사용해 보기

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
		cout << "1. 게임시작" << endl;
		gotoxy(45, 22);
		cout << "2. 이어하기" << endl;
		gotoxy(45, 24);
		cout << "3. 종료" << endl;
		gotoxy(45, 26);
		cout << "입력 : ";
		cin >> iMenu;
		getchar();

		if (cin.fail())					//이거 하는 이유는 입력에서 문자를 받으면 오류먹어서 실패하면 cin 비워주고 다시 시작
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
			//start 메뉴로 이동 - 이름 입력 받고 초기 돈을 획득
			player->PlayerSetting();
			int n = StartMenu(*player);
			if (n == 0)
			{
				return 0;
			}
		}
		else if (iMenu == MM_CONTINUE)
		{
			//저장 된 파일 불러오고 메뉴로 이동
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