#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemyshot.h"
#include "enemy.h"
#include "player.h"
#include "game.h"
#include "effect.h"
extern bool gameOverFlag;//�Q�[���I�[�o�[����
En enemy[EnemyNum];//1nd�̓G�̊֐�
En enemy2[EnemyNum];//2nd�̓G�̊֐�
int explodese;//���j�G�t�F�N�g�̊֐�
int enemyimg;//���j�G�t�F�N�g�̉摜
int enemy2img;
int kisidaimg;
int kisidahp;
int q = 0;
//�G�̏�����
void initEnemy()
{
	//���j�G�t�F�N�g
	explodese = LoadSoundMem("maou_se_battle_explosion05.mp3");
	//�G�̉摜
	enemyimg = LoadGraph("enemy1.png");
	enemy2img = LoadGraph("enemy2.png");
	kisidaimg = LoadGraph("kisida.png");
	//1�X�e�[�W�ڂ̓G
	//1�̖ڂ̓G
	enemy[0].x = 900;//�G��X���W
	enemy[0].y = 200;//�G��Y���W
	enemy[0].r = 30;//�G�̑傫��
	enemy[0].color = GetColor(255, 0, 0);//�G�̐F
	enemy[0].fill = true;//�h��Ԃ����ۂ�
	enemy[0].enable = true;//�����Ă��邩����ł��邩
	enemy[0].vx = -2.0;//X�����̃X�s�[�h
	enemy[0].vy = 0.0;//Y�����̃X�s�[�h
	enemy[0].type = ENEMY2;//�e�̎��
	//2�̖ڂ̓G
	enemy[1].x = 1500;//�G��X���W
	enemy[1].y = 300;//�G��Y���W
	enemy[1].r = 30;//�G�̑傫��
	enemy[1].color = GetColor(255, 0, 0);//�G�̐F
	enemy[1].fill = true;//�h��Ԃ����ۂ�
	enemy[1].enable = true;//�����Ă��邩����ł��邩
	enemy[1].vx = -2.0;//X�����̃X�s�[�h
	enemy[1].vy = 0.0;//Y�����̃X�s�[�h
	enemy[1].type = ENEMY2;//�e�̎��
	//3�̖ڂ̓G
	enemy[2].x = 1500;//�G��X���W
	enemy[2].y = 200;//�G��Y���W
	enemy[2].r = 30;//�G�̑傫��
	enemy[2].color = GetColor(255, 0, 0);//�G�̐F
	enemy[2].fill = true;//�h��Ԃ����ۂ�
	enemy[2].enable = true;//�����Ă��邩����ł��邩
	enemy[2].vx = -2.0;//X�����̃X�s�[�h
	enemy[2].vy = 0.0;//Y�����̃X�s�[�h
	enemy[2].type = ENEMY3;//�e�̎��
	//4�̖ڂ̓G
	enemy[3].x = 1550;
	enemy[3].y = 50;
	enemy[3].r = 30;
	enemy[3].color = GetColor(255, 0, 0);
	enemy[3].fill = true;
	enemy[3].enable = true;
	enemy[3].vx = -2.0;
	enemy[3].vy = 0.0;
	enemy[3].type = ENEMY3;
	//5�̖ڂ̓G
	enemy[4].x = 1600;
	enemy[4].y = 400;
	enemy[4].r = 30;
	enemy[4].color = GetColor(255, 0, 0);
	enemy[4].fill = true;
	enemy[4].enable = true;
	enemy[4].vx = -2.0;
	enemy[4].vy = 0.0;
	enemy[4].type = ENEMY3;
	//6�̖ڂ̓G
	enemy[6].x = 1600;
	enemy[6].y = 100;
	enemy[6].r = 30;
	enemy[6].color = GetColor(255, 0, 0);
	enemy[6].fill = true;
	enemy[6].enable = true;
	enemy[6].vx = -2.0;
	enemy[6].vy = 0.0;
	enemy[6].type = ENEMY3;

	enemy[7].x = 1700;
	enemy[7].y = 200;
	enemy[7].r = 30;
	enemy[7].color = GetColor(255, 0, 0);
	enemy[7].fill = true;
	enemy[7].enable = true;
	enemy[7].vx = -2.0;
	enemy[7].vy = 0.0;
	enemy[7].type = ENEMY3;

	enemy[8].x = 1700;
	enemy[8].y = 400;
	enemy[8].r = 30;
	enemy[8].color = GetColor(255, 0, 0);
	enemy[8].fill = true;
	enemy[8].enable = true;
	enemy[8].vx = -2.0;
	enemy[8].vy = 0.0;
	enemy[8].type = ENEMY3;

	enemy[9].x = 1700;
	enemy[9].y = 500;
	enemy[9].r = 30;
	enemy[9].color = GetColor(255, 0, 0);
	enemy[9].fill = true;
	enemy[9].enable = true;
	enemy[9].vx = -2.0;
	enemy[9].vy = 0.0;
	enemy[9].type = ENEMY3;

	enemy[10].x = 1750;
	enemy[10].y = 200;
	enemy[10].r = 30;
	enemy[10].color = GetColor(255, 0, 0);
	enemy[10].fill = true;
	enemy[10].enable = true;
	enemy[10].vx = -2.0;
	enemy[10].vy = 0.0;
	enemy[10].type = ENEMY3;

	enemy[11].x = 1800;
	enemy[11].y = 500;
	enemy[11].r = 30;
	enemy[11].color = GetColor(255, 0, 0);
	enemy[11].fill = true;
	enemy[11].enable = true;
	enemy[11].vx = -2.0;
	enemy[11].vy = 0.0;
	enemy[11].type = ENEMY3;

	enemy[12].x = 1800;
	enemy[12].y = 100;
	enemy[12].r = 30;
	enemy[12].color = GetColor(255, 0, 0);
	enemy[12].fill = true;
	enemy[12].enable = true;
	enemy[12].vx = -2.0;
	enemy[12].vy = 0.0;
	enemy[12].type = ENEMY3;

	enemy[13].x = 1800;
	enemy[13].y = 300;
	enemy[13].r = 30;
	enemy[13].color = GetColor(255, 0, 0);
	enemy[13].fill = true;
	enemy[13].enable = true;
	enemy[13].vx = -2.0;
	enemy[13].vy = 0.0;
	enemy[13].type = ENEMY3;

	int a = 20;
	for (int i = 14; i < 20; i++)
	{
		enemy[i].x = 1900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 10;
	for (int i = 20; i < 25; i++)
	{
		enemy[i].x = 2000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}


	a = 30;
	for (int i = 25; i < 30; i++)
	{
		enemy[i].x = 2200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 10;
	for (int i = 30; i < 35; i++)
	{
		enemy[i].x = 2500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}

	a = 25;
	for (int i = 35; i < 40; i++)
	{
		enemy[i].x = 2700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 25;
	for (int i = 40; i < 45; i++)
	{
		enemy[i].x = 2800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 10;
	for (int i = 45; i < 50; i++)
	{
		enemy[i].x = 2900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 50;
	for (int i = 50; i < 55; i++)
	{
		enemy[i].x = 3000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 5;
	for (int i = 55; i < 60; i++)
	{
		enemy[i].x = 3100;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 125;
	}

	a = 10;
	for (int i = 60; i < 65; i++)
	{
		enemy[i].x = 3200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 40;
	for (int i = 65; i < 70; i++)
	{
		enemy[i].x = 3200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}

	a = 20;
	for (int i = 70; i < 75; i++)
	{
		enemy[i].x = 3300;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 10;
	for (int i = 75; i < 80; i++)
	{
		enemy[i].x = 3400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 8;
	for (int i = 80; i < 85; i++)
	{
		enemy[i].x = 3400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 15;
	for (int i = 85; i < 90; i++)
	{
		enemy[i].x = 3500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 20;
	for (int i = 90; i < 95; i++)
	{
		enemy[i].x = 3600;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 15;
	for (int i = 95; i < 100; i++)
	{
		enemy[i].x = 3700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}


	a = 30;
	for (int i = 100; i < 105; i++)
	{
		enemy[i].x = 3700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 15;
	for (int i = 105; i < 110; i++)
	{
		enemy[i].x = 3800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 130;
	}

	a = 20;
	for (int i = 110; i < 115; i++)
	{
		enemy[i].x = 3900;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 110;
	}


	a = 10;
	for (int i = 115; i < 120; i++)
	{
		enemy[i].x = 4000;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 8;
	for (int i = 120; i < 125; i++)
	{
		enemy[i].x = 4100;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}

	a = 10;
	for (int i = 125; i < 130; i++)
	{
		enemy[i].x = 4200;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}


	a = 20;
	for (int i = 130; i < 135; i++)
	{
		enemy[i].x = 4300;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 80;
	}

	a = 6;
	for (int i = 140; i < 145; i++)
	{
		enemy[i].x = 4400;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	a = 10;
	for (int i = 145; i < 150; i++)
	{
		enemy[i].x = 4500;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	a = 20;
	for (int i = 150; i < 155; i++)
	{
		enemy[i].x = 4600;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 100;
	}

	a = 50;
	for (int i = 150; i < 155; i++)
	{
		enemy[i].x = 4700;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 120;
	}


	a = 10;
	for (int i = 155; i < 165; i++)
	{
		enemy[i].x = 4800;
		enemy[i].y = a + a;
		enemy[i].r = 30;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;
		enemy[i].vx = -2.0;
		enemy[i].vy = 0.0;
		enemy[i].type = ENEMY3;

		a += 50;
	}

	//2�X�e�[�W�ڂ̓G
	//1�̖ڂ̓G
	enemy2[0].x = 900;
	enemy2[0].y = 300;
	enemy2[0].r = 50;
	enemy2[0].color = GetColor(255, 0, 0);
	enemy2[0].fill = true;
	enemy2[0].enable = true;
	enemy2[0].vx = -2.0;
	enemy2[0].vy = 2.0;
	enemy2[0].type = ENEMY4;
	kisidahp = 100;
}
//�^�������e������
void straightShot(int rad, En ene)
{
	//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double PI = 3.14159265358979323846264338;//�~����
			double minrad = PI / 180.0;//1�x�̃��W�A��
			double speed = 3.0;//���x
			enemyshot[j].vx = speed * cos(minrad * rad);//���̈ړ���
			enemyshot[j].vy = speed * sin(minrad * rad);//�c�̈ړ���
			enemyshot[j].enable = true;//�L���t���O
			enemyshot[j].type = ene.type;//�e�̎��
			break;
		}
	}
}
void tripleShot(int rad, En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1�x�̃��W�A��
			double speed = 3.0;//���x
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			break;
		}
	}
}
void twinShot(int rad, int shifty, En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y + shifty;
			double PI = 3.14159265358979323846264338;
			double minrad = PI / 180.0;//1�x�̃��W�A��
			double speed = 4.0;//���x
			enemyshot[j].vx = speed * cos(minrad * rad);
			enemyshot[j].vy = speed * sin(minrad * rad);
			enemyshot[j].enable = true;
			break;
			break;
		}
	}
}
void closerangeShot(En ene) {
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double speed = 3.0;//���x
			double dx = player.x - ene.x;//�v���C���[�ƓG��x�����̋���
			double dy = player.y - ene.y;//�v���C���[�ƓG��y�����̋���
			double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
			if (d <= 300) {
				enemyshot[j].vx = speed * (dx / d);//x�̈ړ���
				enemyshot[j].vy = speed * (dy / d);//y�̈ړ���
			}
			else if (d >= 300) {
				enemyshot[j].vx = speed;
				enemyshot[j].vy = speed;
			}
			enemyshot[j].enable = true;
			break;
		}
	}
}
//�_���Č���
void aimShot(En ene)
{
	//�e�����Ă���
//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y;
			double speed = 3.0;//���x
			double dx = player.x - ene.x;//�v���C���[�ƓG��x�����̋���
			double dy = player.y - ene.y;//�v���C���[�ƓG��y�����̋���
			double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
			enemyshot[j].vx = speed * (dx / d);//x�̈ړ���
			enemyshot[j].vy = speed * (dy / d);//y�̈ړ���
			enemyshot[j].enable = true;//���肪�L�����ۂ�
			break;
		}
	}
}
//���������֐�
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
	}
}

//�G�̍X�V
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//�e�̎�ނɉ�����
			if (enemyshot[i].type == ENEMY1)
			{
				enemy[i].vx = enemy[i].vx * 1, 02;
				enemy[i].vy = enemy[i].vy * 1, 02;
			}
			//�G�������œ�����
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;
			//�e�𔭎˂���
			if (canEnemyShot(enemy[i]))
			{
				if (enemy[i].type == ENEMY1) {
					straightShot(180, enemy[i]);//�^�������e�����
				}
				if (enemy[i].type == ENEMY2) {
					straightShot(200, enemy[i]);//����ɒe�����
				}
				if (enemy[i].type == ENEMY3) {
					aimShot(enemy[i]);//�v���C���[��_���Ēe�����ł���
				}
				if (enemy[i].type == ENEMY4) {
					tripleShot(160, enemy[i]);//3�����ɒe�����
					tripleShot(180, enemy[i]);
					tripleShot(200, enemy[i]);
				}
				if (enemy[i].type == ENEMY5) {
					twinShot(180, -5, enemy[i]);//�^������2��Œe�����ł���
					twinShot(180, 5, enemy[i]);
				}
				if (enemy[i].type == ENEMY6) {
					straightShot(0, enemy[i]);//�e���G�𒆐S�ɕ��o�����B
					straightShot(20, enemy[i]);
					straightShot(40, enemy[i]);
					straightShot(60, enemy[i]);
					straightShot(80, enemy[i]);
					straightShot(100, enemy[i]);
					straightShot(120, enemy[i]);
					straightShot(140, enemy[i]);
					straightShot(160, enemy[i]);
					straightShot(180, enemy[i]);
					straightShot(200, enemy[i]);
					straightShot(220, enemy[i]);
					straightShot(240, enemy[i]);
					straightShot(260, enemy[i]);
					straightShot(280, enemy[i]);
					straightShot(300, enemy[i]);
					straightShot(320, enemy[i]);
					straightShot(340, enemy[i]);
					straightShot(360, enemy[i]);
				}
				if (enemy[i].type == ENEMY7) {
					closerangeShot(enemy[i]);//�v���C���[�ɋ߂��ƁA�v���C���[��_���Ēe��ł�
				}
				enemy[i].cooltime = 100;//�e�̃N�[���^�C��
			}
			if (isHit(player, enemy[i]) && BlackHole.enable == false)
			{
				if (AttackCoolTime == 0)
				{
					playerHp--;//�v���C���[��HP�����炷
					AttackCoolTime = 30;//�A�^�b�N�N�[���^�C�������
					playerBar.x2--;
				}
				if (playerHp == 0)
				{
					gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
				}
			}
			if (AttackCoolTime > 0)
			{
				AttackCoolTime--;
			}
			for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].enable = false;//�G�𖳌�
						shot[j].enable = false;//�e�𖳌�
						PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//���j�G�t�F�N�g�̌Ăяo��
						p = p + 1;//�|�C���g+1
						explosion(enemy[i]);//����
						break;
					}
				}
			}
			//�e���₷����
			if (enemy[i].cooltime > 0) {
				enemy[i].cooltime--;//�N�[���^�C���̏���
			}
		}
	}
}
//2nd�̓G�̍X�V
void updatesecondEnemy()
{
	if (enemy2[0].enable == false) {
		q++;//�P�t���[�����ƂɂP�_���Z
		if (q == 500) {
			scene = cria;
		}
	}
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			//�G�������œ�����
			if (enemy2[i].x >= 650) {
				enemy2[i].x = enemy2[i].x + enemy2[i].vx;
			}
			if (enemy2[i].x == 648) {
				enemy2[i].y = enemy2[i].y + enemy2[i].vy;
			}
			if (enemy2[i].y >= 600) {
				enemy2[i].vy = -2;
			}
			if (enemy2[i].y <= 0) {
				enemy2[i].vy = 2;
			}
			//�e�𔭎˂���
			if (canEnemyShot(enemy2[i]))
			{
				if (enemy2[i].type == ENEMY1) {
					straightShot(180, enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY2) {
					straightShot(200, enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY3) {
					aimShot(enemy2[i]);//
				}
				if (enemy2[i].type == ENEMY4) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY5) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY6) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
					straightShot(0, enemy2[i]);//
					straightShot(20, enemy2[i]);
					straightShot(40, enemy2[i]);
					straightShot(60, enemy2[i]);
					straightShot(80, enemy2[i]);
					straightShot(100, enemy2[i]);
					straightShot(120, enemy2[i]);
					straightShot(140, enemy2[i]);
					straightShot(160, enemy2[i]);
					straightShot(180, enemy2[i]);
					straightShot(200, enemy2[i]);
					straightShot(220, enemy2[i]);
					straightShot(240, enemy2[i]);
					straightShot(260, enemy2[i]);
					straightShot(280, enemy2[i]);
					straightShot(300, enemy2[i]);
					straightShot(320, enemy2[i]);
					straightShot(340, enemy2[i]);
					straightShot(360, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY7) {
					tripleShot(160, enemy2[i]);//
					tripleShot(180, enemy2[i]);
					tripleShot(200, enemy2[i]);
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
					straightShot(0, enemy2[i]);//
					straightShot(20, enemy2[i]);
					straightShot(40, enemy2[i]);
					straightShot(60, enemy2[i]);
					straightShot(80, enemy2[i]);
					straightShot(100, enemy2[i]);
					straightShot(120, enemy2[i]);
					straightShot(140, enemy2[i]);
					straightShot(160, enemy2[i]);
					straightShot(180, enemy2[i]);
					straightShot(200, enemy2[i]);
					straightShot(220, enemy2[i]);
					straightShot(240, enemy2[i]);
					straightShot(260, enemy2[i]);
					straightShot(280, enemy2[i]);
					straightShot(300, enemy2[i]);
					straightShot(320, enemy2[i]);
					straightShot(340, enemy2[i]);
					straightShot(360, enemy2[i]);
					closerangeShot(enemy2[i]);//
				}if (enemy2[i].type == ENEMY8) {
				}
				enemy2[i].cooltime = 100;//
			}
			if (isHit(player, enemy2[i]) && BlackHole.enable == false)
			{
				if (AttackCoolTime == 0)
				{
					playerHp--;//�v���C���[��HP�����炷
					AttackCoolTime = 30;//�A�^�b�N�N�[���^�C�������
					playerBar.x2--;
				}
				if (playerHp == 0)
				{
					gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
				}
			}
			if (AttackCoolTime > 0)
			{
				AttackCoolTime--;
			}
			for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy2[i]))
					{
						kisidahp--;
						shot[j].enable = false;//�e�𖳌�
						//�������Ă���
						if (kisidahp == 0) {
							enemy2[i].enable = false;//�G�𖳌�
							PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//���j�G�t�F�N�g�̌Ăяo��
							explosion(enemy2[i]);//����
							break;
						}
						break;
					}
				}
			}
			//�e���₷����
			if (enemy2[i].cooltime > 0) {
				enemy2[i].cooltime--;//�N�[���^�C���̏���
			}
		}
	}
}
//1nd�̓G�̕`��
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawGraph(enemy[i].x - 10, enemy[i].y - 30, enemyimg, true);//�G�̕`��
		}
	}
}
//2nd�̓G�̕`��
void drawsecondEnemy()
{
	SetFontSize(20);
	for (int i = 0; i < EnemyNum; i++) {
		if (1 <= kisidahp && kisidahp <= 100 && scene == second) {
			DrawFormatString(320, 20, GetColor(25, 200, 0), "vs�ݓc�FHP%d", kisidahp);
		}
		if (enemy2[i].enable == true) {
			DrawGraph(enemy2[i].x - 10, enemy2[i].y - 40, kisidaimg, true);
		}
		if (scene == second && 75 <= kisidahp && kisidahp <= 100) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "���F������m�@�������̑�P�O�O����t������b\n�ݓc���Y��|����Ƃł��v���Ă���̂�");
		}
		if (scene == second && 50 <= kisidahp && kisidahp <= 74) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "�ǂ����|�C���������H�Ȃ�΂��炦�I�IHigherTax!!");
			//HigherTax ��@����
			enemy2[0].type = ENEMY5;
		}
		if (scene == second && 30 <= kisidahp && kisidahp <= 49) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "�ӂ�@�ǂ����G���ł͖����炵����");
			enemy2[0].type = ENEMY6;
		}if (scene == second && 1 <= kisidahp && kisidahp <= 29) {
			DrawFormatString(100, 550, GetColor(255, 0, 0), "���̎��ɑ��Ȃ����I�S�ˁI");
			enemy2[0].type = ENEMY7;
		}if (scene == second && kisidahp <= 0) {
			DrawFormatString(100, 500, GetColor(255, 0, 0), "���B�I�H\n���̑�P�O�O����t������b�ݓc���Y��������Ƃ͂���������������������������������������������������������������");
			enemy2[0].type = ENEMY8;
		}if (scene == second && kisidahp <= 0 && q >= 100) {
			DrawFormatString(130, 20, GetColor(255, 0, 0), "���{���񕷂����܂����H");
		}if (scene == second && kisidahp <= 0 && q >= 200) {
			DrawFormatString(150, 50, GetColor(255, 0, 0), "�I���B����M���ւ�");
		}if (scene == second && kisidahp <= 0 && q >= 300) {
			DrawFormatString(150, 80, GetColor(255, 0, 0), "������<���N�C�G��>�ł�");
		}
	}
}
//�e�����Ă邩�m�F����֐�
bool canEnemyShot(En enemy)
{
	//�e���₦�Ă���
	if (enemy.cooltime <= 0) {
		if (enemy.x >= 0 &&
			enemy.x < 800 &&
			enemy.y>0 &&
			enemy.y < 600)
		{
			//��ʂ̒��ɂ���
			return true;
		}
	}
	//��ʓ��ɂ��Ȃ�
	return false;
}