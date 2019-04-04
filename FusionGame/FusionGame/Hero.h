#pragma once
#include "Util.h"

class Hero
{
public:
	string Name;
	int Level;
	int Hp;
	int HpMax;
	int Mp;
	int MpMax;
	int Ad;
	int Ap;
	int Dp;
	int Exp;
	int ExpMax;
	int giveGold;
	int giveExp;
public:
	Hero();
	~Hero();
	Hero(string _name, int _level, int _hp, int _hpmax, int _mp, int _mpmax, int _ad, int _ap, int _dp);
public:
	void HeroSetting(list<Hero*> &Herolist);
	void LevelUp(Hero *hero);
};

