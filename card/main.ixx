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
protected:
	string name;//���O
	vector<int> hand;//��D
	int card;//�񎦂���J�[�h
	Suit suit;//�X�[�g
	bool isopen;	//���J���邩�ǂ���
	int chip;		//�q���`�b�v����
	int mychip = 100;//�����`�b�v����

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
	Suit order;//�����Ԗڂ�
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
// �v���C�x�[�g���W���[���t���O�����g
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
