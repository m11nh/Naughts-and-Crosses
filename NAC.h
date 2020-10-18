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

bool player(int player, Game g);
bool gameIsOver(Game g); 
void enterMove(Game g, Move m); 
bool validMove(Game g, Move m);
Game newGame(Player p); 
void endGame(Game g); 
Player getPlayerTurn(Game g); 
Player getCoordState(Game g, int x, int y); 
int getEmptySlots(Game g); 
Player getWinner(Game g); 
bool gameIsDraw(Game g); 

#endif
