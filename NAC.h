#ifndef NAC_H_   /* Include guard */
#define NAC_H_

enum Player { Naught, Cross }; 

typedef gameState *Game; 

bool playerHasWon(Player p, Game g);
bool gameIsOver(Game g); 
void enterMove(Game g, Player p , int x, int y); 
bool validMove(Game g, Player p, int x, int y);
Game newGame(); 
void endGame(Game g); 
Player PlayersTurn(Game g); 

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