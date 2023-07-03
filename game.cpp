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

int selectbomb;
int clickcooltime;

Box playerBar;
Box playerBarBox;


void initGame()
{
	playerBar.x1 = 550;
	playerBar.x2 = 750;
	playerBar.y1 = 20;
	playerBar.y2 = 50;
	playerBar.color = GetColor(255, 255, 255);
	playerBar.fill = true;

	playerBarBox.x1 = 550;
	playerBarBox.x2 = 750;
	playerBarBox.y1 = 20;
	playerBarBox.y2 = 50;
	playerBarBox.color = GetColor(255, 255, 255);
	playerBarBox.fill = false;

	selectbomb = 0;
	clickcooltime = 0;
}


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
	
	if (p >= 80) {
		scene = stand;
		
	}

	if (playerBar.x2 <= 600)
	{
		playerBar.color = GetColor(255, 0, 0);//�m���ɂȂ�����Ԃ�����
	}

	SelectBomb();
	
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
	
	//if (p >= 4)
	//{
		//scene = cria;
	//}


	if (playerBar.x2 <= 600)
	{
		playerBar.color = GetColor(255, 0, 0);//�m���ɂȂ�����Ԃ�����
	}

	SelectBomb();
}


void SelectBomb() {
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1 && clickcooltime == 0)
	{
		selectbomb++;
		clickcooltime = 50;
		if (selectbomb >= 2)
		{
			selectbomb = 2;
		}
	}

	if (CheckHitKey(KEY_INPUT_LEFT) == 1 && clickcooltime == 0)
	{
		selectbomb--;
		clickcooltime = 50;
		if (selectbomb <= 0)
		{
			selectbomb = 0;
		}
	}

	if (clickcooltime > 0)
	{
		clickcooltime--;
	}
}


//�Q�[�����̕`��
void drawGame()
{
	SetFontSize(15);
	DrawFormatString(0, 0, GetColor(255, 255, 0), "�^�C�� %d �_", t);
	DrawFormatString(0, 20, GetColor(255, 255, 0), "�X�R�A %d �_", p);
	if (selectbomb == 0)
	{
		DrawFormatString(650, 570, GetColor(255, 255, 255), "�m�[�}���V���b�g");
	}
	if (selectbomb == 1)
	{
		DrawFormatString(650, 570, GetColor(255, 255, 255), "�u���b�N�z�[��");
	}
	if (selectbomb == 2)
	{
		DrawFormatString(650, 570, GetColor(255, 255, 255), "���C���C");
	}
	DrawBox(playerBar.x1, playerBar.y1, playerBar.x2, playerBar.y2, playerBar.color, playerBar.fill);
	DrawBox(playerBarBox.x1, playerBarBox.y1, playerBarBox.x2, playerBarBox.y2, playerBarBox.color, playerBarBox.fill);
	if (gameOverFlag == true) {
		scene = gameover;

		//DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}

}