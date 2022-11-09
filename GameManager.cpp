#include"p.h"
using GM = GameManager;
GameManager::GameManager()
{
	background = LoadGraph("�w�i2.png");
	img = LoadGraph("�g�����v.png");
}

GameManager::GameManager(Suit s)
{
	background = LoadGraph("�w�i2.png");
	img = LoadGraph("�g�����v.png");
	cardPlacement[0] = make_pair(231 + 4, 458 + Ty + 4);
	cardPlacement[1] = make_pair(448 + 4, 234 + Ty + 4);
	cardPlacement[2] = make_pair(231 + 4,  14 + Ty + 4);
	cardPlacement[3] = make_pair( 17 + 4, 234 + Ty + 4);
	//static short int i = 0;
	/*
	if (e == s)//s�̓v���C���[�̃X�[�g
	{
		up_pBases[(int)e] = make_unique<Player>(_sp, e, pot);
	}
	else
	{
		up_pBases[(int)e] = make_unique<Cpu>(_sp, e, i, pot);
		i++;
	}*/
	for (int i = 0; i < 4; i++)
	{
		if (i == SIC(s))
		{
			up_pBases[i] = make_unique<Player>("Player", SSC(i));
		}
		else
		{
			up_pBases[i] = make_unique<Cpu>("cpu", SSC(i));
		}
	}

}

void GameManager::mainLoop()
{
	Draw();
	for (auto& i : up_pBases)
	{
		i->Action(fieldTime);
		i->Draw();
	}
	
}
void GameManager::Draw()
{
	//�w�i�\��
	DrawGraphF(0, 0, background, TRUE);
	//���O�\��
	drawstr();

	DrawFormatString(800, 20, GetColor(0, 0, 0), "�� %d�@�@�� %d�@�@���݂̎�� %d",
		fieldTime.fieldSuit, fieldTime.fieldOrder, fieldTime.currentSuit);
	

}

void GameManager::drawstr()
{
	// ���̒l���擾
	int BoxCr = GetColor(0, 0, 0);
	//DrawBox(0, 0, 640, 32, BoxCr, TRUE);
	/*
	DrawFormatString(231 + 4, 458 + Ty + 4, BoxCr, "S Player1 ");
	DrawFormatString(448 + 4, 234 + Ty + 4, BoxCr, "H Player2 ");
	DrawFormatString(231 + 4, 14 + Ty + 4, BoxCr, "D Player3 ");
	DrawFormatString(17 + 4, 234 + Ty + 4, BoxCr, "C Player4 ");*/
	auto cL = pBase::getcardList();
	//S,H,D,C
	// ���W�������`��
	DrawFormatString(800, 60, GetColor(0, 0, 0), "p1 %d�@�@p2 %d�@�@p3 %d�@�@p4 %d",
		cL[0], cL[1], cL[2], cL[3]);

	for (int i=0;auto& x : cardPlacement)
	{
		DrawFormatString(x.first, x.second, BoxCr, up_pBases[i]->getName().c_str());
		if (cL[i]==0)
		{
			DrawRectGraph(x.first - 4, x.second - Ty, urax, uray, Tx, Ty, img, FALSE, FALSE);
		}
		else
		{
			DrawRectGraph(x.first - 4, x.second - Ty, (cL[i] - 1) * xx,yy * SIC(up_pBases[i]->getSuit())\
				, Tx, Ty, img, FALSE, FALSE);
		}

		

		//DrawFormatString(x.first, x.second, BoxCr, "S Player1 ");
		i++;
	}
	/*
	DrawRectGraph(231,458, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(448,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);
	DrawRectGraph(231, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);//����
	DrawRectGraph( 17,234, urax, uray, Tx, Ty, img3, FALSE, FALSE);*/

	//S,H,D,C
}
void drawFieldCard()
{

}