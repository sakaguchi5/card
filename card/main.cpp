//接続される側
#pragma once
#include "main.h"
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdline, _In_ int nShowCmd)
{
	//Log.txtを生成しないように設定
	SetOutApplicationLogValidFlag(FALSE);
	//windowモード切替
	ChangeWindowMode(TRUE);
	//windowサイズ
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	
	//バックグラウンド処理の許可
	SetAlwaysRunFlag(TRUE);
	//多重起動の許可
	SetDoubleStartValidFlag(TRUE);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) return -1;

	//バックバッファを準備
	SetDrawScreen(DX_SCREEN_BACK);

	

	// 接続してくるかＥＳＣキーが押されるまでループ
	while (!ProcessMessage() && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//画面クリア
		ClearDrawScreen();
		//リストの処理
		
		//画面更新
		ScreenFlip();
	}
	//接続状態を解除
	StopListenNetWork();

	//Dxライブラリ終了処理
	DxLib_End();
	return 0;
}