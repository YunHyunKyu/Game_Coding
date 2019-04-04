#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

Hero::Hero(string _name, int _level, int _hp, int _hpmax,int _mp, int _mpmax, int _ad, int _ap, int _dp)
{
	Name = _name;
	Level = _level;
	Hp = _hp;
	HpMax = _hpmax;
	Mp = _mp;
	MpMax = _mpmax;
	Ad = _ad;
	Ap = _ap;
	Dp = _dp;
	Exp = 0;
	ExpMax = Level * 10;
	giveGold = 5;
	giveExp = 2;
}

void Hero::LevelUp(Hero *hero)
{
	/*
	if (hero->Name == "고블린")
	{
		hero.Level++;
		hero.HpMax += 5;
		hero.Hp = hero.HpMax;
		hero.MpMax += 5;
		hero.Mp = hero.MpMax;
		hero.Ad += 1;
		hero.Ap += 1;
		hero.Dp += 1;
		hero.ExpMax = Level * 10;
		hero.giveExp = Level * 2;
		hero.giveGold = Level * 5;
	}
	*/
	hero->Level++;
	hero->HpMax += 5;
	hero->Hp = hero->HpMax;
	hero->MpMax += 5;
	hero->Mp = hero->MpMax;
	hero->Ad += 1;
	hero->Ap += 1;
	hero->Dp += 1;
	hero->ExpMax = Level * 10;
	hero->giveExp = Level * 2;
	hero->giveGold = Level * 5;
}

void Hero::HeroSetting(list<Hero*>& Herolist)
{
	Hero* hero = new Hero("고블린", 1, 10, 10, 10, 10, 3, 1, 1);
	Herolist.push_back(hero);

	hero = new Hero("슬라임", 1, 5, 5, 10, 10, 2, 2, 1);
	Herolist.push_back(hero);

	hero = new Hero("스켈레톤", 1, 15, 15, 5, 5, 3, 1, 2);
	Herolist.push_back(hero);

	hero = new Hero("페어리", 1, 10, 10, 20, 20, 2, 3, 1);
	Herolist.push_back(hero);

	hero = new Hero("인간병사", 1, 10, 10, 10, 10, 2, 2, 1);
	Herolist.push_back(hero);
}



