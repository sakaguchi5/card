module;
#include "DxLib.h"
#include <vector>
#include <array>

export module mylib;
export import :main;
// �N���XS�̐錾���Q�Ƃ��邽�߂ɃC���|�[�g����
 

namespace mylib {
using namespace std;
//using namespace mylib;

export {

struct FieldTime
{
    Suit fieldSuit = Suit::Spade;//Spade-Club
    int fieldOrder=1;//1-13
};    

class Gmgr
{
public:
    Gmgr();
    //Gmgr(Suit s);
    void f(){}
    ~Gmgr();
    void mainloop();

private:
    //array<pBase, 4> ar;	//pBase�̔z��
    vector<pBase>ar;
    
};      
        




}}

//---------------------------------------------------
module :private;
using namespace mylib;
// �v���C�x�[�g���W���[���t���O�����g
Gmgr::Gmgr()
{
}

Gmgr::~Gmgr()
{
}

void Gmgr::mainloop()
{
    for (auto& x : ar)
    {
        x.choice();
    }
}


