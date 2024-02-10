#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
/* this function is used to play the game with initial score of 100.
Players choose target, shows 'it is a shipname'  if its a ship point.
shows shipname is sunk when all points were hitted. score -1 when 
target is not a ship point(missed).
input:
row: number of rows in the board
column: number of column in the board
iniboard: populated board, 0: no ship, 1:carrier, 2:battleship, 3:cruiser,
                    4. submarine, 5:destroyer
return: score of player
*/
//variables in the function
char letter;          //record target, 'H' for hitted ship 'M' for missed

int hitpointval;           //value of hitted point in the iniboard 
int rowi;             //hitted points
int coli;

//function
int play(int row, int col, int **iniboard){


 int score=100;             //initial score ,-1 with each missing
int carrierhit=5;           //initial carrier points number,-1 with each hit
int battleshiphit=4;        //initial battleshiphit points number,-1 with each hit
int cruiserhit=3;          //initial cruiserhit points number,-1 with each hit
int submarinehit=3;          //initial submarinehit points number,-1 with each hit
int destroyerhit=2;          //initial destroyerhit points number,-1 with each hit
 
 // prepare borad used in game 
 /*creat a board, value changed during game play*/
 int **board = (int **)malloc(row*sizeof(int *)); 
for (int i=0;i<row;i++) {
        board[i]=(int *)malloc(col*sizeof(int));
}
//created 2D char array for printing the board,value changing depends on the hit
    char **boardstr=(char **)malloc(row*sizeof(char *));
    for (int i=0;i<row;i++) {
        boardstr[i]=(char *)malloc(col*sizeof(char));
    }
    //initial the board
    for (int i = 0; i < row; i++) {
          
        for (int j=0; j<col;j++) {
            boardstr[i][j]=' ';            //initial char ' '  
            board[i][j]=iniboard[i][j];    //copy value from initial
            
        }
    }
 
    printf("Now let's play the game \n");
    printPlayBoard(row,col,boardstr);            //call function below to print blank board
   
   // start play 
  
  do {    
    
    /* get the target from screen*/
        do {
            printf("please enter the target:");
            scanf("%c%d", &letter, &coli);
            while(getchar()!='\n');
            rowi=letter-'A';
            
        } while (rowi<0 || coli<0 ||rowi>9 ||coli>9);
    //
    hitpointval=board[rowi][coli];            //target the point and get the value
    
    //tell which ship it is or not a ship point by target value
    if(hitpointval==0) {                         //not a ship
    
        boardstr[rowi][coli]='M';
        printPlayBoard(row,col,boardstr); 
        printf("It missed\n");
        score--;                                 //score -1
    }
    else if(hitpointval==1){                     //hitted a carrier
        board[rowi][coli]=6;
        boardstr[rowi][coli]='H';
        printPlayBoard(row,col,boardstr); 
        carrierhit--;                            //ship points number -1
        if(carrierhit==0) {
            printf("Carrier is sunk.\n");}
        else {
            printf("It is a carrier.\n");
        }
    }
    else if(hitpointval==2){                    //hitted a Battleship
        board[rowi][coli]=7;
        boardstr[rowi][coli]='H';
        printPlayBoard(row,col,boardstr); 
        battleshiphit--;        
        if(battleshiphit==0) {
            printf("Battleship is sunk.\n");}
        else {
            printf("It is a Battleship.\n");
        }

    }
    else if(hitpointval==3){                    //hitted a Cruiser
        board[rowi][coli]=8;
        boardstr[rowi][coli]='H';
        printPlayBoard(row,col,boardstr); 
        cruiserhit--;                            //ship points number -1
        if(cruiserhit==0) {
            printf("Cruiser is sunk.\n");}
        else {
            printf("It is a Cruiser.\n");
        }
    
    }
    else if(hitpointval==4){                    //hitted a Submarine
        board[rowi][coli]=9;
        boardstr[rowi][coli]='H';
        printPlayBoard(row,col,boardstr); 
        submarinehit--;                            //ship points number -1
        if(submarinehit==0) {
            printf("Submarine is sunk.\n");}
        else {
            printf("It is a Submarine.\n");
        }
    
    }
    else if(hitpointval==5){                    //hitted a Destroyer
        board[rowi][coli]=10;
        boardstr[rowi][coli]='H';
        printPlayBoard(row,col,boardstr); 
        destroyerhit--;                             //ship points number -1
        if(destroyerhit==0) {
            printf("Destroyer is sunk.\n");}
        else {
            printf("It is a Destroyer.\n");
        }
    }
    else
    {
        printf("Waring: not available \n");
    }
    
    
    
    }while (carrierhit>0 || battleshiphit>0 ||cruiserhit>0 ||submarinehit>0 || destroyerhit>0 );
  //free the memory  
 for (int i=0;i<row;i++) {
        free (boardstr[i]);
        free (board[i]);
    }
    free (boardstr);
    free (board);
    
    return score;
}
/*this is a function for printing game board during play
intput:
row: number of rows in the board
column: number of column in the board
boardstr: contains letters to be printed on screen
no return
*/
void printPlayBoard(int row, int col, char **boardstr)
{

    char colname[10]={'A','B','C','D','E','F','G','H','I','J'};
    printf("   0   1   2   3   4   5   6   7   8   9\n");
    printf("   _______________________________________\n");
    
    for (int i = 0; i < row; i++) {
    
        printf("%c ",colname[i]);
        
        printf("|"); 
        
        for (int j=0; j<col;j++) {
        
            
            printf(" %c ",boardstr[i][j]);
            printf("|");
        } 
        
        printf("\n");
	
	if (i==i-1)
	{
	printf("  ________________________________________\n");
	}
	else{printf("  |___|___|___|___|___|___|___|___|___|___|\n");}

    }

   

}
