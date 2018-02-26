//##################################################################################################
//This is header of derived class pacman that inherits derived class two dimensional game publically
//##################################################################################################
#ifndef PACMAN_H
#define PACMAN_H
#include<iostream>
#include "TwoDimensionalGame.h"
#include "map.h"
#include "KEYSTROKE.h"
#include<ctime>
using namespace std;





class pacman:public TwoDimensionalGame
{
public:
	pacman(int mx,int my);
	
	void startGame ();
	void movpacman();
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();
	void display() const;
	int getscore() const;
	void gotoxy(int x,int y);
	void detail() ;
	~pacman();
	private:
		
	 int x,y,score,life,key,level;
	 time_t leftTime;
	 int i;//for sleep
	 
	 
	//char **game ;
	 map gaming;
	 KEYSTROKE key1;
};



#endif