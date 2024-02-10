#include <stdio.h>
#include "PlayerInfo.h"
/* this function is used to save players information and score  to file.
input: 
filename : name of file used to save players information and score
plyr: player's information
retun: no*/
void save( char *filename,PLAYERS plyr) {

    FILE *fp;
    fp=fopen (filename,"a+");
    fprintf(fp,"%s %s %d %d %d %d\n", plyr.name,plyr.country,plyr.playdate.month, plyr.playdate.day, plyr.playdate.year,plyr.score);
    //fprintf(fp, "%s\n", plyr.name);
    //fprintf(fp, "%s\n", plyr.country);
    //fprintf(fp, "%d %d %d\n", plyr.playdate.month, plyr.playdate.day, plyr.playdate.year);
    //fprintf(fp, "%d\n", plyr.score);
   
    /*fprintf(fp, "Player No. %d : \n",order);
    fprintf(fp, "Name : %s \n", plyr.name);
    fprintf(fp, "Country : %s \n", plyr.country);
    fprintf(fp, "Date : %d %d %d \n", plyr.playdate.month, plyr.playdate.day, plyr.playdate.year);
    fprintf(fp, "Score : %d \n", plyr.score);
    */
    fclose(fp);
}
