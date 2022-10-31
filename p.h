#pragma once
#include "DxLib.h"
#include<vector>
#include <random>
#include <algorithm>
#include<array>
//#include <algorithm>
/*
Tx=128;
Ty=192;
Tp=8;*/


constexpr int Tx = 128;
constexpr int Ty = 192;
constexpr int Tp = 8;
constexpr int xx = Tx + Tp;//136
constexpr int yy = Ty + Tp;//200
constexpr int urax = 1768;
constexpr int uray = 200;
//1768,200

using namespace std;
using Pair = pair<int, int>;
using AllData = shared_ptr<array<array<int, 4>, 13>>;

enum class Suit
{
	Spade,
	Heart,
	Diamond,
	Club
};
#define SSC(x)	(static_cast<Suit>	(x) )//STATIC_SUIT_CAST
#define SIC(x)	(static_cast<int>	(x) )//STATIC_INT_CAST
using enum Suit;

inline bool operator < (Pair p1, Pair p2) {
	return p1.first < p2.first&& p1.second < p2.second;
}
inline Pair operator - (Pair p1, Pair p2) {
	Pair result;
	result.first = p1.first - p2.first;
	result.second = p1.second - p2.second;
	return result;
}
class pBase
{
public:
	pBase() {}
	pBase(string str, Suit s) { name = str; suit = s; }
	virtual ~pBase() {}
   /**
	* \brief カードを選択する
	* \
	* \
	*/
	virtual void choice() = 0;
   /**
	* \brief 公開するか
	* \
	* \
	*/

	/**
	 * \brief 
	 * \
	 * \
	 */
	virtual void Action() = 0;
	/**
	 * \brief 
	 * \
	 * \
	 */
	virtual void Draw() = 0;
	 //virtual void isOpen() = 0;

	Suit getSuit() { return suit; }
	string getName() { return name; }

protected:

private:

public:
protected:

	string name;//名前
	Suit suit = Suit::Spade;//スート
	vector<int> hand;//手札
	//int choiceCard;
	int Card = 0;//選択したカード
private:

};
class Player :public pBase
{
public:
	Player(string str, Suit s);
	~Player();
	void Action();
	void Draw();
private:
	void choice();
	void drawfor();
	
	void mousecrick();
	void reHitbox();
	void choiceCard(int card);
public:
private:
	vector<int>v{ 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12 };
	//int img;
	//int img2;
	int img3;

	int back;
	// 黒の値を取得
	int BoxCr = GetColor(0, 0, 0);
	vector<Pair>hitvx;

	int MouseX = 0;
	int MouseY = 0;
	
	//Pair itr = hitvx.begin();
	//AllData data;//全データ
};

class Cpu :public pBase
{
public:
	Cpu(string str, Suit s);
	~Cpu();
	void Action();
	void Draw();
private:
	void choice();
public:
private:
	vector<int>v;
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12 };
	random_device seed_gen;
	std::mt19937 engine;
	//AllData data;//全データ
};

class GameManager
{
public:
	GameManager();
	~GameManager() { DeleteGraph(background); DeleteGraph(img);}
	GameManager(Suit s);
	void mainLoop();

private:
	void Draw();
	void drawstr();
public:
private:
	array<unique_ptr<pBase>, 4>up_pBases;
	array<Pair, 4>cardPlacement;
	//array<unique_ptr<GameVar>, 4>datas;
	int background;//背景
	int img;
};



