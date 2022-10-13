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

Suit operator++(Suit& s)
{
	switch (s)
	{
	case Suit::Club:
		return s = Suit::Spade;
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
	case Suit::Spade:
		return s = Suit::Club;
		break;
	default:
		return s = Suit(underlying_type<Suit>::type(s) - 1);
		break;
	}
}

struct SuitItr
{
	SuitItr() { begin = Suit::Spade; end = begin; }
	SuitItr(Suit begin) :begin(begin), end(begin) {}
	SuitItr(Suit begin, Suit end) :begin(begin), end(end) {}
	Suit begin;
	Suit end;
	void operator++() { ++begin; ++end; }
	//void operator--() { --begin; --end; }
	void s_while(function<void(Suit dammy)>f)
	{
		while (begin != end)
		{
			f(begin);
			++begin;
		}
	}
	void s_dowhile(function<void(Suit dammy)>f)
	{
		do
		{
			//cout << (int)begin ;//<< endl
			f(begin);
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
protected:
	string name;//名前
	vector<int> hand;//手札
	int card;//提示するカード
	Suit suit;//スート
	bool isopen;	//公開するかどうか
	int chip;		//賭けチップ枚数
	int mychip = 100;//所持チップ枚数

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
	virtual bool isOpen(bool b) = 0;
private:

	
};

class Player :public pBase
{
public:
	using pBase::pBase;

private:
	Suit order;//今何番目か
};
class Cpu :public pBase
{
public:
	using pBase::pBase;
private:


};





}}

/*
//---------------------------------------------------
module :private;
// プライベートモジュールフラグメント
mylib::pBase::pBase()
{
	name = "none";
	suit = Suit::Spade;
}
mylib::pBase::pBase(string str, Suit s):name(str),suit(s)
{
}

mylib::pBase::~pBase()
{
}*/