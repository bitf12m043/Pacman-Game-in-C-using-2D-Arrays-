//#################################################################################
//This is a header of two dimensional game which inherit base class game publically
//#################################################################################
#ifndef TwoDimensionalGame_H
#define TwoDimensionalGame_H
#include <iostream>
#include "Game.h"
using namespace std;
class TwoDimensionalGame:public Game
{
public:
	TwoDimensionalGame(int x,int y);
	TwoDimensionalGame();
	~TwoDimensionalGame();
	virtual void display() const=0;
};
#endif