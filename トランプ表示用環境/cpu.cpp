#include"p.h"
#include <numeric>
#include <string>
//array<int, 4> pBase::cardList;
Cpu::Cpu(string str, Suit s): pBase(str,s), engine(seed_gen()), v(13)
{
	iota(v.begin(), v.end(), 1); // 1〜13 までの値を生成
	CardShuffle();
	name = "cpu";
	name += std::to_string(SIC(s));
}

Cpu::~Cpu()
{
}

void Cpu::Action()
{
	if (fieldTime.currentSuit == suit&& bDecisionBs[SIC(suit)]==0)
	{
								//v[fieldTime.fieldOrder-1]
		cardList[SIC(suit)].first = v[fieldTime.fieldOrder - 1];
		//++fieldTime;
		bDecisionBs.set(SIC(suit));//suit番目のbitを立てる			
	}

	//choice();
}

void Cpu::Draw()
{
}

void Cpu::choice()
{
	
	//return n;
}

void Cpu::CardShuffle()
{
	std::shuffle(v.begin(), v.end(), engine);
}
