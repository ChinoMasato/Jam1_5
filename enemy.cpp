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

//�G�̏�����
void initEnemy()
{
	//���j�G�t�F�N�g
	explodese = LoadSoundMem("maou_se_battle_explosion05.mp3");

	//�G�̉摜
	enemyimg = LoadGraph("teki (1).png");

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
	enemy[2].x = 2000;//�G��X���W
	enemy[2].y = 200;//�G��Y���W
	enemy[2].r = 30;//�G�̑傫��
	enemy[2].color = GetColor(255, 0, 0);//�G�̐F
	enemy[2].fill = true;//�h��Ԃ����ۂ�
	enemy[2].enable = true;//�����Ă��邩����ł��邩
	enemy[2].vx = -2.0;//X�����̃X�s�[�h
	enemy[2].vy = 0.0;//Y�����̃X�s�[�h
	enemy[2].type = ENEMY3;//�e�̎��


	//2�X�e�[�W�ڂ̓G
	//1�̖ڂ̓G
	enemy2[0].x = 900;//�G��X���W
	enemy2[0].y = 400;//�G��Y���W
	enemy2[0].r = 30;//�G�̑傫��
	enemy2[0].color = GetColor(255, 0, 0);//�G�̐F
	enemy2[0].fill = true;//�h��Ԃ����ۂ�
	enemy2[0].enable = true;//�����Ă��邩����ł��邩
	enemy2[0].vx = -2.0;//X�����̃X�s�[�h
	enemy2[0].vy = 0.0;//Y�����̃X�s�[�h
	enemy2[0].type = ENEMY4;//�e�̎��

	//2�̖ڂ̓G
	enemy2[1].x = 1500;//�G��X���W
	enemy2[1].y = 300;//�G��Y���W
	enemy2[1].r = 30;//�G�̑傫��
	enemy2[1].color = GetColor(255, 0, 0);//�G�̐F
	enemy2[1].fill = true;//�h��Ԃ����ۂ�
	enemy2[1].enable = true;//�����Ă��邩����ł��邩
	enemy2[1].vx = -2.0;//X�����̃X�s�[�h
	enemy2[1].vy = 0.0;//Y�����̃X�s�[�h
	enemy2[1].type = ENEMY5;//�e�̎��

	//3�̖ڂ̓G
	enemy2[2].x = 2200;//�G��X���W
	enemy2[2].y = 500;//�G��Y���W
	enemy2[2].r = 30;//�G�̑傫��
	enemy2[2].color = GetColor(255, 0, 0);//�G�̐F
	enemy2[2].fill = true;//�h��Ԃ����ۂ�
	enemy2[2].enable = true;//�����Ă��邩����ł��邩
	enemy2[2].vx = -2.0;//X�����̃X�s�[�h
	enemy2[2].vy = 0.0;//Y�����̃X�s�[�h
	enemy2[2].type = ENEMY6;//�e�̎��

	
}
//�^�������e������
void straightShot(int rad,En ene)
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

void tripleShot(int rad,  En ene)
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

void twinShot( int rad, int shifty,En ene)
{
	for (int j = 0; j < EnemyShotNum; j++)
	{
		//���Ă�e���݂���
		if (enemyshot[j].enable == false) {
			//�e������
			enemyshot[j].x = ene.x;
			enemyshot[j].y = ene.y+shifty;
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
				enemy[i].vx= enemy[i].vx*1,02;
				enemy[i].vy= enemy[i].vy*1,02;
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
					twinShot(180,-5, enemy[i]);//�^������2��Œe�����ł���
					twinShot(180,5,enemy[i]);
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
		
			if (isHit(player, enemy[i]))
			{
				player.color = enemy[i].color;//�������Ă���
				gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
			}
		
			for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].enable = false;//�G�𖳌�
						shot[j].enable = false;//�e�𖳌�
						PlaySoundMem(explodese,DX_PLAYTYPE_BACK);//���j�G�t�F�N�g�̌Ăяo��
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
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			//�e�̎�ނɉ�����
			if (enemyshot[i].type == ENEMY1)
			{
				enemy2[i].vx = enemy2[i].vx * 1, 02;
				enemy2[i].vy = enemy2[i].vy * 1, 02;
			}
			//�G�������œ�����
			enemy2[i].x = enemy2[i].x + enemy2[i].vx;
			enemy2[i].y = enemy2[i].y + enemy2[i].vy;

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
					twinShot(180, -5, enemy2[i]);//
					twinShot(180, 5, enemy2[i]);
				}
				if (enemy2[i].type == ENEMY6) {
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
					closerangeShot(enemy2[i]);//
				}

				enemy2[i].cooltime = 100;//
			}

			if (isHit(player, enemy2[i]))
			{
				
				player.color = enemy2[i].color;//�������Ă���
				gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
			}

			for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy2[i]))
					{
						//�������Ă���
						enemy2[i].enable = false;//�G�𖳌�
						shot[j].enable = false;//�e�𖳌�
						PlaySoundMem(explodese, DX_PLAYTYPE_BACK);//���j�G�t�F�N�g�̌Ăяo��
						p = p + 1;//�|�C���g+1
						explosion(enemy2[i]);//����
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
			DrawGraph(enemy[i].x-10, enemy[i].y-40, enemyimg,true);//�G�̕`��
		}
	}
}
//2nd�̓G�̕`��
void drawsecondEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy2[i].enable == true) {
			DrawGraph(enemy2[i].x - 10, enemy2[i].y - 40, enemyimg, true);//�G�̕`��
		}
	}
}
//�e�����Ă邩�m�F����֐�
bool canEnemyShot(En enemy)
{
	//�e���₦�Ă���
	if (enemy.cooltime <= 0) {
		if(enemy.x >=0 &&
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