#include <stdio.h>
#include <stdlib.h>

#include "NAC.h"

struct gameState {
    int playerTurn; 
    int **tableRep; 
    int emptySlots; 
}; 

// helper static functions declarations
static bool pointExists(Game g, Player p, int x, int y);

// main functions
int getEmptySlots(Game g) {
    return g->emptySlots; 
}

Player getMove(Game g, int x, int y) {
    return g->tableRep[y][x]; 
}

Game newGame(Player playerStarting) {
    Game g = malloc(sizeof(*g)); 

    // allocates memory to a tableSize x tableSize game of Naughts and Crosses
    g->tableRep = malloc(sizeof(int *) * tableSize); 
    for (int i=0; i < tableSize; i++) {
        g->tableRep[i] = malloc(sizeof(int) * tableSize); 
        // sets the contents of the table to -1
        for (int j = 0; j < tableSize; j++) {
            g->tableRep[i][j] = -1; 
        }
    }
    
    // set initial player turn 
    g->playerTurn = playerStarting; 
    g->emptySlots = tableSize * tableSize; 
    return g; 
}

void endGame(Game g) {
    // free the contents of the table
    for (int i = 0; i < tableSize; i++) {
        free(g->tableRep[i]); 
    }
    free(g->tableRep); 
    // frees the game itself
    free(g); 
}

void enterMove(Game g, Player p, int x, int y) {
    if (g->tableRep[y][x] == -1) {
        g->tableRep[y][x] = p; 
        g->emptySlots--; 
    }
}

bool validMove(Game g, int x, int y) {
    if (g->tableRep[y][x] != -1) {
        return false; 
    }
    return true;
}

bool gameIsOver(Game g) {
    return (g->emptySlots == 0) ? true : false; 
}

bool playerHasWon(Player p, Game g) {
    int horiz, vert, left_diag, right_diag = true; 
    for (int i = 0; i < 3; i++) {
        // horizontal and vertical cases    
        for (int j = 0; j < 3; j++) {
            if (!pointExists(g, p, i, j)) {
                horiz = false; 
            }
            if (!pointExists(g, p, j, i)) {
                vert = false; 
            }
        }

        // left_diagoncal case
        if (!pointExists(g, p, i, i)) {
            left_diag = false; 
        }
        if (!pointExists(g, p, i, 2 - i)) {
            right_diag = false; 
        }

        // final return
        if (horiz || vert || left_diag || right_diag) {
            return true; 
        }
        horiz = true; 
        vert = true; 
    }
    return false; 
}

static bool pointExists(Game g, Player p, int x, int y) {
    return (g->tableRep[y][x] == p); 
}

int getPlayerTurn(Game g) {
    return g->playerTurn; 
}




