//#include"Gamemanager.h"
#include"main.h"
using GM = GameManager;
GameManager::GameManager()
{

}

GameManager::GameManager(Suit s)
{
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
		if (i==SIC(s))
		{
			up_pBases[SIC(s)]= make_unique<Player>("", SSC(i));
		}
		else
		{
			up_pBases[SIC(s)] = make_unique<Cpu>("", SSC(i));
		}
	}

}

void GameManager::mainLoop()
{

}
void GameManager::draw()
{

}