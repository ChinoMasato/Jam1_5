#pragma once
enum GameScene
{
	Title,
	Game,
	stand,
	second,
	gameover,
	cria
};
extern int score;//�_��
extern int b;
extern int p;
extern int t;
extern bool gameOverFlag;//�Q�[���I�[�o�[����
extern GameScene scene;
void updateGame();//�Q�[�����e�̍X�V
void drawGame();//�Q�[���֘A�̕`��
void secondUpdate();
