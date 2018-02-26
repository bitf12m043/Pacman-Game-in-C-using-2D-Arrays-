//########################################################
//This class is used for user input
//########################################################

#ifndef KEYSTROKE_H
# define KEYSTROKE_H
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
class KEYSTROKE
{
	int key;
	friend class pacman;
public:
	void setinput();
	int getkey() const ;
	
};
#endif