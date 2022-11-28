#include"p.h"

using GM = GameManager;
GameManager::GameManager()
{
	background = LoadGraph("背景2.png");
	img = LoadGraph("トランプ.png");
	img2 = LoadGraph("ミニトランプ.png");
}

GameManager::GameManager(Suit s)
{
	background = LoadGraph("背景2.png");
	img = LoadGraph("トランプ.png");
	img2 = LoadGraph("ミニトランプ.png");
	cardPlacement[0] = make_pair(231 + 4, 458 + Ty + 4);
	cardPlacement[1] = make_pair(448 + 4, 234 + Ty + 4);
	cardPlacement[2] = make_pair(231 + 4,  14 + Ty + 4);
	cardPlacement[3] = make_pair( 17 + 4, 234 + Ty + 4);
	//std::rotate(cardPlacement.begin(), cardPlacement.begin() + SIC(s), cardPlacement.end());
	std::rotate(cardPlacement.rbegin(), cardPlacement.rbegin() + SIC(s), cardPlacement.rend());
	//static short int i = 0;
	/*
	if (e == s)//sはプレイヤーのスート
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
		if (pBase::getbDecisionBs().all())time++;
		if (pBase::getbDecisionBs().all() && time == 1)
		{
			//time++;
			r = true;
			Clog->AddCardlog();
			

		}
		if (pBase::getbDecisionBs()[SIC(pBase::getfieldTime().currentSuit)])
		{
			
			if (!pBase::getbDecisionBs().all())
			{++pBase::getfieldTime();

			}

			if (pBase::getbDecisionBs().all()/* */&& time == 360)
			{
				Judge();
				pBase::bitreset();				
				time = 0;
				r = false;++pBase::getfieldTime();
			}
			//++pBase::getfieldTime();
		}
		//pBase::getbDecisionBs()[SIC(pBase::getfieldTime().currentSuit)];
		i->Draw();
	}
	/*
	if (pBase::getbDecisionBs().all())
	{
		Judge();
		pBase::bitreset();
		Clog->AddCardlog();
	}*/
	
	
}
void GameManager::Draw()
{
	//背景表示
	DrawGraphF(0, 0, background, TRUE);
	auto ft = pBase::getfieldTime();
	auto CardLogArray = Clog->getCardlog();
	int uraax = 210;
	int uraay = 180;
	int tx = 35;
	int ty = 45;
	//for (int i = 0; i < ft.fieldOrder-1; i++)
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (CardLogArray[SIC(ft.fieldSuit)][i][j] == 0)
			{
				//DrawRectGraph(650+29*i*j, 100+35*i*j, uraax, uraay, tx, ty, img2, FALSE, FALSE);
				//DrawGraphF(640, 150, img2, TRUE);
				DrawRectGraph(700 + 29*(i), 130 + 35*j, 210, 180,29, 39, img2, FALSE, FALSE);
			}
			else
			{
				//DrawRectGraph(600 - 4, 600 - Ty, urax, uray, Tx, Ty, img2, FALSE, FALSE);
				//DrawGraphF(640, 150, img2, TRUE);
				DrawRectGraph(700 + 29 * (i ), 130 + 35 * j,
					tx* (CardLogArray[SIC(ft.fieldSuit)][i][j]-1), ty*j,
					29, 39, img2, FALSE, FALSE);
			}
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//DrawRectGraph(640 + 29 * (i - 1), 280 + 35 * j, 210, 180, 29, 39, img2, FALSE, FALSE);

			if (CardLogArray[SIC(ft.fieldSuit)][i][j] == 0)
			{
				//DrawRectGraph(640 + 29 * (i), 280 + 35 * j, 210, 180, 29, 39, img2, TRUE, FALSE);
			}

			if (CardLogArray[SIC(ft.fieldSuit)][i][j] == 0)
			{
				//DrawRectGraph(650+29*i*j, 100+35*i*j, uraax, uraay, tx, ty, img2, FALSE, FALSE);
				//DrawGraphF(640, 150, img2, TRUE);
				//DrawRectGraph(640 + 29 * (i ), 280 + 35 * j, 210, 180, 29, 39, img2, FALSE, FALSE);
			}
			else
			{
				//DrawRectGraph(600 - 4, 600 - Ty, urax, uray, Tx, Ty, img2, FALSE, FALSE);
				//DrawGraphF(640, 150, img2, TRUE);
				DrawRectGraph(700 + 29 * (CardLogArray[SIC(ft.fieldSuit)][i][j] - 1), 280 + 35 * j,
					tx * (CardLogArray[SIC(ft.fieldSuit)][i][j] - 1), ty * j,
					29, 39, img2, FALSE, FALSE);
			}
		}
	}
	//DrawGraphF(640-29, 280, img2, TRUE);


	//DrawGraphF(640, 150, img2, TRUE);
	//名前表示
	drawstr();
	FieldTime fieldTime = pBase::getfieldTime();
	DrawFormatString(600, 0, GetColor(0, 0, 0), "場 %d　　巡 %d　　現在の手番 %d",
		fieldTime.fieldSuit, fieldTime.fieldOrder, fieldTime.currentSuit);
	

}

void GameManager::drawstr()
{
	// 黒の値を取得
	int BoxCr = GetColor(0, 0, 0);
	/*
	DrawFormatString(231 + 4, 458 + Ty + 4, BoxCr, "S Player1 ");
	DrawFormatString(448 + 4, 234 + Ty + 4, BoxCr, "H Player2 ");
	DrawFormatString(231 + 4, 14 + Ty + 4, BoxCr, "D Player3 ");
	DrawFormatString(17 + 4, 234 + Ty + 4, BoxCr, "C Player4 ");*/
	auto cL = pBase::getcardList();
	auto chipL = pBase::getchipList();
	
	//S,H,D,C
	// 提示カードを描く
	DrawFormatString(600, 30, GetColor(0, 0, 0), "p1 %d　　p2 %d　　p3 %d　　p4 %d",
		cL[0].first, cL[1].first, cL[2].first, cL[3].first);
	/**/
	// 所持チップを描く
	DrawFormatString(600, 60, GetColor(0, 0, 0), "p1 %d枚　　p2 %d枚　　p3 %d枚　　p4 %d枚",
		chipL[0], chipL[1], chipL[2], chipL[3]);

	for (int i=0;auto& x : cardPlacement)
	{
		DrawFormatString(x.first, x.second, BoxCr, up_pBases[i]->getName().c_str());
		if (/*cL[i].first == 0*/pBase::getbDecisionBs()[i]==0||!r)
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
	DrawRectGraph(231, 14, urax, uray, Tx, Ty, img3, FALSE, FALSE);//決定
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

	//全員同じ数字、つまり全員勝者の場合
	//bitは全て1となり何もしない(早期リターン)
	if (bs.all())return;

	int win = SIC(bs.count());
	int lose = 4 - win;

	for (int i = 0; i < 4; i++)
	{
		if (bs[i])
		{
			pBase::getchipList()[i] += 6 / win;
		}
		else
		{
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