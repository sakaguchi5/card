#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include"p.h"

using namespace std;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdline, _In_ int nShowCmd)
{
	//window���[�h�ؑ�
	ChangeWindowMode(TRUE);
	//window�T�C�Y
	//SetGraphMode(800, 600, 32);
	//1920�~1080
	//1280�~720
	SetGraphMode(1280, 720, 32);
	//�o�b�N�O���E���h�����̋���
	SetAlwaysRunFlag(TRUE);
	//���d�N���̋���
	SetDoubleStartValidFlag(TRUE);

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) return -1;

	//�o�b�N�o�b�t�@������
	SetDrawScreen(DX_SCREEN_BACK);

	auto p = make_unique<Player>();
	// �O���t�B�b�N�̃��[�h
	//int img = LoadGraph("t.jpg");
	int MouseX, MouseY;
	int StringCr, BoxCr;

	// �}�E�X��\����Ԃɂ���
	SetMouseDispFlag(TRUE);

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);

	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);

	while (TRUE)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		//��ʃN���A
		ClearDrawScreen();
		 
		// �}�E�X�̈ʒu���擾
		GetMousePoint(&MouseX, &MouseY);
		// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă����������������
		//DrawBox(0, 0, 640, 32, BoxCr, TRUE);
		p->Action();
		p->Draw();

		// ���W�������`��
		DrawFormatString(1000, 0, BoxCr, "���W�w %d�@�@���W�x %d", MouseX, MouseY);
		//DrawGraphF(100, 100, img, TRUE);
		//DrawRectGraph(0, 0, 0, 0, 108, 150, img, FALSE, FALSE);
		//DrawRectGraph(18, 0, 113, 0, 108, 150, img, FALSE, FALSE);
		//��ʍX�V
		ScreenFlip();

		if (ProcessMessage() == -1) break;
	}
	// �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	//DeleteGraph(img);

	//Dx���C�u�����I������
	DxLib_End();
	return 0;
}