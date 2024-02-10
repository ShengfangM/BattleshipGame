#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "PlayerInfo.h"
#include "Board.h"

/*this is the main function for Battleship game
 It calls the other functions from their files to
 accomplishment the procedure*/

/*variables in main function*/
int ch=0;                             //read player's choice
int option[8]={0,0,0,0,0,0,0,0};  //record which option has been done
int *optioninf=option;                //store player's choice to check if obey the rule
PLAYERS plyr;                //used to store player's information
int cheat=0;                 //used to check if the player cheated in the game
int overplay=0;              //used to check if the player want to replay the game

const int row=10;            // rows of board
const int col=10;            // columns of board

int ** board;                //store game board

int plyrorder=0;             //used to record players number in the game
char *plyrinfofile="Players information and score.txt";       //file used to store player's information
  
/* main function*/
int main() {


    int a=0;                  //*define val used as return val */
    a= menu();                //call menu fuction from menu.c*/
    
    while (a !=0){               //loop the whole play process until exit
        
       printf("Please make your choice: \n");   /*player choose the options*/
       
       scanf("%d", &ch);                        /* get user's choice*/
       while(getchar()!='\n');
        
        if (ch ==1) {  
            optioninf[1]=1;                         /* when user choose option 1*/
            plyr=PlayerInfo();                      //get playerinformation 
            a=menu();            
        } 
        else if (ch ==2) {                          //player choose option 2
             //call function to initialize board
           board=initializeboard(row,col,optioninf);  
            a=menu();           
        }

        else if (ch ==3) {                          //player choose option 3
             //check if option 1 2  has been done, if yes can choose option 3
           if (optioninf[1] ==1 && optioninf[2] ==1 )
            {
                
            //populate the board , return not cheated once populated
                populateBoard(row,col,board); 
               
                  cheat=0;                    //populated the board, not cheat            
                  optioninf[3]=1;           //check menu option 3
                 overplay=0;               //no multiplay
                }
               else if (optioninf[1] ==0) {      //option 1 is not done
                
                printf("Player's information is required. Please choose option 1 first!\n");

            }
            else  {              //option 2 is not done
                
                printf("Please initialize the board. Please choose option 2 first!\n");

            }
            a=menu(); 
            
        }
         else if (ch ==4) {                           //player choose option 4
      //check if option 1 2 3 has been done, if yes can choose option 4
           if (optioninf[1] ==1 && optioninf[2] ==1 && optioninf[3] ==1)
           {
             if(overplay==1)                 //player has played before, ask repopulate first
             {                  
                a=menu();
                printf("Please populate board again!\n");
             }
             else{                           //players play the game for the first time
                optioninf[4]=1;
                plyr.score=play(row, col, board);   //call play function and return player's score
                if (cheat==0)  
                {                              
                    plyrorder ++;
                    save(plyrinfofile,plyr);    //save the score, then print on screen
                    printf("your Score is %d \n", plyr.score);
                }
                else {             //printed populated board before play, don't save the score
                    printf("Score can't be recorded.");
                }
                overplay=1;         //player has played the game 
                
                }  
            }
            else if (optioninf[1] ==0) {      //option 1 is not done
                
                printf("Player's information is required. Please choose option 1 first!\n");

            }
            else if (optioninf[2] ==0) {              //option 2 is not done
                
                printf("Please initialize the board. Please choose option 2 first!\n");

            }
            else {                                     //option 3 is not done
                
                printf("Please populate the board. Please choose option 3 first!\n");
                
            }
            a=menu();
         }
        else if (ch ==5) {                   //player choose option 5
              //check if option 1 2 3 has been done, if yes can choose option 5
           if (optioninf[1] ==1 && optioninf[2] ==1 && optioninf[3] ==1)
            {
                cheat=1;                    //have printed the board, used to check if cheated
                optioninf[5]=1;             //
                
                printPopulatedBoard( row,  col, board);   //print populated board
               
            }
            else if (optioninf[1] ==0) {              //option 1 is not done 
                printf("Player's information is required. Please choose option 1 first!\n");

            }
            else if (optioninf[2] ==0) {               //option 2 is not done
                printf("Please initialize the board. Please choose option 2 first!\n");

            }
            else {               //option 3 is not done
                printf("Please populate the board. Please choose option 3 first!\n");
                
            }
             a=menu();  
        
        }
        else if  (ch ==6) {
          //check if option 1 2 3 has been done, if yes can choose option 6
            if (optioninf[1] ==1 && optioninf[2] ==1 && optioninf[3] ==1)
            {
                scoreBoard(plyrinfofile);               //call function to print player's score
                
            }
            else if (optioninf[1] ==0) {               //option 1 is not done
                printf("Player's information is required. Please choose option 1 first!\n");

            }
            else if (optioninf[2] ==0) {               //option 2 is not done
                 printf("Please initialize the board. Please choose option 2 first!\n");

            }
            else {                                   //option 3 is not done
               printf("Please populate the board. Please choose option 3 first!\n");
                
            }
            a=menu();
         } 
        else if  (ch ==7) {
      
            a=exitgame();    //call exit
        }

        
        else {
         
             printf("Please enter the number in menu!\n");
            continue;           
       }

    }
    if (board !=NULL)
    {
 for (int i=0;i<row;i++) {
        
        free (board[i]);
    }
    
    free (board);
    board = NULL;}
     //if (optioninf !=NULL) {free (optioninf);}
    return a;
}

