#include"p.h"

#include<iterator>
Player::Player(string str, Suit s):pBase(str, s)
{
	// グラフィックのロード
	
	img3 = LoadGraph("トランプ.png");
	//背景1
	//トランプ.png
	

	reHitbox();
	
}

Player::~Player()
{
	
	DeleteGraph(img3);
}
void Player::Action()
{
	if (int esc=0;CheckHitKey(KEY_INPUT_RETURN) == 0)
	{
		// 押されていない
		if (esc > 0)
			esc = -1;		// ESCキーが離れた瞬間
		else
			esc = 0;		// ESCキーが離れている状態
	}
	else
	{
		// 押されている
		esc++;				// ESCキーが押されている間は値を増やし続ける
		if (esc == 1)
		{/*
			if (Card!=0)
			{
				choiceCard(Card);
			}*/
		}
		/**/
		if (Card != 0)
		{
			choiceCard(Card);
		}
	}
	choice();

}
void Player::Draw()
{
	// マウスの位置を取得
	GetMousePoint(&MouseX, &MouseY);
	
	
	
	
	drawstr();/*
	DrawRectGraph(231,458, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(448,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(231, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);//決定
	DrawRectGraph( 17,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);*/
	
	//DrawRectGraph(232, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	// 
	drawfor();
}

void Player::choice()
{
	//マウスチェック
	mousecrick();
}
void Player::drawfor()
{
	//1px=0.026458cm  100px=2.6458cm
	//19±1	範囲forのときにずらす値
	//21/28
	int ix = 700;
	int iy = 70;
	//ix = 0;
	//iy = 0;
	int x1 = 0;

	
	//DrawFormatString(1000,100, BoxCr, "x:%d y%d", x1 + ix, yy * 2 + iy);
	for (auto x : v)
	{
		DrawRectGraph(x1+ix, 300+iy, (x - 1) * xx, yy * 2, Tx, Ty, img3, FALSE, FALSE);
		
		x1 += 20;
	}
}


void Player::drawstr()
{
	//DrawBox(0, 0, 640, 32, BoxCr, TRUE);

	DrawFormatString(231+4,458+Ty+4, BoxCr, "S Player1 ");
	DrawFormatString(448+4,234+Ty+4, BoxCr, "H Player2 ");
	DrawFormatString(231+4, 14+Ty+4, BoxCr, "D Player3 ");
	DrawFormatString( 17+4,234+Ty+4, BoxCr, "C Player4 ");

	//DrawFormatString( 0,0, BoxCr, "");
	//S,H,D,C
}
void Player::mousecrick()
{
	auto Mouse = make_pair(MouseX, MouseY);//Mouseのペアを作成
	
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0&&v.size()!= 0)
	{
		// 押されている
		/*auto result = std::find_if(hitvx.begin(), hitvx.end(), \
			[=](Pair x){return  0 < MouseX - x.first && MouseX - x.first < 21 \
					&& 0 < MouseY - x.second && MouseY - x.second < Ty;});*/
		auto result = std::find_if(hitvx.begin(), hitvx.end(), \
			[=](Pair x) {return	make_pair(0, 0) < Mouse - x && \
								Mouse - x < make_pair(21, Ty); });
		if (result == hitvx.end()) 
		{
			/*
			if (0 < MouseX - (*hitvx.rbegin()).first && MouseX - (*hitvx.rbegin()).first < Tx \
			&& 0 < MouseY - (*hitvx.rbegin()).second && MouseY - (*hitvx.rbegin()).second < Ty)*/
			if (make_pair(0, 0) < Mouse - hitvx.back() && \
				Mouse - hitvx.back() < make_pair(Tx, Ty))
			{
				Card = v.back();
				DrawFormatString(0, 0, BoxCr, "found %d", Card);
			}
			else
			{
				DrawFormatString(0, 0, BoxCr, "not found ");
			}
		}
		else
		{
			//(*hitvx.rbegin()).first;
			//result
			int d = (int)std::distance(hitvx.begin(), result);
			Card = v[d];
			DrawFormatString(0, 0, BoxCr, "found %d", Card);
		}
			
		
	}
	else
	{
		// 押されていない
	}
}

void Player::reHitbox()
{
	int ix = 700;
	int iy = 70;
	
	for (auto& i : v)
	{
		hitvx.push_back(make_pair(ix, 300+iy));
		ix += 20;
	}

	
}

void Player::choiceCard(int card)
{
	erase(v, card);
	hitvx.pop_back();
	Card = 0;
}

//backup
/*
void Player::drawfor()
{
	//1px=0.026458cm  100px=2.6458cm
	//19±1	範囲forのときにずらす値
	//21/28
	int ix = 700;
	int iy = 70;
	//ix = 0;
	//iy = 0;
	int x1 = 0;
	//int x2 = 0;
	for (auto x : v)
	{
		DrawRectGraph(x1+ix, 0+iy, (x - 1) * xx, 0, Tx, Ty, img3, FALSE, FALSE);
		x1 += 18;
	}
	x1 = 0;
	for (auto x : v)
	{
		DrawRectGraph(x1+ix, yy+iy, (x - 1) * xx, yy, Tx, Ty, img3, FALSE, FALSE);
		x1 += 20;
	}
	x1 = 0;
	for (auto x : v)
	{
		DrawRectGraph(x1+ix, yy * 2+iy, (x - 1) * xx, yy * 2, Tx, Ty, img3, FALSE, FALSE);
		x1 += 19;
	}
}
*/