#pragma once
#include "Util.h"
class Hero;

class Player
{
public:
	string Name;
	int Gold;
	list<Hero*> HeroInven;
public:
	Player();
	~Player();
	Player(string _name, int Gold);
public:
	void PlayerSetting();
};

