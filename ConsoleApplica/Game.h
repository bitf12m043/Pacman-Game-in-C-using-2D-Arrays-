//########################################################
//This is a header of base class game
//########################################################
#ifndef Game_H
#define Game_H
#include <iostream>
using namespace std;
class Game
{
	int score;
public:
	
	Game(int x, int y);
	Game();
	~Game();
	virtual int getscore() const=0 ;
	virtual void display() const=0;
	virtual void startGame() =0;
};
#endif