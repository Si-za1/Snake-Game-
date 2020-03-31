#include <iostream>
#include<conio.h>
#include<cstdlib>
using namespace std;
bool gameover;
const int width = 20;
const  int height = 20;
int x , y, Fruitx, Fruity ;
int ntail; // specifices the length of the snake  
int tailx[20], taily[20]; // gives the idea about how long the snake's tail is going to be
enum eDirection  {Stop=0, Left,Down,Up,Right }; // gives the idea for the direction of where and how is snake gonna move 
int score = 0 ;
eDirection dir; // the object for the enum type
int rand();

void setup()
{  // where we will be placing the fruit and the player and how will our box look like 
  gameover= false;
  dir = Stop;
  x= width /2;  // to place it at the centre.
  y= height / 2;
  Fruitx =rand()% width;
  Fruity =rand()% height;  // to place the fruit ranomly on the random x and y zone assume the graph and work
  score =0;


}
void draw()
// for the game process 
{
     system("cls");
     for (int i=0;i< width ; i++)
      cout<< "*" ;
      cout << endl;
     for(int i=0;i< height ; i++)
     {
         for(int j= 0 ; j< width ; j++)
         {
            if(j== 0)
              cout<< "*";
            if(i==y && j==x)
             cout<<"o";
            else if( i== Fruity && j== Fruitx)
             cout<< "F"; 
            else 
            { 
               bool print = false;
              for (k=0; k< nTail ; k++)      // to add the tail part , if it is equal to the givwn number then  a part in  the tail is going to be added 
               {
                  if( tailx[k]== j && taily[k]== i)
                  {
                     cout<< "o";// if true a single portion of the Tail is going to be added 
                     print = true;
                  }
               }
                if (!print)  // if the print function is true then we are going to add the blank space 
                { 
                  cout << " " ;
                }
            
            if (j== width -1 )
              cout<< "*";
          }
         cout<<endl;
      }
     for (int i=0;i< width ; i++)
      cout<< "*" ;
      cout << endl;
}

void input() // for taking the input for the game
{
 if(_kbhit())   // if we hit something on the keyboard then this function will be activated and the switch function will collect the value and it wil work accordinlgy
 {
 	switch(_getch())
 	{
 		case 'a':
 			dir = Left;
 			break;     // NOTE: since we have used the enum function at the top, so follow the naming accordingly, or else this is not gonna work. If youhave left at first then u have the up write it accordingly.
 		case 's':
 			dir = Down ;
 			break;
 		case 'd':
 			dir = Up;
 			break;
 		case 'f':
 			dir = Right;
 			break;
 		case 'q':
 			gameover = true;
 			break;
	 }
 }

}

void gamelogic()
 // how does the game work // the actual concept of the whole game 
{
  int prevx, prevy;
  int prev2x , prev2y;
  int prevX = tailx[0];
    prevy = taily[0];
    prev2x, prev2y ;
   tailx[0] = x;
   taily[0] = y;
  for ( i=1; i< nTail ; i++)
   { // we need to keep the track of where the snake is and where the tail will be added so we have the prev 2x and 2y accordingly anfd as the process of the backtracking the values are exchanged using the recursion.
   
     prev2x= tailx[i];
     prev2y  = taily[i];
     tail[i] = prevx;
     tail[i] = prevy;
      prevx  = prev2x;
      prevy  = prev2y;
   }
   switch(dir)
   {
    case Left:
     x--;
     break;
    case Right :
     x++;
     break;
    case  Up :
     y++;
     break;
     case Down :
     y--;
     break;
    default :
     break;
  }
   if (x>width || x<0 ||y>height || y<0)
    gameover = true;
     
   } 











int main()
{
    setup();
    while(!gameover)
    {
      draw();
      input();
      gamelogic();
    
    }
    return 0;
}
