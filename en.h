#pragma once
#include <map>
enum EnemyType
{
	ENEMY1,//�G�^�C�v�P
	ENEMY2,//�G�^�C�v�Q
	ENEMY3,//�G�^�C�v�R
	ENEMY4,//�G�^�C�v�S
	ENEMY5, //�G�^�C�v�T
	ENEMY6,
	ENEMY7, ENEMY8
};
struct MovePattern
{
	double vx;
	double vy;
};
//�~�̍\����
struct En
{
	EnemyType type;//�G�̎��
	double x;//X���W
	double y;//Y���W
	double r;//���a
	int color;//�~�̐F
	bool fill;//�h��Ԃ����ۂ�
	double vx;//���̈ړ���
	double vy;//�c�̈ړ���
	double vvx;//���̈ړ��ʂ̑���
	double vvy;//�c�̈ړ��ʂ̑���
	bool enable;//�L���t���O�i�����Ă邩�A����ł邩�j
	int cooltime;//�A�˂ł��Ȃ��悤�ɂ���^�C�}�[
	int counter;
	int spawnTiming;//�o���^�C�~���O
	std::map<int, MovePattern> pattern;
};
struct Box
{
	double x1;//X���W
	double y1;//Y���W
	double x2;//X���W
	double y2;//Y���W
	int color;//�~�̐F
	bool fill;//�h��Ԃ����ۂ�
};
bool isHit(En en1, En en2);//�����蔻��֐�
bool isRight(En shot, En target);//�i�s�����̉E�ɂ��邩
void RotVec(En& shot, double r);