#include <crtdbg.h>
#include"main.h"
//#include"Gamemanager.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
using  GM = GameManager;

void Print(array<shared_ptr<GameVar>,4>&ar)
{
	//thread thd{ task ,ref(c.num) };
	ar[3]->isopen;

}
int main()
{
	//cout << "hello" << std::endl;


	bool b = true;
	if (b == true)
	{
		auto a = make_unique<GM>(Suit::Diamond);//‚±‚±‚Ì‘æ“ñˆø”‚ğ•Ï‚¦‚é‚ÆƒvƒŒƒCƒ„[‚Ì‡”Ô‚ª•Ï‚í‚é

		

	}

	while (true)
	{

	}

	_CrtDumpMemoryLeaks();

}