#ifndef NAC_H
#define NAC_H

#include <stdbool.h>

#define tableSize 3

typedef struct gameState *Game; 
typedef enum { Naught, Cross, None =-1 } Player; 

bool player(int player, Game g);
bool gameIsOver(Game g); 
void enterMove(Game g, Player p, int x, int y); 
bool validMove(Game g, int x, int y);
Game newGame(Player p); 
void endGame(Game g); 
Player getPlayerTurn(Game g); 
Player getMove(Game g, int x, int y); 
int getEmptySlots(Game g); 

#endif
/*
Structs that i wil need 

gameState
- playerTurn - either 0, 1, for players
- game rep - array[3][3] - 0, and 1 representing whether naught or cross on a certain location, -1 if currently empty
- emptySlots - to check if there still are turns needed

Brainstorming functions I may need

playerHasWon(player, gameState)
playerHasLost(player, gameState)
gameIsOver(gameState)
enterMove(gameState, move)
isPlayersTurn(player, gameState) 

*/ 