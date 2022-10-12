#pragma once
#include "DxLib.h"
#include <list>
#include <memory>


//各スマートポイントのエイリアステンプレート
template <class T>
using u_p = std::unique_ptr<T>;
template <class T>
using s_p = std::shared_ptr<T>;
template <class T>
using w_p = std::weak_ptr<T>;

using namespace std;

//画面の大きさ
constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;

//移動スカラー
constexpr float movescalar = 4.f;

//画像の縦幅
constexpr int heightsize = 64;
//画像の横幅
constexpr int widthsize = 64;

//IPDATAのラッパークラス
struct MyIP:public IPDATA
{
	MyIP()
	{
		initip();
	}
	MyIP(unsigned char d1, unsigned char d2, unsigned char d3, unsigned char d4)
	{
		setip(d1, d2, d3, d4);
	}
	void initip()
	{
		this->d1 = 0;
		this->d2 = 0;
		this->d3 = 0;
		this->d4 = 0;		
	}
	IPDATA setip(unsigned char d1, unsigned char d2, unsigned char d3, unsigned char d4)
	{
		this->d1 = d1;
		this->d2 = d2;
		this->d3 = d3;
		this->d4 = d4;
	};
	//IPDATA getIP(){}
};