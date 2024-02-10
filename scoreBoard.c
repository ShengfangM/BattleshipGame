#include <stdio.h>
#include "PlayerInfo.h"
/* this function is used to print players information and score from previously save file.
input: filename : name of file which contains players information and score
retun: no*/
void scoreBoard( char *filename) {

PLAYERS plyr;

//int totalline=0;
    
    FILE *fp;
    fp=fopen (filename,"r");
    

while (!feof(fp)) {

    fscanf(fp,"%s %s %d %d %d %d\n", plyr.name,plyr.country,&plyr.playdate.month, &plyr.playdate.day, &plyr.playdate.year,&plyr.score);
   //while(getchar()!='\n');
       
    printf("Player Information: \n");
    printf ("neme: %s \n", plyr.name);
    printf ("country: %s \n", plyr.country);
    printf ("Date of play: %d %d %d \n", plyr.playdate.month, plyr.playdate.day, plyr.playdate.year);           
    printf ("score: %d \n", plyr.score);
}

    
    fclose(fp);
}
