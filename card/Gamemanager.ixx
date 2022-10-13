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


class Gmgr
{
public:
    Gmgr();
    //Gmgr(Suit s);
    void f(){}
    ~Gmgr();

private:
    //array<pBase, 4> ar;	//pBaseの配列
    //vector<pBase>ar;
    void mainloop(){};
};      
        




}}



