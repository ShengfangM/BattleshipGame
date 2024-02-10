#ifndef _BOARD_H_
#define _BOARD_H_
//state functions 
int **  initializeboard(int , int , int *);
void  populateBoard(int , int,int** );
void printPopulatedBoard(int , int ,int **); 
int play(int row, int col, int **);
void printPlayBoard(int,int,char**);
int exitgame();

#endif
