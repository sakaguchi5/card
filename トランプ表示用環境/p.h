#pragma once
#include "DxLib.h"
#include<vector>
#include <random>
#include <algorithm>
#include<array>
#include"bitset"
//#include <algorithm>


//多次元の std::array を楽に扱う
template<typename T, std::size_t N, std::size_t... Extents>
struct extents_expander
	: extents_expander<std::array<T, N>, Extents...>
{};  // struct extents_expander

template<typename T, std::size_t N>
struct extents_expander<T, N>
{
	using type = std::array<T, N>;
};  // struct extents_expander

template<typename T, std::size_t... Extents>
struct ndarray_helper
{
	using type = typename extents_expander<T, Extents...>::type;
};  // struct ndarray_helper

template<typename T, std::size_t N, std::size_t... Extents>
struct ndarray_helper<T[N], Extents...>
{
	using type = typename ndarray_helper<T, N, Extents...>::type;
};  // struct ndarray_helper

template<typename T>
using NdArray = typename ndarray_helper<T>::type;

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
using Hands = pair<int, Suit >;

//各スマートポイントのエイリアステンプレート
template <class T>
using u_p = std::unique_ptr<T>;
template <class T>
using s_p = std::shared_ptr<T>;
template <class T>
using w_p = std::weak_ptr<T>;

using enum Suit;



inline Suit operator++(Suit& s)
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

inline Suit operator--(Suit& s)
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

struct FieldTime
{
	FieldTime() { Init(); }
	Suit fieldSuit;//Spade-Club
	int fieldOrder;//1-13
	Suit currentSuit;//Spade-Club

	void Init()
	{
		fieldSuit = Spade;//Spade-Club
		fieldOrder = 1;//1-13
		currentSuit = Spade;//Spade-Club
	}
	//FieldTime ft
	void operator++()
	{
		++this->currentSuit;
		if (this->currentSuit == Spade)
		{
			++this->fieldOrder;
			if (this->fieldOrder == 14)
			{
				++this->fieldSuit;
				this->fieldOrder = 1;
			}
			//sa++;
		}
		//return *this;
	}
	void operator--()
	{
		--this->currentSuit;
		if (this->currentSuit == Club)
		{
			--this->fieldOrder;
			if (this->fieldOrder == 0)
			{
				--this->fieldSuit;
				this->fieldOrder = 13;
			}
			//sa++;
		}
		//return *this;
	}
};

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
	virtual ~pBase() { }
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

	static FieldTime& getfieldTime();
	static array<Hands, 4> &getcardList();
	static array<int, 4>& getchipList();
	static bitset<4>getbDecisionBs();
	static void bitreset();//全bitを0にする

protected:

private:

public:
protected:

	string name;//名前
	Suit suit = Suit::Spade;//スート
	vector<int> hand;//手札
	//int choiceCard;
	int Card = 0;//選択したカード

	static FieldTime fieldTime;

	static array<Hands, 4>cardList;
	static array<int, 4>chipList;

	//static array<int, 4>chipList;
	static bitset<4>bDecisionBs;//決断したかどうかのbitset
	
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
	//vector<int>v{ 2,3,4,5,6,7,8,9,10,11,12,13,1 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12 };
	//int img;
	int img3;

	int back;
	// 黒の値を取得
	int BoxCr = GetColor(0, 0, 0);
	vector<Pair>hitvx;

	int MouseX = 0;
	int MouseY = 0;
	
	//Pair itr = hitvx.begin();
	//AllData data;//全データ
	//FieldTime ft;
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
	void CardShuffle();
public:
private:
	vector<int>v;
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12 };
	random_device seed_gen;
	std::mt19937 engine;
	//AllData data;//全データ
};

//using ar1 = NdArray<int[4]>;
using ar3 = NdArray<int[4][13][4]>;

class Cardlog
{
public:
	Cardlog();
	~Cardlog();
	void AddCardlog();
	ar3 getCardlog() { return cardlog; }
private:
	ar3 cardlog;
};



class GameManager
{
public:
	GameManager();
	~GameManager() { DeleteGraph(background); DeleteGraph(img); DeleteGraph(img2);}
	GameManager(Suit s);
	void mainLoop();

private:
	void Draw();
	void drawstr();

	void Judge();
	void Result(array<vector<Suit>, 2> result);
	void AddCardlog();
public:
private:
	u_p<Cardlog>Clog;
	array<unique_ptr<pBase>, 4>up_pBases;
	array<Pair, 4>cardPlacement;
	//array<unique_ptr<GameVar>, 4>datas;
	int background;//背景
	int img;
	int img2;
	vector<array<int, 4>>cardlog;
	//FieldTime fieldTime;

};



