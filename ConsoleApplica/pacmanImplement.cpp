#include <iostream>
#include <fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include  "PACMAN.h"
#include "Game.h"
#include <ctime>
#include "TwoDimensionalGame.h"
#pragma comment(lib, "winmm.lib")

//########################################################
//GOTOXY  function
//########################################################
void pacman:: gotoxy(int x,int y)
{
	
	COORD co;
	co.X=x;
	co.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}

using namespace std;

//########################################################
//Parameterized constructor
//########################################################
	pacman::pacman(int mx,int my)
	{
		key=0;
		life=3;
		i=250;
		level=1;
		leftTime=0;
		x=mx;
		y=my;
		score=0;
	}
//########################################################
//Start game
//########################################################
	
	void pacman::startGame()
	{
		 PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_FILENAME | SND_ASYNC);
		gaming.stage1();
		display();
		movpacman();
		level-=1;
		if(gaming.fooditem<=0 )
		{
			 PlaySound(TEXT("pacman_beginning.wav"), NULL, SND_FILENAME | SND_ASYNC);
			leftTime=0;
			life=3;
			key1.key=0;
			gaming.stage2();
			display();
			movpacman();
		}
	}
//########################################################
//move pacman function
//########################################################
	void pacman::movpacman()
 {
	time_t startTime=0;
	time_t endTime=0;
	startTime=time(NULL);
	 while(gaming.fooditem>0 && life>0 && leftTime<=200  )
	 {
		 
			 Sleep(250);
			
		 
		 if(_kbhit())
		 {
			key1.setinput();
			key=key1.getkey();
		 }
		 
		 	 //move up
		 if (key==1  )
		  {moveUp();}
		 else if (key==2  )
		   {moveDown();} 
		else if(key==4  )
	     {moveRight();}
		 else if (key==3)
          {moveLeft();}
	  
			endTime=time(NULL);
			leftTime=endTime-startTime;
			detail();
			 
	}
	
	 
	 
	  if(gaming.fooditem==0)
	 {
		system("cls");
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		 
		 cout<<"\nLEVEL COMPLETED...\n";
		// level-=1;
		 Sleep(1500);
	 }
	  
	 if(life==0 || leftTime>=180)
	 {
		 system("cls");
		 for (int i = 0; i < 5; i++)
		 {
			 cout<<endl;
		 }
		  PlaySound(TEXT("end.wav"), NULL, SND_FILENAME | SND_ASYNC);
		 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		 cout<<"\t\t                  *          "<<endl;
	cout<<"\t\t(        (      (  `         "<<endl;
	cout<<"\t\t )\\ )     )\\     )\\))(   ( "<<endl;
	cout<<"\t\t(()/(  ((((_)(  ((_)()\\  )\\ "<<endl;
	cout<<"\t\t /(_))_ )\\ _ )\\ (_()((_)((_) "<<endl;
	cout<<"\t\t(_)) __|(_)_\\(_)|  \\/  || __| "<<endl;
	cout<<"\t\t| (_ |   / _ \\  | |\\/| || _|"<<endl;
	cout<<"\t\t \\)__|  /_/ \\_\\ |_| (|_||___| "<<endl<<endl;
	cout<<"\t\t( /(                  )\\ )   "<<endl;
	cout<<"\t\t)\()) (   (   (    (()/(  "<<endl;
	cout<<"\t\t((_)  )\\  )\\    )\\   /(_)) "<<endl;
	cout<<"\t\t ((_)((_)((_)(  (_) (_)) "<<endl;
	cout<<"\t\t / _ \\ \\ \\ / / | __|| _ \\"<<endl;
	cout<<"\t\t| (_) | \\ V /  | _| |   / "<<endl;
	cout<<"\t\t \\___/   \\_/   |___||_|_\\"<<endl<<endl;

	cout<<"\t\t\t Your score is:"<<score<<endl;
		 Sleep(4000);
	 }
	 
	 
	 
	 
 }
	
//########################################################
//move right fuction
//########################################################
	
	void pacman::moveRight()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		if(gaming.game[gaming.current_y][gaming.current_X+1]!=gaming.hurdle && gaming.game[gaming.current_y][gaming.current_X+1]!=gaming.star)
		 {
			 if(gaming.game[gaming.current_y][gaming.current_X+1]==gaming.food)
			 {
				 gaming.fooditem--;
				 score+=5;
				 PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 }
			 
			 char temp=gaming.game[gaming.current_y][gaming.current_X];
			 gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				 gaming.current_X++;
				 gaming.game[gaming.current_y][gaming.current_X]=temp;
				 
				 gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x++;
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
				 
				 Sleep(i);
		  //display();
			 
		}
		else  if( gaming.game[gaming.current_y][gaming.current_X+1]==gaming.star)
			  {
				   PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				  score-=50;

				  gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				  gaming.current_X=gaming.startX;
				  gaming.current_y=gaming.startY;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.face;
				   
				  life--;
				   gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x=gaming.start_x;
				 gaming.scr_y=gaming.start_y;
				
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
				  Sleep(i);
		  //display();
			  }
		 
		
		
	}

//########################################################
//move left fuction
//########################################################
	
	void pacman:: moveLeft()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		if(gaming.game[gaming.current_y][gaming.current_X-1]!=gaming.hurdle && gaming.game[gaming.current_y][gaming.current_X-1]!=gaming.star )
		 {
			 if(gaming.game[gaming.current_y][gaming.current_X-1]==gaming.food)
			 {
				 gaming.fooditem--;
				 score+=5;
				 PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 }
			 
			 char temp=gaming.game[gaming.current_y][gaming.current_X];
			 gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				 gaming.current_X--;
				 gaming.game[gaming.current_y][gaming.current_X]=temp;
				 gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x--;
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
				 Sleep(i);
		 // display();
			 
		}
		else  if( gaming.game[gaming.current_y][gaming.current_X-1]==gaming.star)
			  {
				  PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				  score-=50;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				  gaming.current_X=gaming.startX;
				  gaming.current_y=gaming.startY;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.face;
				    
				  life--;
				  Sleep(i);
				   gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x=gaming.start_x;
				 gaming.scr_y=gaming.start_y;
				
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
		  
				  
			  }
		
	}

//########################################################
//move up fuction
//########################################################
	
	void pacman::moveUp()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		 if(gaming.game[gaming.current_y-1][gaming.current_X]!=gaming.hurdle && gaming.game[gaming.current_y-1][gaming.current_X]!=gaming.star )
		 {
			 if(gaming.game[gaming.current_y-1][gaming.current_X]==gaming.food )
			 {
				 gaming.fooditem--;
				 score+=5;
				 PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 }
			 
			 char temp=gaming.game[gaming.current_y][gaming.current_X];
			 gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
			 gaming.current_y--;
				 gaming.game[gaming.current_y][gaming.current_X]=temp;
				 gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_y--;
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
				Sleep(i);
			    //display();
			 
		}
		else  if( gaming.game[gaming.current_y-1][gaming.current_X]==gaming.star)
			  {
				  PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				  score-=50;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				  gaming.current_X=gaming.startX;
				  gaming.current_y=gaming.startY;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.face;
				    
				   gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x=gaming.start_x;
				 gaming.scr_y=gaming.start_y;
				
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;
				  life--;
				  Sleep(i);
				  //display();
				  
			  }
		
	}

//########################################################
//move down fuction
//########################################################
	
	void pacman::moveDown()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		if(gaming.game[gaming.current_y+1][gaming.current_X]!=gaming.hurdle && gaming.game[gaming.current_y+1][gaming.current_X]!=gaming.star )
		 {
			 if(gaming.game[gaming.current_y+1][gaming.current_X]==gaming.food)
			 {
				 gaming.fooditem--;
				 score+=5;
				 PlaySound(TEXT("pacman_chomp.wav"), NULL, SND_FILENAME | SND_ASYNC);
			 }
			 
			 char temp=gaming.game[gaming.current_y][gaming.current_X];
			 gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
			 gaming.current_y++;
				 gaming.game[gaming.current_y][gaming.current_X]=temp;
			 gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_y++;
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;	
				 Sleep(i);
		  //display();
			 
		}
		else  if( gaming.game[gaming.current_y+1][gaming.current_X]==gaming.star)
			  {
				   PlaySound(TEXT("pacman_death.wav"), NULL, SND_FILENAME | SND_ASYNC);
				  score-=50;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.space;
				  gaming.current_X=gaming.startX;
				  gaming.current_y=gaming.startY;
				  gaming.game[gaming.current_y][gaming.current_X]=gaming.face;

				  gotoxy(gaming.scr_x,gaming.scr_y);
				 cout<<gaming.space;
				 gaming.scr_x=gaming.start_x;
				 gaming.scr_y=gaming.start_y;
				
				  gotoxy(gaming.scr_x,gaming.scr_y);
				  cout<<gaming.face;	  
				  life--;
				  Sleep(i);
		    //display();
				  
			  }
		
	}

//########################################################
//Display method 
//########################################################

void pacman::display() const
	{ 
		 system("cls");
	 //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	 //cout<<"           Time left:"<<leftTime<<endl<<endl;
		 cout<<endl<<endl;
		for(int i=0;i<y;i++)
		{
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			
			cout<<"                    ";
			for (int j = 0; j < x; j++)
			{
				if(gaming.game[i][j]==gaming.face)
			   {
				   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				   cout<<gaming.game[i][j];
			   }
				else if(gaming.game[i][j]==gaming.food)
				  {
				   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					cout<<gaming.game[i][j];
			   }
			   else if(gaming.game[i][j]==gaming.star)
				  {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<gaming.game[i][j];
			   }
			   else
			   {
				   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
				   cout<<gaming.game[i][j];
			   }
			}
			cout<<endl;
		}
		
		
		
	}
//########################################################
//Show score lifes and time etc
//########################################################
void pacman::detail() 
{
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			 gotoxy(43,8);
			 cout<<"Time : ";
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			 cout<<leftTime;
			  gotoxy(43,9);
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	         cout<<"Score: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<score<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(43,10);
			cout<<"Remaining life: ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<life<<endl;
			gotoxy(43,11);
		
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		cout<<"Remaining food items: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<gaming.fooditem<<endl;
		cout<<endl;
}
//########################################################
//Return score
//########################################################
int pacman::getscore() const
{
	return score;
}
//########################################################
//Destructor
//########################################################

pacman::~pacman()
	{
		
	}

