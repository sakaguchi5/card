#include"p.h"

#include<iterator>
array<Hands, 4> pBase::cardList;
array<int, 4> pBase::chipList{ 100, 100, 100, 100 };
bitset<4> pBase::bDecisionBs;

array<Hands, 4> pBase::getcardList()
{
	return pBase::cardList;
}

array<int, 4> pBase::getchipList()
{
	return pBase::chipList;
}

bitset<4> pBase::getbDecisionBs()
{
	return pBase::bDecisionBs;
}

void pBase::bitreset()
{
	bDecisionBs.reset();
}
