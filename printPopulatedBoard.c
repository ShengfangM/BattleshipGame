#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
/* this game used to print the populated board
inputs:
row: row of board
col: column of board

board: populated board,0 means no ship. >=1 means ship points
no return*/

void printPopulatedBoard(int row, int col,int **board)
{

    char colname[10]={'A','B','C','D','E','F','G','H','I','J'};

//print the board

    printf("   0   1   2   3   4   5   6   7   8   9\n");
    printf("   _______________________________________\n");
    
    for (int i = 0; i < row; i++) {
    
        printf("%c ",colname[i]);
        
        printf("|"); 
        
        for (int j=0; j<col;j++) {
        
            if(board [i][j]>0) {                          //print "X" if point of ship
   
                printf(" X |");
             }
            else {
            
            printf("   |");
                       
            }
            
            
        } 
        
        printf("\n");
	
	if (i==i-1)
	{
	printf("  ________________________________________\n");
	}
	else{printf("  |___|___|___|___|___|___|___|___|___|___|\n");}

    }

    printf("\n");
}
