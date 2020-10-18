#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"
#include "NAC.h"

#define VERBOSE 0
#define NOTVERBOSE 1

int main(int argc, char *argv[]) {
    Game g = newGame(Naught);
    displayBoard(g); 
    while (!gameIsOver(g)) {
        Move m; 
        if (getMove(getPlayerTurn(g), &m) && validMove(g, m)) {
            enterMove(g, m); 
            displayBoard(g); 
        } else {
            showInvalidMoveError(); 
        }
    }
    showEndGameMsg(g); 
}

