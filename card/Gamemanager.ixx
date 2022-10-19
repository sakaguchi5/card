module;
#include "DxLib.h"
#include <vector>
#include <array>
#include<memory>
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

class GameManager
{
public:
    GameManager();
    ~GameManager();
    //Gmgr(Suit s);
    void mainLoop();

private:
    void draw();
    //array<unique_ptr<Base>, 4>up_base;
    array<unique_ptr<pBase>, 4>up_pbase;
   
    
};      
        




}}
