#pragma once

const int EffectNum = 100;
extern int img[10];//�ő�P�O�R�}�@�摜
struct Effect
{
	double x;
	double y;
	double animeNo=0;
	double mazAnimeNo;
	bool enable = false;

};
extern Effect effe[EffectNum];//�G�t�F�N�g�p�̕ϐ�
void initEffect();
void updateEffect();
void drawEffect();