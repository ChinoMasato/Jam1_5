#pragma once
#include "en.h"
const int EnemyNum = 300;//�G�̐�
extern En enemy[EnemyNum];//�G
extern En enemy2[EnemyNum];//�G
extern int enemy1img;
extern int enemy2img;
extern int kisidaimg;
extern int kisidahp;
void initEnemy();//�G�̏�����
void updateEnemy();//�G�̍X�V
void updatesecondEnemy();
void secondupdateEnemy();
void drawEnemy();//�G�̕`��
void drawsecondEnemy();//�G�̕`��
void seconddrawEnemy();
bool canEnemyShot(En enemy);//�e�����Ă邩�m�F
void straightShot(int rad, En ene);//�^����������
void aimShot(En ene);//�_���Č���
void tripleShot(int rad, En ene);
void twinShot(int rad, int shifty, En ene);
void closerangeShot();
void explosion(En ene);//���j�����֐�