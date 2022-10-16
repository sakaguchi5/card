module;
#include"main.h"
#include <vector>
#include <string>
#include<set>
#include<utility>
#include<array>
#include<numeric>
#include<iostream>
#include<algorithm>
#include <random>
#include<functional>
export module mylib:main;

namespace mylib {
using namespace std; 
export {
	
enum class Suit
{
	Spade,
	Heart,
	Diamond,
	Club
};
using enum Suit;
Suit operator++(Suit& s)
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

Suit operator--(Suit& s)
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
	SuitItr(Suit begin, Suit end) { setItr(begin,end); }
	Suit begin;
	Suit end;
	void operator++() { ++begin; ++end; }
	void setItr(Suit begin) { this->begin = begin; this->end = begin;}
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

class pBase
{
public:
	pBase(){}
	pBase(string str,Suit s){}
	virtual ~pBase(){}
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
protected:
	string name;//名前
	vector<int> hand;//手札
	int card;//提示するカード
	Suit suit;//スート
	bool isopen;	//公開するかどうか
	int chip;		//賭けチップ枚数
	int mychip = 100;//所持チップ枚数

	void makehand();
private:
	
	
};

class Player :public pBase
{
public:
	using pBase::pBase;

private:
	void choice();
	void isOpen();
	Suit order;//今何番目か
};
class Cpu :public pBase
{
public:
	using pBase::pBase;
private:


};





}



}


//---------------------------------------------------
module :private;
using namespace mylib;
// プライベートモジュールフラグメント
pBase::pBase()
{
	name = "none";
	suit = Suit::Spade;
}
pBase::pBase(string str, Suit s):name(str),suit(s)
{
}

pBase::~pBase()
{
}

void pBase::makehand()
{
	for (int i = 0; i < 13; i++)
	{
		hand[i] = i + 1;
	}
}

void Player::choice()
{

}

void Player::isOpen()
{
}
