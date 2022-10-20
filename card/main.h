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


//1�`13�̊�{�I��array���R���p�C�����ɍ쐬
constexpr array<int, 13> ar()
{
	array<int, 13>ar{};
	iota(ar.begin(), ar.end(), 1);
	return ar;
}

#define SSC(x)	(static_cast<Suit>		(x) )//STATIC_SUIT_CAST
#define SIC(x)	(static_cast<int>	(x) )//STATIC_INT_CAST

constexpr int ante = 3;//�A���e�B�̊z




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
	bool isopen;	//���J���邩�ǂ���
	int card;		//�񎦂���J�[�h
	int chip;		//�q���`�b�v����
	int mychip = 100;		//�����`�b�v����
	string name;//�����̖��O
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
	 * \brief �J�[�h�Ɗ|������I������
	 * \
	 * \
	 */
	virtual void choice() = 0;
	/**
	 * \brief ���J���邩
	 * \
	 * \
	 */
	virtual void isOpen() = 0;
protected:/*
	string name;//���O
	
	int card;//�񎦂���J�[�h
	
	bool isopen;	//���J���邩�ǂ���
	int chip;		//�q���`�b�v����
	int mychip = 100;//�����`�b�v����*/
	GameVar data;
	Suit suit=Suit::Spade;//�X�[�g
	vector<int> hand;//��D

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
	Suit order;//�����Ԗڂ�

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

