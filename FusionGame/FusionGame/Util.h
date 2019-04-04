#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <list>
#include <vector>
#include <time.h>
using namespace std;

#define AddHeroMax 5
#define HeroMax 11

enum Hero_Count {
	Goblin,
	Slime,
	Skeleton,
	Fairy,
	soldier
};

//메인 메뉴
enum MAIN_MENU {
	MM_NONE,
	MM_START,
	MM_CONTINUE,
	MM_END
};

//Start Menu
enum START_MENU {
	SM_NONE,
	SM_Stroy,			
	SM_ADD,
	SM_LIST,
	SM_FUSION,
	SM_DEL,
	SM_Offerings,
	SM_FINFO,
	SM_END
};

// 색
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

void Title();

void gotoxy(int x, int y);

void setColor(int, int);

void FusionInfo();