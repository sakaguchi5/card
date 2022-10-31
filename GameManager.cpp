#include"p.h"
using GM = GameManager;
GameManager::GameManager()
{
	background = LoadGraph("”wŒi2.png");
}

GameManager::GameManager(Suit s)
{
	background = LoadGraph("”wŒi2.png");
	//static short int i = 0;
	/*
	if (e == s)//s‚ÍƒvƒŒƒCƒ„[‚ÌƒX[ƒg
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
		i->Action();
		i->Draw();
	}
	
}
void GameManager::Draw()
{
	//”wŒi•\¦
	DrawGraphF(0, 0, background, TRUE);
}