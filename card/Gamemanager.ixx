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


class Gmgr
{
public:
    Gmgr();
    //Gmgr(Suit s);
    void f(){}
    ~Gmgr();

private:
    //array<pBase, 4> ar;	//pBase�̔z��
    //vector<pBase>ar;
    void mainloop(){};
};      
        




}}



