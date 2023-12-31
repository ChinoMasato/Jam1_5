#pragma once
#include "en.h"
const int EnemyNum = 300;//敵の数
extern En enemy[EnemyNum];//敵
extern En enemy2[EnemyNum];//敵
extern int enemy1img;
extern int enemy2img;
extern int kisidaimg;
extern int kisidahp;
extern int explodese;
void initEnemy();//敵の初期化
void updateEnemy();//敵の更新
void updatesecondEnemy();
void secondupdateEnemy();
void drawEnemy();//敵の描画
void drawsecondEnemy();//敵の描画
void seconddrawEnemy();
bool canEnemyShot(En enemy);//弾が撃てるか確認
void straightShot(int rad, En ene);//真っすぐ撃つ
void aimShot(En ene);//狙って撃つ
void tripleShot(int rad, En ene);
void twinShot(int rad, int shifty, En ene);
void closerangeShot();
void explosion(En ene);//爆破発生関数