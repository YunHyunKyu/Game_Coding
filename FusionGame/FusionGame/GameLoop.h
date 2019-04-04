#pragma once
#include <list>
class Player;
class Hero;


template <typename T>
T cinKey();

int StartMenu(Player &player);

void HeroAdd(Player &player, std::list<Hero*> &hlist);

void HeroList(Player &player);

void HeroDel(Player &player);

void HeroOff(Player &player);

void Load(Player &player);

void Save(Player &player);