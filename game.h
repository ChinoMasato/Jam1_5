#pragma once
#include "en.h"

enum GameScene
{
	Title,
	Game,
	stand,
	second,
	gameover,
	cria
};
extern Box playerBar;
extern Box playerBarBox;
extern int score;//�_��
extern int b;
extern int p;
extern int t;
extern int selectbomb;
extern bool gameOverFlag;//�Q�[���I�[�o�[����
extern GameScene scene;
void initGame();
void updateGame();//�Q�[�����e�̍X�V
void drawGame();//�Q�[���֘A�̕`��
void secondUpdate();
void SelectBomb();