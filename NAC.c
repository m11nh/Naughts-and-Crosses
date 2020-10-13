#include <stdio.h>
#include <stdlib.h>

#include "NAC.h"

#define tableSize 3

struct gameState {
    int playerTurn; 
    int **tableRep; 
    int emptySlots; 
}; 

// helper static functions declarations

// main functions
Game newGame(Player playerStarting) {
    Game g = malloc(sizeof(*Game)); 

    // allocates memory to a tableSize x tableSize game of Naughts and Crosses
    g->tableRep = malloc(sizeof(int *) * tableSize); 
    for (i=0; i < tableSize; i++) {
        g->tableRep[i] = malloc(sizeof(int) * tableSize); 
        // sets the contents of the table to -1
        for (j = 0; j < tableSize; j++) {
            g->tableRep[i][j] = -1; 
        }
    }
    
    // set initial player turn 
    g->playerTurn = playerStarting; 
    g->emptySlots = tableSize * tableSize; 
}

void endGame(Game g) {
    // free the contents of the table
    for (i = 0; i < tableSize; i++) {
        free(g->tableRep[i]); 
    }
    free(g->tableRep); 
    // frees the game itself
    free(g); 
}

void enterMove(Game g, Player p, int x, int y) {
    if (g->tableRep[y][x] != -1) {
        g->tableRep[y][x] = p; 
        g->emptySlots--; 
    }
}

bool validMove(Game g, Player p, int x, int y) {
    if (g->tableRep[y][x] != -1) {
        return false; 
    }
    return true;
}

bool gameIsOver(Game g) {
    return (g->emptySlots == 0) ? true : false; 
}





