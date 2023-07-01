#include "en.h"
#include "DxLib.h"
#include "shot.h"
#include "player.h"

En player;//�v���C���[
int shotse;
//�v���C���[�̏�����
void initPlayer()
{
	player.x = 100;
	player.y = 200;
	player.r = 10;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;
	shotse = LoadSoundMem("maou_se_battle07.mp3");

	playerimg= LoadGraph("UFO.png");

}

//�v���C���[�̍X�V
void updatePlayer()
{
	//�v���C���[�𓮂���
	if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
	{
		player.x = player.x + 2.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) == 1)
	{
		player.x = player.x - 2.0;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		player.y = player.y - 2.0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		player.y = player.y + 2.0;
	}
	if (player.x < 0) {
		//�������[�ɏo����
		player.x = 0;
	}
	if (player.x >= 800) {
		//�����E�[�ɏo����
		player.x = 800;
	}
	if (player.y < 0) {
		//�������[�ɏo����
		player.y = 0;
	}
	if (player.y >= 600) {
		//�����E�[�ɏo����
		player.y = 600;
	}

	//�e��������
	if (CheckHitKey(KEY_INPUT_Z) == 1 &&
		player.cooltime <= 0)
	{
		//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
		for (int i = 0; i < ShotNum; i++)
		{
			//���Ă�e���݂���
			if (shot[i].enable == false) {
				//�e������
				shot[i].x = player.x;
				shot[i].y = player.y;
				shot[i].enable = true;
				player.cooltime = 30;//�A�ˑ��x�@�������قǘA�˂ł���
				PlaySoundMem(shotse, DX_PLAYTYPE_BACK);
				break;
			}
		}
	}
	//�e���₷����
	if (player.cooltime > 0) {
		player.cooltime--;
	}
}

//�v���C���[�̕`��
void drawPlayer()
{
	DrawGraph(player.x-40, player.y-30, playerimg,true);

}