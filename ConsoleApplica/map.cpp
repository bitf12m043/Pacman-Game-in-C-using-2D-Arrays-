#include <iostream>
using namespace std;
#include "map.h"

//########################################################
//Dynamically allocate memory function
//########################################################
void map:: allocatememory()
	{
		game=new char*[y];
		for (int i = 0; i < y; i++)
		{
			game[i]=new char [x];
		}
		
	}

//########################################################
// constructor
//########################################################
map::map()
	{
		x=20;
		y=20;
		face=2;
		space=0;
		hurdle=219;
		food=46;
		fooditem=0;
		star=4;
		allocatememory();
		

	}

//########################################################
//Stage 1 of pacman
//########################################################
	void map:: stage1()
	{
		
		//Draw a boundry
		for(int i=0;i<x;i++)
		 {
			game[0][i]=hurdle;
		 }
 for (int i = 1; i < y; i++)
 {
	 game[i][0]=hurdle;
	 game[i][x-1]=hurdle;
 }
 for (int i = 0; i <x; i++)
 {
	 game[y-1][i]=hurdle;
 }
 //Draw iternal map 
 for (int i = 3 ; i <= 8; i++)
 {
	 game[i][2]=star;
	  game[i][17]=star;

 }
 for (int i = 11 ; i <= 16; i++)
 {
	 game[i][2]=star;
	  game[i][17]=star;

 }
 for (int i = 3 ; i <= 7; i++)
 {
	 game[3][i]=star;
	  game[16][i]=star;

 }

 for (int i = 12 ; i <= 17; i++)
 {
	 game[3][i]=star;
	  game[16][i]=star;

 }

 for (int i = 5 ; i <= 8; i++)
 {
	 game[i][4]=star;
	  game[i][15]=star;

 }
 for (int i = 11 ; i <= 14; i++)
 {
	 game[i][4]=star;
	  game[i][15]=star;

 }
 for (int i = 5 ; i <= 8; i++)
 {
	 game[5][i]=star;
	 

 }

 for (int i = 11 ; i <= 14; i++)
 {
	 game[14][i]=star;
	 

 }

 for (int i = 7 ; i <= 12; i++)
 {
	 game[7][i]=star;
	 game[9][i]=star;
	  game[10][i]=star;
	 game[12][i]=star;
 }

 game[10][12]=star;
 game[8][7]=star;
  game[9][7]=star;
  

    game[11][12]=star;
	 game[12][12]=star;
	  game[12][7]=star;
 //Insert food items
 for (int i = 0; i < x; i++)
 {
	 for (int j = 0; j < y; j++)
	 {
		 if(game[i][j]!=hurdle && game[i][j]!=star)
		 {
			 
			 game[i][j]=food;
			 fooditem++;
		 }
	 }
	 
 }
 fooditem--;
 //starting point of pacman in array
 current_X=1;
 current_y=18;
 //startting point of pacman on screen
 scr_x=21;
 scr_y=	20;
 //if die start from here on screen
 start_x=21;
 start_y=20;
 //if pacman die it start again from this point
  startX=1;
 startY=18;
 //face of pacman
 game[current_y][current_X]=face;
	}

//########################################################
//Stage 2 of pacman
//########################################################

	void map::stage2()
	{
		fooditem=0;
		//clear stage 1
		for(int k=0;k<19;k++)
		{
			for(int m=0;m<19;m++)
				game[k][m]=space;
		}
		
		//Draw a boundry
		for(int i=0;i<x;i++)
		 {
			game[0][i]=hurdle;
		 }
 for (int i = 1; i < y; i++)
 {
	 game[i][0]=hurdle;
	 game[i][x-1]=hurdle;
 }
 for (int i = 0; i <x; i++)
 {
	 game[y-1][i]=hurdle;
 }
 //Draw iternal map 
 for (int i = 4; i <=15; i++)
 {
	 game[i][4]=star;
	 game[i][15]=star;
 }


 for (int i = 6; i <= 13; i++)
 {
	 game[5][i]=star;
	 game[14][i]=star;
 }

 for (int i = 7; i <= 12; i++)
 {
	 game[i][7]=star;
	 game[i][12]=star;
 }

 for (int i = 2; i <= 6; i++)
 {
	 game[2][i]=star;
	 game[17][i]=star;
 }

 for (int i = 14; i <= 17; i++)
 {
	 game[2][i]=star;
	 game[17][i]=star;
 }
 game[3][2]=star;
 game[4][2]=star;
 game[15][2]=star;
 game[16][2]=star;

  game[3][17]=star;
 game[4][17]=star;
 game[15][17]=star;
 game[16][17]=star;
 //################
 game[8][9]=star;
 game[8][10]=star;
 game[11][9]=star;
 game[11][10]=star;
 //Insert food items
 for (int i = 0; i < x; i++)
 {
	 for (int j = 0; j < y; j++)
	 {
		 if(game[i][j]!=hurdle && game[i][j]!=star)
		 {
			 
			 game[i][j]=food;
			 fooditem++;
		 }
	 }
	 
 }
 fooditem--;
 //for screen coordinates
 scr_x=21;
 scr_y=	20;
 //if die start from this screen coordinates
 start_x=21;
 start_y=20;
 //for array coordinates;
 current_X=1;
 current_y=18;
 //if pacman die it start again from this point
  startX=1;
 startY=18;
 //face of pacman
 game[current_y][current_X]=face;
	}

//########################################################
//Destructor for deallocating memory
//########################################################

	map::~map()
	{
		{
		for (int i = 0; i <y; i++)
	 {
		 delete game[i];

	 }
	 delete [] game;
	}
	}