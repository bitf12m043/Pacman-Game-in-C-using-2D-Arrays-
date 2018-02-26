//########################################################
//This is implementation of class keystroke
//########################################################

#include <iostream>
using namespace std;
#include"KEYSTROKE.h"
//########################################################
//Input method for taking input from user
//########################################################
void KEYSTROKE::setinput()
	{
	
	if(_kbhit())
	{
		
		if(GetAsyncKeyState(VK_UP))
		{
			key=1;
			
			
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			key=2;
			
		}
		else if(GetAsyncKeyState(VK_LEFT))
		{
			key=3;
			
		}
		else if(GetAsyncKeyState(VK_RIGHT))
		{
			key=4;
			
		}
		
	}
}

//########################################################
//Getter method for getting input of user
//########################################################
	int KEYSTROKE::getkey() const
	{
		return key;
	}