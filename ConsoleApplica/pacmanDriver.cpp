//########################################################
//This is main or driver for the game
//########################################################

//########################################################
//Libraries used in the game
//########################################################	

#include <iostream>
#include <fstream>
#include<conio.h>
#include<windows.h>
#include<iomanip>
#include  "PACMAN.h"
#include "Game.h"
#pragma comment(lib, "winmm.lib")

using namespace std;
//########################################################
//Main functions prototype
//########################################################
void saveTofile(int score);//save your score to file if its highest then previous five
void goToGame();//initialize game
void loading();//load the game 
int menu();//display main menu
void highScore();//display high score
void instruction();//important rules
void welcome();//Display name etc 
//########################################################
//GOTOXY  function
//########################################################
void gotoxy(int x,int y)
{
	
	COORD co;
	co.X=x;
	co.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),co);
}

//########################################################
//Main function
//########################################################
int main()
{
	welcome();
	menu();
	return 0;
} 	
		
//########################################################
//Show loading before game start
//########################################################	
void loading()
	{
		char a[26];
		a[0]=2;
		for(int i=1;i<25;i++)
		{
			a[i]=46;
		}
	
		for(int i=0;i<25;i++)
		{
			for(int i=0;i<11;i++)
			cout<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<"                            Loading......\n                  ";
			a[i]=2;
			for(int j=0;j<25;j++)
			{
				if(a[j]==2)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
						cout<<a[j];
					}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout<<a[j];
			}
			a[i]=0;
			a[i+1]=2;
			

		}
		Sleep(200);
		system("cls");
	}
	
	
	
	}
//########################################################
//Make object of pacman game 
//########################################################
void goToGame()
{
	system("cls");
	
	loading();
	Game *Gaming;
	pacman gamer(20,20);
	Gaming=&gamer;
	Gaming->startGame();
	int score=Gaming->getscore();
	cout<<score<<endl;
	saveTofile(score);
	
   menu();
 
		
}
//########################################################
//Display main menu
//########################################################
int menu()
{   char bullet=26;
   int y=6;
  
   system("cls");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
   for (int i = 0; i < 5; i++)
   {
	   cout<<endl;
   }
   cout<<"                      ================================\n";
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
   cout<<"                      =      "<<" 1:NEW GAME             ="<<endl<<endl;
   cout<<"                      =      "<<" 2:INSTRUCTION          ="<<endl<<endl;
   cout<<"                      =      "<<" 3:HIGH SCORE           ="<<endl<<endl;
   cout<<"                      =      "<<" 4:EXIT                 ="<<endl<<endl;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
   cout<<"                      ================================\n";

   gotoxy(15,15);
   
   cout<<"                         ENTER <CHOOSE> \n";
    char choice=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	gotoxy(26,6);
		cout<<bullet;
		PlaySound(TEXT("button-3.wav"), NULL, SND_FILENAME | SND_ASYNC);
	while(_kbhit)
   {
	  if(GetAsyncKeyState(VK_UP))
		{
			
			if(y!=6)
			{
				 PlaySound(TEXT("button-3.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gotoxy(26,y);
				cout<<" ";
				y-=1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			    gotoxy(26,y);
				cout<<bullet;
			}
		}
     if(GetAsyncKeyState(VK_DOWN))
		{
			if(y!=12)
			{
				 PlaySound(TEXT("button-3.wav"), NULL, SND_FILENAME | SND_ASYNC);
				gotoxy(26,y);
				cout<<" ";
				y+=1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				gotoxy(26,y);
				cout<<bullet;
			}
			
		}
	
		choice=getch();
		if(choice==13 && y==6)
		 {
			goToGame();
			y+=6;
		}
	if(choice==13 && y==8)
	{
		 PlaySound(TEXT("button-6.wav"), NULL, SND_FILENAME | SND_ASYNC);
		instruction();
		y+=4;
	}
	if(choice==13 && y==10)
	{
		 PlaySound(TEXT("button-6.wav"), NULL, SND_FILENAME | SND_ASYNC);
		highScore();
		y+=2;
	}
	if(choice==13 && y==12)
	{
		 
		gotoxy(25,25);
		
		return 0;
	}
		
   }

	
}
//########################################################
//Display 5 high scores
//########################################################
void highScore()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	system("cls");
	ifstream inFile;
  inFile.open("highScore.txt");
  if(inFile.fail())
	  cout<<"File not found\n";
 
 int score[5];
 for(int i=0;i<10;i++)
	 cout<<endl;
 cout<<"                        High score in pacman...\n";
 for(int i=0;i<5;i++)
 {
   inFile>>score[i];
   cout<<"				   "<<(i+1)<<":"<<score[i]<<endl;
 }
 // Close the file
 inFile.close();
  char b;
 cout<<"                       ------------------------\n";
 cout<<"                                      ESC<EXIT>\n         ";
 b=getch();
 while(b!=27)
	 b=getch();
 if(b==27)
 {
   menu();
 }

}
//########################################################
//Important instruction and rule for game
//########################################################
void instruction()
{
	system("cls");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	for(int i=0;i<5;i++)
		cout<<endl;
	cout<<"            1:Total three lifes are available to complete all levels\n";
   cout<<"            2:Move pacman with up,down,right and left key\n";
   cout<<"            3:Do not strike with diamond shape hurdle it will reduce your one \n              chance \n";
   cout<<"            4:There are total two stages in this game\n";
   cout<<"            5:Total 500 seconds are given to complete each level\n";
    cout<<"            6:If you strike with diamond hurdle you will lose 50 points\n";
   cout<<"            7:5 Score will be awarded for eating each food item \n\n\n";
  
 char b;
 cout<<"            ----------------------------------------------------------------\n";
 cout<<"                                                               ESC<EXIT>\n         ";
 b=getch();
 while(b!=27)
	 b=getch();
 if(b==27)
 {
   menu();
 }
   
}
//########################################################
//Save five highest score to a file
//########################################################
void saveTofile(int score)
{
	
	ifstream inFile;
  inFile.open("highScore.txt");
  if(inFile.fail())
	  cout<<"File not found\n";
 
 int highscore[6];
 highscore[0]=score;
 cout<<"                 High score in pacman...\n";
 for(int i=1;i<6;i++)
 {
   inFile>>highscore[i];
   cout<<"  "<<(i+1)<<":"<<highscore[i]<<endl;
 }
 for (int i = 0; i < 5; i++)
 {
	 for (int j = 0; j < 5; j++)
	 {
		 if(highscore[j]<highscore[j+1])
		 {
			 int temp=highscore[j+1];
			 highscore[j+1]=highscore[j];
			 highscore[j]=temp;
		 }
	 }
 }
 // Close the file
 
 ofstream outputFile;
 outputFile.open("highScore.txt");
 for(int i=0;i<5;i++)
 outputFile<<highscore[i]<<endl;
  outputFile.close();
  inFile.close();
}
//########################################################
//Display welcome screen
//########################################################
void welcome()
{
	for (int i = 0; i < 5; i++)
   {
	   cout<<endl;
   }
	         PlaySound(TEXT("interference.wav"), NULL, SND_FILENAME |SND_ASYNC|SND_LOOP);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	
	 cout<<"\t\t (                       *                ) "<<endl;
	 cout<<"\t\t  )\\ )    (        (    (  `     (      ( /( "<<endl;
	 cout<<"\t\t (()/(    )\\       )\\   )\\))(    )\\     )\\())"<<endl;
	 cout<<"\t\t /(_))((((_)(   (((_) ((_)()\\((((_)(  ((_)\\ "<<endl;
     cout<<"\t\t (_))   )\\ _ )\\  )\\___ (_()((_))\\ _ )\\  _((_)"<<endl;
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
     cout<<"\t\t | _ \\  (_)_\\(_)((/ __||  \\/  |(_)_\\(_)| \\| |"<<endl;
	 cout<<"\t\t |  _/   / _ \\   | (__ | |\\/| | / _ \\  | .` |"<<endl;
	 cout<<"\t\t |_|    /_/ \\_\\   \\___||_|  |_|/_/ \\_\\ |_|\\_|"<<endl;






	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
   cout<<"                      =================================\n";
  
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);

 
    for (int i = 24; i > 14; i--)
		{
			
			
			gotoxy(28,i);
	
	  cout << "  GAME DEVELOPED BY:  \n";
			_sleep(100);
			if(i>15)
			{
			gotoxy(28,i);
			cout << "                           ";
			}
   }
	for (int i = 24; i > 16; i--)
		{
			
			
			gotoxy(28,i);
	
	  cout << "   SHAHARYAR TARIQ\n";
			_sleep(100);
			if(i>17)
			{
			gotoxy(28,i);
			cout << "                           ";
			}
   }


	 for (int i = 24; i > 18; i--)
		{
			
			
			gotoxy(28,i);
	
	  cout << "     BITF12M043  \n";
			_sleep(100);
			if(i>19)
			{
			gotoxy(28,i);
			cout << "                ";
			}
   }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
   gotoxy(22,21);
    cout<<"=================================\n";
   Sleep(5000);

   system("cls");
   for (int i = 0; i < 10; i++)
   {
	   cout<<endl;
   }
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
   cout<<"          NOTE:USE ARROW KEYS FOR SELECTION AND FOR PLAYING GAME\n";

   Sleep(3000);
}