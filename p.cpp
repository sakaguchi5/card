#include"p.h"

Player::Player()
{
	// グラフィックのロード
	
	img3 = LoadGraph("トランプ.png");
	back = LoadGraph("背景2.png");
	//背景1
	//トランプ.png
	/*
	for (int i = 1; i < 14; i++)
	{
		v.emplace_back(i);
	}*/
}

Player::~Player()
{
	
	DeleteGraph(img3);
	DeleteGraph(back);
}

void Player::Draw()
{
	DrawGraphF(0, 0, back, TRUE);
	//DrawRectGraph(230+xx, 12, 0, 0, Tx, Ty, img3, FALSE, FALSE);
	//DrawRectGraph(230+xx-8, 12, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(231, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);//決定
	//DrawRectGraph(232, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	// 
	//drawfor();
}

void Player::drawfor()
{
	//1px=0.026458cm  100px=2.6458cm
	//19±1	範囲forのときにずらす値
	//21/28
	//DrawRectGraph(0, 0, 0, 0, Tx, Ty, img3, FALSE, FALSE);
	//DrawRectGraph(20, 0, 0, 0, Tx, Ty, img3, FALSE, FALSE);


	int x1 = 0;
	//int x2 = 0;
	for (auto x : v)
	{
		//DrawRectGraph((x - 1) * 20, 0, (x-1) * 114, 0, 108, 150, img, FALSE, FALSE);

		DrawRectGraph(x1, 0, (x - 1) * xx, 0, Tx, Ty, img3, FALSE, FALSE);
		x1 += 18;
	}
	x1 = 0;
	for (auto x : v)
	{
		//DrawRectGraph((x - 1) * 20, 0, (x-1) * 114, 0, 108, 150, img, FALSE, FALSE);

		DrawRectGraph(x1, yy, (x - 1) * xx, yy, Tx, Ty, img3, FALSE, FALSE);
		x1 += 20;
	}
	x1 = 0;
	for (auto x : v)
	{
		//DrawRectGraph((x - 1) * 20, 0, (x-1) * 114, 0, 108, 150, img, FALSE, FALSE);

		DrawRectGraph(x1, yy * 2, (x - 1) * xx, yy * 2, Tx, Ty, img3, FALSE, FALSE);
		x1 += 19;
	}
	/*
	int x1 = 0;
	//int x2 = 0;
	for(auto x:v)
	{
		//DrawRectGraph((x - 1) * 20, 0, (x-1) * 114, 0, 108, 150, img, FALSE, FALSE);

		DrawRectGraph(x1, 0, (x - 1) * 114, 0, 108, 150, img, FALSE, FALSE);
		x1 += 20;
	}*/
	//DrawGraphF(100, 100, img2, TRUE);
}
