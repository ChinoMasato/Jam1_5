#include "DxLib.h"
#include "bgsprite.h"
int bgimg0;//�w�i�摜1
int bgimg1;//�w�i�摜2
int bgimg2;//�w�i�摜3
double scrollX1 = 0.0;//�X�N���[���̊֐�
double scrollX2 = 800.0;//�X�N���[���̊֐�
double scrollX3 = 0.0;//�X�N���[���̊֐�
double scrollX4 = 800.0;//�X�N���[���̊֐�
//�w�i�X�v���C�g�̏�����
void initBg()
{
	bgimg0 = LoadGraph("IMG_6884 (1).jpg");//�w�i�摜1
	bgimg1 = LoadGraph("IMG_6884 (1).jpg");//�w�i�摜2
	bgimg2 = LoadGraph("IMG_6884 (1).jpg");//�w�i�摜3

}
//�w�i�ړ��̏���
double scroll(double x, double speed)//�X�N���[���̈ʒu�ƃX�s�[�h�̊֐�
{
	x = x - speed;//�w�i�̐i�ރX�s�[�h
	if (x <= -800.0)//�摜1�������ɃY������
	{

		x = x + 1600.0;//�摜2�����E�ɖ߂�
	}
	return x;
}
//�w�i�X�v���C�g�̍X�V
void updateBg()
{
	//�X�N���[��
	scrollX1 = scroll(scrollX1, 1.0);//�X�N���[���̊֐�
	scrollX2 = scroll(scrollX2, 1.0);//�X�N���[���̊֐�

	scrollX3 = scroll(scrollX3, 1.0);//�X�N���[���̊֐�
	scrollX4 = scroll(scrollX4, 1.0);//�X�N���[���̊֐�
}
//�w�i�̕`��
void drawBg()
{
	DrawGraph(scrollX1, 0, bgimg0, true);//�w�i�摜1�̃X�N���[��
	DrawGraph(scrollX2, 0, bgimg1, true);//�w�i�摜2�̃X�N���[��
	DrawGraph(scrollX3, 0, bgimg2, true);//�w�i�摜3�̃X�N���[��
}