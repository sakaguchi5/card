#include"p.h"

Player::Player()
{
	// �O���t�B�b�N�̃��[�h
	
	img3 = LoadGraph("�g�����v.png");
	back = LoadGraph("�w�i2.png");
	//�w�i1
	//�g�����v.png
	/*
	for (int i = 1; i < 14; i++)
	{
		v.emplace_back(i);
	}*/
	hitvx.push_back(make_pair(0, 0));
	hitvx.push_back(make_pair(0, 1));
	hitvx.push_back(make_pair(0, 2));
	hitvx.push_back(make_pair(0, 3));

}

Player::~Player()
{
	
	DeleteGraph(img3);
	DeleteGraph(back);
}

void Player::Draw()
{
	// �}�E�X�̈ʒu���擾
	GetMousePoint(&MouseX, &MouseY);
	
	//�w�i�\��
	DrawGraphF(0, 0, back, TRUE);
	//�}�E�X�`�F�b�N
	mousecrick();
	/*
	drawstr();
	DrawRectGraph(231,458, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(448,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(231, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);//����
	DrawRectGraph( 17,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);*/
	
	//DrawRectGraph(232, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	// 
	drawfor();
}

void Player::drawfor()
{
	//1px=0.026458cm  100px=2.6458cm
	//19�}1	�͈�for�̂Ƃ��ɂ��炷�l
	//21/28
	int ix = 700;
	int iy = 70;
	//ix = 0;
	//iy = 0;
	int x1 = 0;

	

	for (auto x : v)
	{
		DrawRectGraph(x1+ix, yy * 2+iy, (x - 1) * xx, yy * 2, Tx, Ty, img3, FALSE, FALSE);
		x1 += 19;
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
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		// ������Ă���
		if (true)
		{
			auto result = std::find(hitvx.begin(), hitvx.end(), make_pair(MouseX, MouseY));
			if (result == hitvx.end()) {
				DrawFormatString(0,0, BoxCr, "not found ");
			}
			else {
				DrawFormatString(0,0, BoxCr, "found ");
			}
		}

	}
	else
	{
		// ������Ă��Ȃ�
	}
}
//backup
/*
void Player::drawfor()
{
	//1px=0.026458cm  100px=2.6458cm
	//19�}1	�͈�for�̂Ƃ��ɂ��炷�l
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