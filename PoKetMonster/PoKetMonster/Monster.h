#pragma once
#include "util.h"
#include <time.h>

class Monster
{
public:
	Monster();
	~Monster();
public:
	char Name[20];
	char skillName[40];
	int Level;
	int Ad;
	int Dp;
	int Hp;
	int HpMax;
	int Exp;
	int ExpMax;
	int giveGold;
	int giveExp;
	int skillDamage;
	int skillCount;
public:
	void SetMonster(int round);
	void SetName(const char* _name);
	void SetSkillName(const char* _name);
	void LevelUp(vector<Monster*> monster);
};

