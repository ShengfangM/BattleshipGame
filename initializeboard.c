#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
/* This function is used to initialize Battleship game board 
by giving board size and return the board to main function 

input parameters: row of board, column of board, menu option info
return parameters: initialized game board 
*/

int ** initializeboard(int row, int col, int* option) 
{

if (option[1] ==1)                    //check if menu option 1 checked
 {
    option[2]=1;                      // menu option 2 been choosed      
    
    char colname[10]={'A','B','C','D','E','F','G','H','I','J'}; 

 /* initial board array */
 
 int ** iniboard=(int **) malloc(row*sizeof(int *));
     for (int i=0;i<row;i++) {
        iniboard[i]=(int *)malloc(col*sizeof(int));
    }


    char **boardchar=(char **) malloc(row*sizeof(char *));
     for (int i=0;i<row;i++) {
        boardchar[i]=(char *)malloc(col*sizeof(char));
    }

  /*print initial board  frame */

    printf("   0   1   2   3   4   5   6   7   8   9\n");
    printf("   _______________________________________\n");
    
    for (int i = 0; i < row; i++) {
    
        printf("%c ",colname[i]);
        
        printf("|"); 
        
        for (int j=0; j<col;j++) {
        
            iniboard[i][j]=0;
            boardchar[i][j]=' ';
       
            printf(" %c |",boardchar[i][j]);
        
        } 
        
        printf("\n");
	
	if (i==i-1)
	{
	printf("  ________________________________________\n");
	}
	else{printf("  |___|___|___|___|___|___|___|___|___|___|\n");}

    } 
    printf("\n");
    /* free board array */
     for (int i=0;i<row;i++) {
           free (boardchar[i]);
         }
         free (boardchar);
    /////////////////////////////////////////////    
    //return that initial board 
        return iniboard;
     }
     else {                      //if menu option 1 hasn't checked then return to main menu
  
        printf("Player's information is required. Please choose option 1 first!\n \n");
        return NULL;
                
     }


}
