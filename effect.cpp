#include "effect.h"
#include "DxLib.h"
Effect effe[EffectNum];//�G�t�F�N�g�p�̕ϐ�
int img[10];//�ő�P�O�R�}�@�摜
//�G�t�F�N�g�̏�����
void initEffect()
{

	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);//�摜�̓ǂݍ���
}
//�G�t�F�N�g�̍X�V
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			
			effe[i].animeNo = effe[i].animeNo + 0.1;//�A�j���[�V������i�߂�
			
			if ((int)(effe[i].animeNo) > 5) {//�U�R�}�ڂɂȂ�����I��
				effe[i].enable = false;//�G�t�F�N�g����������
			}
		}
	}
}
//�G�t�F�N�g�̕`��
void drawEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			int no = effe[i].animeNo;//�G�t�F�N�g�̃R�}��
			DrawGraph(effe[i].x, effe[i].y, img[no],true);//�G�t�F�N�g�̕`��
		}
	}
}