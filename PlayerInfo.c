#include <stdio.h>
#include "PlayerInfo.h"
/*this function used to scanf player's information and
store in the PLAYERS structure and initial the score 0*/

PLAYERS PlayerInfo (){

    PLAYERS plyr;
      
    printf("Please enter your name: \n");
    fflush(stdin);                               //get player's name
    fgets ( plyr.name,30,stdin);
  
    printf("Please enter your country: \n");
    fflush(stdin);
    fgets (plyr.country,20,stdin);                 //get player's country
 
    printf("Please enter date of the play (month day year): \n");
    scanf ("%d %d %d", &plyr.playdate.month, &plyr.playdate.day, &plyr.playdate.year);  

    plyr.score=0;

    return plyr;
}





