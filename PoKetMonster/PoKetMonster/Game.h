#pragma once
#include "Player.h"
#include "Monster.h"
#include "Setting.h"

//Ÿ��Ʋ �׸���
void titleDraw();

//Ÿ��Ʋ�� �޴�
int titleMenu();

//�κ�ȭ��
int lobby(Player &player, vector<Monster*> &playerMonster);

//�κ񿡼� ������ ���ϸ� �����ֱ�
void PlayPoketMon(vector<Monster*> &plmon, Player &player);

//-------Ű �Է� �ҽ�--------
template <typename T>
T cinKey();

int GetKey();
//--------------------------

//---------------------�κ� ȭ�� ����------------------
//�κ��丮
void Inventory(vector<Monster*> &playerMonster);
//����
void Market(Player &player, vector<Monster*> &playerMonster);

//-----------------------------------------------------

//���� ���ý�----------------------------

//Ʈ���̴�
void training(Player &player, vector<Monster*> &playerMonster);

//������ �ݱ�
void ItemGet(Player &player, vector<Monster*> &playerMonster);

//��Ʋ �ڵ�
void battle(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, Player& player, int n);
void Dual(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int Random);
//���ͺ�
int MonsterBall(vector<Monster*> &playerMonster, vector<Monster*> &EnemyMonster, int RandomMonster, Player &player);
void trainer(Player &player, vector<Monster*> &playerMonster);
//-------------------------------------------