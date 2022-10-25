#pragma once
#include "DxLib.h"
#include<vector>
//#include <algorithm>
/*
Tx=128;
Ty=192;
Tp=8;*/

constexpr int Tx = 128;
constexpr int Ty = 192;
constexpr int Tp = 8;
constexpr int xx = Tx + Tp;//136
constexpr int yy = Ty + Tp;//200
constexpr int urax = 1768;
constexpr int uray = 200;
//1768,200

using namespace std;
using Pair = pair<int, int>;

inline bool operator < (Pair p1, Pair p2) {
	return p1.first < p2.first&& p1.second < p2.second;
}
inline Pair operator - (Pair p1, Pair p2) {
	Pair result;
	result.first = p1.first - p2.first;
	result.second = p1.second - p2.second;
	return result;
}

class Player
{
public:
	Player();
	~Player();
	void Draw();
	vector<int>v{ 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12,13 };
	//vector<int>v{ 1,2,3,4,6,7,8,9,11,12 };
	//int img;
	//int img2;
	int img3;

	int back;
	// •‚Ì’l‚ğæ“¾
	int BoxCr = GetColor(0, 0, 0);
private:
	void drawfor();
	void drawstr();

	void mousecrick();
	void reHitbox();
	//vector<Point>hitvx;
	//typedef std::pair<int, int> pair;
	vector<Pair>hitvx;

	int MouseX = 0;
	int MouseY = 0;
};

