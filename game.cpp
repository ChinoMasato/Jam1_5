#include "DxLib.h"
#include "game.h"
#include"en.h"
#include "player.h"
#include "effect.h"

//�Q�[���֘A�̏��
int score = 0;//�_��
int t = 0;
int p = 0;
int b = 0;
bool gameOverFlag = false;//�Q�[���I�[�o�[����

//�Q�[�����e�̍X�V
void updateGame()
{
	if (gameOverFlag == false) {
		score++;//�P�t���[�����ƂɂP�_���Z
	}
	if (score == 100) {
		t = t + 1;
		score = 0;
	}
	if (t >= 10) {
		scene = stand;
		
	}
	if (p >= 2) {
		scene = stand;
		
	}
	
}
void secondUpdate()
{
	if (gameOverFlag == false) {
		score++;//�P�t���[�����ƂɂP�_���Z
	}
	if (score == 100) {
		t = t + 1;
		score = 0;
	}
	if (t >=20)
	{
		scene = cria;
	}
	if (p >= 4)
	{
		scene = cria;
	}
}

//�Q�[�����̕`��
void drawGame()
{

	DrawFormatString(0, 0, GetColor(255, 255, 0), "�^�C�� %d �_", t);
	DrawFormatString(0, 20, GetColor(255, 255, 0), "�X�R�A %d �_", p);
	if (gameOverFlag == true) {
		scene = gameover;
		
		//DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}
	
}