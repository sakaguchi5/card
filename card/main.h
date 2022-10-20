#pragma once
#include <vector>
#include <string>
#include<set>
#include<utility>
#include"array"
#include<numeric>
#include<iostream>
#include<algorithm>
#include <random>
#include<functional>
using namespace std;
//extern mt19937 eng;


//1～13の基本選択arrayをコンパイル時に作成
constexpr array<int, 13> ar()
{
	array<int, 13>ar{};
	iota(ar.begin(), ar.end(), 1);
	return ar;
}

#define SSC(x)	(static_cast<Suit>		(x) )//STATIC_SUIT_CAST
#define SIC(x)	(static_cast<int>	(x) )//STATIC_INT_CAST

constexpr int ante = 3;//アンティの額




enum class Suit
{
	Spade,
	Heart,
	Diamond,
	Club
};
using enum Suit;

 Suit inline operator++(Suit& s)
{
	switch (s)
	{
	case Club:
		return s = Spade;
		break;
	default:
		return s = Suit(underlying_type<Suit>::type(s) + 1);
		break;
	}
}

Suit inline operator--(Suit& s)
{
	switch (s)
	{
	case Spade:
		return s = Club;
		break;
	default:
		return s = Suit(underlying_type<Suit>::type(s) - 1);
		break;
	}
}

struct SuitItr
{
	SuitItr() { setItr(Spade); }
	SuitItr(Suit begin) { setItr(begin); }
	SuitItr(Suit begin, Suit end) { setItr(begin, end); }
	Suit begin;
	Suit end;
	void operator++() { ++begin; ++end; }
	void setItr(Suit begin) { this->begin = begin; this->end = begin; }
	void setItr(Suit begin, Suit end) { this->begin = begin; this->end = end; }
	//void operator--() { --begin; --end; }
	/*
	void s_while(function<void()>f)
	{
		while (begin != end)
		{
			f();
			++begin;
		}
	}*/
	void s_dowhile(function<void()>f)
	{
		do
		{
			//cout << (int)begin ;//<< endl
			f();
			++begin;
		} while (begin != end);
	}
};

struct GameVar
{
public:
	GameVar()
	{
		init();
	}
	bool isopen;	//公開するかどうか
	int card;		//提示するカード
	int chip;		//賭けチップ枚数
	int mychip = 100;		//所持チップ枚数
	string name;//迷いの名前
	void setData(GameVar val)
	{
		card = val.card;
		chip = val.chip;
		mychip = val.mychip;

	}
	void init()
	{
		card = 0;
		chip = 0;
		isopen = false;
		mychip = 100;
		name = "";
	}
	void setdata(bool b) { isopen = b; }
	/*void setdata(int card, int chip, int mychip)
	{
		this->card = card;
		this->chip = chip;
		this->mychip = mychip;
	}*/
};

class pBase
{
public:
	pBase() {}
	pBase(string str, Suit s) {}
	virtual ~pBase() {}
	/**
	 * \brief カードと掛け金を選択する
	 * \
	 * \
	 */
	virtual void choice() = 0;
	/**
	 * \brief 公開するか
	 * \
	 * \
	 */
	virtual void isOpen() = 0;
protected:/*
	string name;//名前
	
	int card;//提示するカード
	
	bool isopen;	//公開するかどうか
	int chip;		//賭けチップ枚数
	int mychip = 100;//所持チップ枚数*/
	GameVar data;
	Suit suit=Suit::Spade;//スート
	vector<int> hand;//手札

private:


};

class Player :public pBase
{
public:
	using pBase::pBase;

private:
	void choice();
	void isOpen();
public:

private:
	Suit order;//今何番目か

};
class Cpu :public pBase
{
public:
	using pBase::pBase;

private:
	void choice();
	void isOpen();
public:
private:

};

struct FieldTime
{
	Suit fieldSuit = Suit::Spade;//Spade-Club
	int fieldOrder = 1;//1-13
};

class GameManager
{
public:
	GameManager();
	//~GameManager();
	GameManager(Suit s);
	void mainLoop();

private:
	void draw();
	array<unique_ptr<pBase>, 4>up_pBases;
	//array<unique_ptr<GameVar>, 4>datas;
};

