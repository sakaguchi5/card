#include"p.h"
Cardlog::Cardlog():cardlog()
{
}
Cardlog::~Cardlog()
{
}
void Cardlog::AddCardlog()
{
	auto ft = pBase::getfieldTime();

	auto v= pBase::getcardList();
	for (int i = 0; i < 4; i++)
	{
		cardlog[SIC(ft.fieldSuit)][ft.fieldOrder-1][i] = v[i].first;
	}

}