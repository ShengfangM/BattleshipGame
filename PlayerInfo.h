#ifndef _PLAYERINFO_H_
#define _PLAYERINFO_H_
//state the date structure to store playdate
typedef struct Date{ 
 int year;  
 int month;  
 int day;  
}  DATE;
//state the structure used to store player info
typedef struct Players {
    char name[30];
    char country[20];
    DATE playdate;
    int score;
} PLAYERS;

PLAYERS PlayerInfo (void);

void save( char *,PLAYERS );
void scoreBoard( char *);


#endif
