#include <stdio.h>
#include <stdlib.h>
#include "Board.h"
/*The function is used to populate ships in the board
random choose points for ships depending on their size
input: 
row: number of rows in the board
column: number of column in the board
board: the initialized board done in option2
optionif: check which menu option has been checked
return: game board is populated,no cheating
*/

//variables in the function
int shipdirec=0;    //ship direction
int shiprow=0;      //ship beginning row
int shipcol=0;      //ship beginning column

const int carriernum=5;
const int battleshipnum=4;
const int cruisernum=3;
const int submarinenum=3;
const int destroyernum=2;

void populateBoard(int row, int col,int ** board) {


 /* check initial game board to populating ship. */
    for (int i=0;i<row;i++) {
       for (int j=0; j<col;j++) {
          board[i][j]=0;
       }
   }
    
int overlap=0;     //variable used to checked if the ship hitted twice
   
 
 //find start position of carrier
    shipdirec=rand()%2+1;         //carrier direction
    
    if (shipdirec==1) {           //carrier placed horizontal
        shiprow=rand()%10;        //get ship's point randomly
        shipcol=rand()%6;  
        
        for(int j=shipcol; j<shipcol+carriernum;j++)
        {
    
           board[shiprow][j]=1;
        }
    }
    else {                      //carrier placed vertical
           
        shiprow=rand()%6;        //get ship's point randomly
        shipcol=rand()%10;
        for(int i=shiprow; i<shiprow+carriernum;i++)
        {
    
           board[i][shipcol]=1;
        }
    }

 //find start position of battleship
    do {
        shipdirec=rand()%2+1;    //battleship direction
    
    if (shipdirec==1) {          //horizontal
        shiprow=rand()%10;       //get ship's point randomly
        shipcol=rand()%7;
        for(int j=shipcol; j<shipcol+battleshipnum;j++)
        {
    
           if (board[shiprow][j]>0){      //check if any spots has been ocuppied
               overlap=1;
              break;
           }
           else
           {
               overlap=0;              
           }
        }
        if (overlap==0) {                   //check if any spots has been ocuppied
            for(int j=shipcol; j<shipcol+battleshipnum;j++)
            {
    
               board[shiprow][j]=2;
               
           }
        }
    }
    
    else {                                        //vertical
    
        shiprow=rand()%7;                         //get ship's point randomly
        shipcol=rand()%10;
        for(int i=shiprow; i<shiprow+battleshipnum;i++)
        {
    
           if (board[i][shipcol]>0) {              //check if any spots has been ocuppied
           overlap=1;
           break;
           
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {                             //check if any spots has been ocuppied
            for(int i=shiprow; i<shiprow+battleshipnum;i++)
            {
    
               board[i][shipcol]=2;        
            }
        }
    }
    } while(overlap==1);
    

//find start position of cruiser
 do {
    shipdirec=rand()%2+1;    // direction
    
    if (shipdirec==1) {       //cruiser placed horizontal
        shiprow=rand()%10;
        shipcol=rand()%8;
        for(int j=shipcol; j<shipcol+cruisernum;j++)
        {
    
           if (board[shiprow][j]>0){
           overlap=1;
           break;
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int j=shipcol; j<shipcol+cruisernum;j++)
            {
    
               board[shiprow][j]=3;
           }
        }
    }
    
    else {                      //cruiser placed vertical
    
        shiprow=rand()%8;
        shipcol=rand()%10;
        for(int i=shiprow; i<shiprow+cruisernum; i++)
        {
    
           if (board[i][shipcol]>0) {
           overlap=1;
           break;
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int i=shiprow; i<shiprow+cruisernum;i++)
            {
    
               board[i][shipcol]=3;
               
           }
        }
    }
    } while(overlap==1);
    
    
//find start position of     submarine
 do {
    shipdirec=rand()%2+1;    //submarine direction
    
    if (shipdirec==1) {       //submarine placed horizontal
        shiprow=rand()%10;
        shipcol=rand()%8;
        for(int j=shipcol; j<shipcol+submarinenum;j++)
        {
    
           if (board[shiprow][j]>0){
           overlap=1;
           break;
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int j=shipcol; j<shipcol+submarinenum;j++)
            {
    
               board[shiprow][j]=4;
               
           }
        }
    }
    
    else {                      //submarine placed vertical
    
        shiprow=rand()%8;
        shipcol=rand()%10;
        for(int i=shiprow; i<shiprow+submarinenum;i++)
        {
    
           if (board[i][shipcol]>0) {
           overlap=1;
           break;           
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int i=shiprow; i<shiprow+submarinenum;i++)
            {
    
               board[i][shipcol]=4;
                          
           }
        }
    }
    } while(overlap==1);
    
    
    //find start position of destroyer
 do {
    shipdirec=rand()%2+1;    //submarine direction
    
    if (shipdirec==1) {       //submarine placed horizontal
        shiprow=rand()%10;
        shipcol=rand()%9;
        for(int j=shipcol; j<shipcol+destroyernum;j++)
        {
    
           if (board[shiprow][j]>0){
           overlap=1;
           break;
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int j=shipcol; j<shipcol+destroyernum;j++)
            {
    
               board[shiprow][j]=5;
                          
           }
        }
    }
    
    else {                      //submarine placed vertical
    
        shiprow=rand()%9;
        shipcol=rand()%10;
        for(int i=shiprow; i<shiprow+destroyernum;i++)
        {
    
           if (board[i][shipcol]>0) {
           overlap=1;
           break;
           }
           else   {
               overlap=0;
           }
        }
        if (overlap==0) {
            for(int i=shiprow; i<shiprow+destroyernum;i++)
            {
    
               board[i][shipcol]=5;
           }
        }
    }
    } while(overlap==1);

                
         printf("Game board has been populated\n");
     
}
