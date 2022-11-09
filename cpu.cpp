#include"p.h"
#include <numeric>
#include <string>
//array<int, 4> pBase::cardList;
Cpu::Cpu(string str, Suit s): pBase(str,s), engine(seed_gen()), v(13)
{
	iota(v.begin(), v.end(), 1); // 1Å`13 Ç‹Ç≈ÇÃílÇê∂ê¨
	CardShuffle();
	name = "cpu";
	name += std::to_string(SIC(s));
}

Cpu::~Cpu()
{
}

void Cpu::Action(FieldTime& fieldTime)
{
	if (fieldTime.currentSuit == suit)
	{
								//v[fieldTime.fieldOrder-1]
		cardList[SIC(suit)] = v[fieldTime.fieldOrder - 1];
		++fieldTime;
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
