#pragma once
#include<vector>
using namespace std;
class Card
{
public:
	Card();

private:

public:
private:
	vector<int> hand;//��D�ꗗ
	//int choiceCard;
	int choiceCard = 0;//�I�������J�[�h

};

class PlayerCard:public Card
{
public:
	PlayerCard()
	{
	}

	~PlayerCard()
	{
	}

private:

public:
private:
};

class CpuCard :public Card
{
public:
	CpuCard()
	{
	}

	~CpuCard()
	{
	}

private:

public:
private:
};



