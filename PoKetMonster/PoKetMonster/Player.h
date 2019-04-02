#pragma once
#include "Monster.h"

class Player
{
public:
	Player();
	~Player();
public:
	char Name[128];
	//int Level;
	//int Ad;
	//int Dp;
	//int Hp;
	//int HpMax;
	//int exp;
	//int expMax;
	int gold;
	int MonsterBall;
public:
	Monster *partMon;
	void EqPoket(vector<Monster*> &eqMon);
};

