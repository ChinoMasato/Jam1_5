#pragma once
#include "en.h"

const int EnemyShotNum = 1100;
extern En enemyshot[EnemyShotNum];//�e
extern int AttackCoolTime;

void initEnemyShot();//�e�̏�����
void updateEnemyShot();//�e�̍X�V
void drawEnemyShot();