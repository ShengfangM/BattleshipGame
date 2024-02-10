# BattleshipGame

This project's name is Battleship Game. The program is developed with language C. it contains 10 code files and 3 head files:

Code files:
main.c: main function, call the other functions to accomplish the game.
menu.c: menu function, print menu option on screen.
PlayerInfo.c: PlayerInfo function, let player input their information and store the input information in the PLAYERS structure. 
initializeboard.c initializeboard function, initialize a 10-by-10 game board by allocate dynamic memory 
populateBoard.c, populateBoard fuction, randomly populate the board with five types of ships: Carrier (occupy 1-by-5 or 5-by-1 spots on board), Battleship(1-by-4 or 4-by-1) Cruiser (1-by-3 or 3-by-1)  Submarine (1-by-3 or 3-by-1) and Destroyer (1-by-2 or 2-by-1).
play.c: play function, start playing the game using the populated board.
save.c: save function, save the player's information and score in the file.
printPopulatedBoard.c: printPopulatedBoard function, print the populated board according to players call.
scoreBoard.c: scoreBoard function, print the list of players information and score
exitgame.c: exit the game.

Head files:
menu.h: statement menu function
PlayerInfo.h : state PLAYERS structure and PlayInfo function.
Board.h: state initializeboard, populateBoard, play, save, printPopulatedBoard, scoreBoard , and exitgame function.
