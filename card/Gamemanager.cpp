/*
import mylib; // Gamemanagerモジュールを取り込む
//import main;
using namespace mylib;
Gmgr::Gmgr()
{
}

mylib::Gmgr::Gmgr(Suit s)
{
}

mylib::Gmgr::~Gmgr()
{
}

void mylib::Gmgr::mainloop()
{
}*/
import mylib;
#include"string"

using namespace std;
using namespace mylib;
//using Gmgr = GameManager;
/**/
// プライベートモジュールフラグメント
pBase::pBase()
{
    name = "none";
    suit = Suit::Spade;
}
pBase::pBase(string str, Suit s) :name(str), suit(s)
{
}

pBase::~pBase()
{
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}



void GameManager::mainLoop()
{
    
    for (auto& x : up_pbase)
    {

    }
}

void GameManager::draw()
{
}
