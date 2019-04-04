#pragma once
#include "Util.h"
class Hero;
class Player;

class Stage
{
public:
	vector<Hero*> enemyList;
	static int Round;
public:
	Stage();
	~Stage();
public:
	void RoundStart(Player &player);
};

