#include"p.h"

using GM = GameManager;
GameManager::GameManager()
{
	background = LoadGraph("�w�i2.png");
	img = LoadGraph("�g�����v.png");
	img2 = LoadGraph("�~�j�g�����v.png");
}

GameManager::GameManager(Suit s)
{
	background = LoadGraph("�w�i2.png");
	img = LoadGraph("�g�����v.png");
	img2 = LoadGraph("�~�j�g�����v.png");
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
			/*
			string a = "cpu";
			a += i;*/
			up_pBases[i] = make_unique<Cpu>("cpu", SSC(i));
		}
		pBase::getcardList()[i].second = SSC(i);
	}

	Clog = make_unique<Cardlog>();
}

void GameManager::mainLoop()
{
	Draw();
	for (auto& i : up_pBases)
	{
		i->Action();
		i->Draw();
	}

	if (pBase::getbDecisionBs().all())
	{
		Judge();
		pBase::bitreset();
		Clog->AddCardlog();
	}
	
}
void GameManager::Draw()
{
	//�w�i�\��
	DrawGraphF(0, 0, background, TRUE);
	auto ft = pBase::getfieldTime();
	auto CardLogArray = Clog->getCardlog();
	for (int i = 0; i < ft.fieldOrder-1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (CardLogArray[SIC(ft.fieldSuit)][i][j] == 0)
			{
				//DrawRectGraph(x.first - 4, x.second - Ty, urax, uray, Tx, Ty, img, FALSE, FALSE);
			}
			else
			{

			}
		}
	}
	


	//DrawGraphF(640, 150, img2, TRUE);
	//���O�\��
	drawstr();
	FieldTime fieldTime = pBase::getfieldTime();
	DrawFormatString(600, 0, GetColor(0, 0, 0), "�� %d�@�@�� %d�@�@���݂̎�� %d",
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
	auto chipL = pBase::getchipList();
	
	//S,H,D,C
	// �񎦃J�[�h��`��
	DrawFormatString(600, 30, GetColor(0, 0, 0), "p1 %d�@�@p2 %d�@�@p3 %d�@�@p4 %d",
		cL[0].first, cL[1].first, cL[2].first, cL[3].first);
	/**/
	// �����`�b�v��`��
	DrawFormatString(600, 60, GetColor(0, 0, 0), "p1 %d���@�@p2 %d���@�@p3 %d���@�@p4 %d��",
		chipL[0], chipL[1], chipL[2], chipL[3]);

	for (int i=0;auto& x : cardPlacement)
	{
		DrawFormatString(x.first, x.second, BoxCr, up_pBases[i]->getName().c_str());
		if (cL[i].first ==0)
		{
			DrawRectGraph(x.first - 4, x.second - Ty, urax, uray, Tx, Ty, img, FALSE, FALSE);
		}
		else
		{
			DrawRectGraph(x.first - 4, x.second - Ty, (cL[i].first - 1) * xx,yy * SIC(up_pBases[i]->getSuit())\
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
void GameManager::Judge()
{
	bitset<4>bs;

	auto v = pBase::getcardList();
	std::sort(v.begin(), v.end(), std::greater<Hands>{});
	bool a = true;
	for (auto itr = v.begin();/*itr < v.end()*/; itr++)
	{
		if (a)bs.set(SIC(itr->second));
		if (itr == v.end() - 1)break;
		if (itr->first != (itr + 1)->first)a = false;
	}

	//�S�����������A�܂�S�����҂̏ꍇ
	//bit�͑S��1�ƂȂ艽�����Ȃ�(�������^�[��)
	if (bs.all())return;

	int win = SIC(bs.count());
	int lose = 4 - win;

	for (int i = 0; i < 4; i++)
	{
		if (bs[i])
		{
			//vchip[i] += win;
			//pBase::chipList[i] += 6/win;
			pBase::getchipList()[i] += 6 / win;
		}
		else
		{
			//vchip[i] -= lose;
			pBase::getchipList()[i] -= 6 / lose;
		}
	}



	return;

	//auto amount 




	

	
}
void GameManager::Result(array<vector<Suit>, 2> result)
{
}

void GameManager::AddCardlog()
{
	
}
void drawFieldCard()
{

}