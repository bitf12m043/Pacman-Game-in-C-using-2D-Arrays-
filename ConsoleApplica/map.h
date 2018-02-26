//########################################################
//This is class for setting a stage
//########################################################

#ifndef map_h
#define map_h
#include <iostream>

using namespace std;
class map
{
	char **game;
	char hurdle,star,food,face,space;
	int x,y,current_X,current_y,startX,startY,fooditem,scr_x,scr_y,start_x,start_y;
	void allocatememory();
	
	friend class pacman;
public:
	map();
	


	void stage1();
	void stage2();

	~map();
	

};
#endif
