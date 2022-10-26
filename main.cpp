#pragma once
#include "DxLib.h"
#include <list>
#include <memory>
#include"p.h"

using namespace std;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE,
	_In_ LPWSTR lpCmdline, _In_ int nShowCmd)
{
	//windowモード切替
	ChangeWindowMode(TRUE);
	//windowサイズ
	//SetGraphMode(800, 600, 32);
	//1920×1080
	//1280×720
	SetGraphMode(1280, 720, 32);
	//バックグラウンド処理の許可
	SetAlwaysRunFlag(TRUE);
	//多重起動の許可
	SetDoubleStartValidFlag(TRUE);

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) return -1;

	//バックバッファを準備
	SetDrawScreen(DX_SCREEN_BACK);

	auto p = make_unique<Player>();
	// グラフィックのロード
	//int img = LoadGraph("t.jpg");
	int MouseX, MouseY;
	int StringCr, BoxCr;

	// マウスを表示状態にする
	SetMouseDispFlag(TRUE);

	// 白色の値を取得
	StringCr = GetColor(255, 255, 255);

	// 黒の値を取得
	BoxCr = GetColor(0, 0, 0);

	while (TRUE)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		//画面クリア
		ClearDrawScreen();
		 
		// マウスの位置を取得
		GetMousePoint(&MouseX, &MouseY);
		// 画面左上の領域に黒い四角を描き前に描いてあった文字列を消す
		//DrawBox(0, 0, 640, 32, BoxCr, TRUE);
		p->Action();
		p->Draw();

		// 座標文字列を描く
		DrawFormatString(1000, 0, BoxCr, "座標Ｘ %d　　座標Ｙ %d", MouseX, MouseY);
		//DrawGraphF(100, 100, img, TRUE);
		//DrawRectGraph(0, 0, 0, 0, 108, 150, img, FALSE, FALSE);
		//DrawRectGraph(18, 0, 113, 0, 108, 150, img, FALSE, FALSE);
		//画面更新
		ScreenFlip();

		if (ProcessMessage() == -1) break;
	}
	// 読み込んだ画像のグラフィックハンドルを削除
	//DeleteGraph(img);

	//Dxライブラリ終了処理
	DxLib_End();
	return 0;
}