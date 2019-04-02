#pragma once
#include "Monster.h"
#include "Player.h"
#include "util.h"


void PlayerSetting(Player &player, vector<Monster*> &Pmonster);
void NormalMonsterSetting(vector<Monster*> &monList, Monster* monster, int n);
void EvMonsterSetting(vector<Monster*>& monList, Monster * monster, int n);
void SAVE(Player &player, vector<Monster*> &playerMonster);
int LOAD(Player &player, vector<Monster*> &playerMonster);
void TrinerMonsterSetting(vector<Monster*>& monList, Monster * monster, vector<Monster*> playerMonster);

