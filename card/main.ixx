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
	string name;//���O
	vector<int> hand;//��D
	int card;//�񎦂���J�[�h
	Suit suit;//�X�[�g
	bool isopen;	//���J���邩�ǂ���
	int chip;		//�q���`�b�v����
	int mychip = 100;//�����`�b�v����

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
	virtual bool isOpen(bool b) = 0;
private:

	
};

class Player :public pBase
{
public:
	using pBase::pBase;

private:
	Suit order;//�����Ԗڂ�
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
// �v���C�x�[�g���W���[���t���O�����g
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