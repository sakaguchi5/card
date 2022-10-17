module;
#include "DxLib.h"
#include <vector>
#include <array>

export module mylib;
export import :main;
// クラスSの宣言を参照するためにインポートする
 

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
    //array<pBase, 4> ar;	//pBaseの配列
    vector<pBase>ar;
    
};      
        




}}

module :private;

mylib::Gmgr::Gmgr()
{
}

mylib::Gmgr::~Gmgr()
{
}

void mylib::Gmgr::mainloop()
{
    for (auto &x : ar)
    {
        
    }
}


