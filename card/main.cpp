//�ڑ�����鑤
#pragma once
#include "main.h"
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdline, _In_ int nShowCmd)
{
	//Log.txt�𐶐����Ȃ��悤�ɐݒ�
	SetOutApplicationLogValidFlag(FALSE);
	//window���[�h�ؑ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	
	//�o�b�N�O���E���h�����̋���
	SetAlwaysRunFlag(TRUE);
	//���d�N���̋���
	SetDoubleStartValidFlag(TRUE);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) return -1;

	//�o�b�N�o�b�t�@������
	SetDrawScreen(DX_SCREEN_BACK);

	

	// �ڑ����Ă��邩�d�r�b�L�[���������܂Ń��[�v
	while (!ProcessMessage() && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//��ʃN���A
		ClearDrawScreen();
		//���X�g�̏���
		
		//��ʍX�V
		ScreenFlip();
	}
	//�ڑ���Ԃ�����
	StopListenNetWork();

	//Dx���C�u�����I������
	DxLib_End();
	return 0;
}