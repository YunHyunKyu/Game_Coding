#pragma once
#include "Player.h"
#include "Monster.h"
#include "Setting.h"

//타이틀 그리기
void titleDraw();

//타이틀쪽 메뉴
int titleMenu();

//로비화면
int lobby(Player &player, vector<Monster*> &playerMonster);

//로비에서 장착된 포켓몬 보여주기
void PlayPoketMon(vector<Monster*> &plmon, Player &player);

//-------키 입력 소스--------
template <typename T>
T cinKey();

int GetKey();
//--------------------------

//---------------------로비 화면 선택------------------
//인벤토리
void Inventory(vector<Monster*> &playerMonster);
//상점
void Market(Player &player, vector<Monster*> &playerMonster);

//-----------------------------------------------------

//마을 선택시----------------------------

//트레이닝
void training(Player &player, vector<Monster*> &playerMonster);

//아이템 줍기
void ItemGet(Player &player, vector<Monster*> &playerMonster);

//배틀 코드
void battle(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, Player& player, int n);
void Dual(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int Random);
//몬스터볼
int MonsterBall(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int RandomMonster, Player &player);
void trainer(Player &player, vector<Monster*> &playerMonster);
//-------------------------------------------