#include <stdio.h>
#include <stdlib.h>

#include "NAC.h"

#ifndef NACVIEW_h
#define NACVIEW_H 

/*
    Provides a visual display of the game state.
    If isVerbose is set to true, the axis lines are displayed, otherwise
    the axis lines are not displayed. 
*/
void displayBoard(Game g, bool isVerbose); 

/*
    Asks player p for their move, and stores it into the provided move pointer. 
*/
bool getMove(Player p, Move *m); 

/*
    returns a string representation of the name of player. 
    i.e. Naught = "naught"
         Cross = "cross"
*/
void getPlayerString(Player p, char *str); 

/*
    Displays an error message saying the the move was not valid. 
*/
void showInvalidMoveError(); 

/*
    Displays the state of the game after it has ended. 
    If there is a winner, the name of the winner is declared. 
    If there is a draw, the user is notified that the game is a draw. 
*/
void showEndGameMsg(Game g);

#endif
