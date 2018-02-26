//########################################################
//This is definition of base class game
//########################################################

#include <iostream>
using namespace std;
#include "Game.h"

	Game::Game(int x,int y)
	{
		x=0;
		y=0;
		score=0;
	}
	Game::Game()
	{}
	 void Game :: display() const
	{

	}
	Game::~Game() 
	{
	}
	int Game::getscore() const
	{
		return score;
	}
