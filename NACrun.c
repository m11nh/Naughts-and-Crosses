#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"
#include "NAC.h"

int main(int argc, char *argv[]) {
    Game g = newGame(Naught);
    while (!gameIsOver(g)) {
        Move m; 
        getMove(getPlayerTurn(g), &m); 
        if (validMove(g, m)) {
            enterMove(g, m); 
            displayBoard(g); 
        } else {
            showInvalidMoveError(); 
        }
    }
    showEndGameMsg(g); 
}

