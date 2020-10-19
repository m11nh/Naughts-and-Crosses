#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"
#include "NAC.h"

#define VERBOSE 0
#define NOTVERBOSE 1

static bool isVerbose(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    bool v = isVerbose(argc, argv); 
    Game g = newGame(Naught);
    displayBoard(g, v); 
    while (!gameIsOver(g)) {
        Move m; 
        if (getMove(getPlayerTurn(g), &m) && validMove(g, m)) {
            enterMove(g, m); 
            displayBoard(g, v); 
        } else {
            showInvalidMoveError(); 
        }
    }
    showEndGameMsg(g); 
}

static bool isVerbose(int argc, char *argv[]) {
    return ((argc == 2) && (strcmp(argv[1], "-v") == 0)); 
}

