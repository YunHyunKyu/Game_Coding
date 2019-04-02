#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

using namespace std;

//키보드 값
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SPACE 4 // 스페이스
#define EX_OUT 5

#define GAME_START 0x00
#define GAME_CONTINUE 0x02
#define GAME_INFO 0x04
#define GAME_EXIT 0x06



enum Map_Menu {
	MM_NONE,
	MM_ADVENTURE,
	MM_MARKET,
	MM_POKETMONCENTER,
	MM_INVENTORY,
	MM_SAVE,
	MM_END
};

enum MENU_BATTLE {
	MB_NONE,
	MB_BATTLE,
	MB_ESCAPE,
	MB_MONSTERCATCH,
	MB_END
};

enum MARKET_MENU {
	MK_NONE,
	MK_MONBALL,
	MK_POSITION,
	MK_EXPBOX,
	MK_END
};

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void gotoxy(int, int);
void setColor(int, int);
void GameGo();
void itemMotion();
void AdventureMotion();
void Init();
void GameInfo();