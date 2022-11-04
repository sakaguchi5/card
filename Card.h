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
	vector<int> hand;//手札一覧
	//int choiceCard;
	int choiceCard = 0;//選択したカード

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



