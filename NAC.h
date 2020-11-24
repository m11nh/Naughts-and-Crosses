#ifndef NAC_H
#define NAC_H

#include <stdbool.h>

#define tableSize 3

typedef struct Move {
    int x; 
    int y; 
} Move; 
typedef struct gameState *Game; 
typedef enum { Naught, Cross, None =-1 } Player; 

/*
    Returns True if game is over, otherwise false. 
*/ 
bool gameIsOver(Game g); 

/*
    Takes in a move, and if move is valid in current game state, the game state is updated 
    and the move is entered. 
*/
void enterMove(Game g, Move m); 

/*
    Returns true if move is valid in current game state, otherwise returns false. 
*/
bool validMove(Game g, Move m);

/*
    Creates a new game, with p player being the player with the starting move. 
*/
Game newGame(Player p); 

/*
    Removes all game related data specified by given game instance. 
*/
void endGame(Game g); 

/*
    Returns the player who has the current turn.
*/
Player getPlayerTurn(Game g); 

/*
    Returns the player who made a move at position given. 
    If no move has been made at the position then -1 is returned. 
*/
Player getCoordState(Game g, int x, int y); 

/*
    Returns an integer, representing the number of slots on the board that
    has not been occupied by a player move yet. 
*/
int getEmptySlots(Game g); 

/*
    Returns the player who has won the game. If the game has not been 
    won by any player, returns -1. 
*/ 
Player getWinner(Game g); 

/*
    Returns true if game has ended, and game is a draw
    otherwise returns false
*/ 
bool gameIsDraw(Game g); 

#endif
