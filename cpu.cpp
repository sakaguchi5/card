#include"p.h"
#include <numeric>
#include <string>
Cpu::Cpu(string str, Suit s): pBase(str,s), engine(seed_gen()), v(13)
{
	iota(v.begin(), v.end(), 1); // 1Å`13 Ç‹Ç≈ÇÃílÇê∂ê¨
	std::shuffle(v.begin(), v.end(), engine);
	name = "cpu";
	name += std::to_string(SIC(s));
}

Cpu::~Cpu()
{
}

void Cpu::Action(FieldTime fieldTime)
{
	//choice();
}

void Cpu::Draw()
{
}

void Cpu::choice()
{
	int n = v.back();
	v.pop_back();
	//return n;
}
