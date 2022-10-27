#include"p.h"
#include <numeric>

Cpu::Cpu(string str, Suit s): pBase(str,s), engine(seed_gen()), v(13)
{
	iota(v.begin(), v.end(), 1); // 1`13 ‚Ü‚Å‚Ì’l‚ğ¶¬
	std::shuffle(v.begin(), v.end(), engine);
}

Cpu::~Cpu()
{
}

void Cpu::Action()
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
