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
bool playerHasWon(Player p, Game g); 

#endif
