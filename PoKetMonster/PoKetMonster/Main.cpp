#include "util.h"
#include "Monster.h"
#include "Player.h"
#include "Setting.h"
#include "Game.h"

int main()
{
	
	Init();
	srand((unsigned int)time(0));
	Player *player = new Player;	 //플레이어
	vector<Monster*> playerMonster;  //내가 장착한 몬스터
	while (1)
	{
		titleDraw(); //타이틀 화면 출력
		int n = titleMenu();
		
		//게임 시작
		if (n == GAME_START)
		{
			system("cls");
			PlayerSetting(*player, playerMonster);	// 일단 플레이어 설정
			GameGo();								// 게임 시작 알리기
			int m = lobby(*player, playerMonster);	// 게임 스타트 ( 로비화면 )

			if (m == 0)
				return 0;
		}
		//이어 하기
		else if (n == GAME_CONTINUE)
		{
			int n = LOAD(*player, playerMonster);
			if (n != 0)
			{
				GameGo();								// 게임 시작 알리기
				int m = lobby(*player, playerMonster);	// 게임 스타트 ( 로비화면 )

				if (m == 0)
					return 0;
			}
		}
		//게임 정보
		else if (n == GAME_INFO)
		{
			GameInfo();
		}
		// 게임 종료
		else if (n == GAME_EXIT)
		{
			system("cls");
			gotoxy(30, 20);
			cout << "게임을 종료합니다." << endl;
			Sleep(1000);
			return 0;
		}

		system("cls");
	}

	getchar();
	return 0;
}