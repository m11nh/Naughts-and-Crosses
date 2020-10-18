#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"

void displayBoard(Game g) {
    for (int i = 0; i < tableSize; i++) {
        if (i == 0) {
            printf("     %d  ", i); 
        } else {
            printf("   %d   ", i); 
        }
    }
    printf("\n"); 
    for (int i = 0; i < tableSize; i++) {
        printf("%d  ", i); 
        for (int j = 0; j < tableSize; j++) {
            int move = getCoordState(g, j, i); 
            char moveChar = ' '; 
            if ((move == Naught) || (move == Cross)) {
                moveChar = (move == Naught) ? 'O' : 'X'; 
            } 
            if (j == tableSize - 1) {
                printf("  %c  ", moveChar);
            } else {
                printf("  %c  |", moveChar);
            }
        }
        printf("\n   "); 
        if(i != tableSize - 1) {
            for (int x = 0; x < tableSize; x++) {
                printf("______"); 
            }
        }
        printf("\n\n"); 
    }
}

bool getMove(Player p, Move *m) {
    char currPlayerStr[10], x[10], y[10]; 
    char t; 
    getPlayerString(p, currPlayerStr); 
    printf("%s, please enter in your move:\n", currPlayerStr);
    printf("x: ");
    if ((fgets(x, 10, stdin) == NULL) || (sscanf(x, "%d", &(m->x)) != 1)) {
        sscanf(x, "%c", &t); 
        if (t == 'q') {
            exit(EXIT_SUCCESS); 
        }
        return false; 
    }
    printf("y: "); 
    if ((fgets(y, 10, stdin) == NULL) || (sscanf(y, "%d", &(m->y)) != 1)) {
        sscanf(y, "%c", &t); 
        if (t == 'q') {
            exit(EXIT_SUCCESS); 
        }
        return false; 
    }
    return true; 
}

void getPlayerString(Player p, char *str) {
    if (p == Naught) {
        strcpy(str, "Naught"); 
    } else if (p == Cross) {
        strcpy(str, "Cross"); 
    } else {
        str = NULL; 
    }
}

void showInvalidMoveError() {
    printf("Move can only be an integer between 0 and %d, and only on empty square\n", tableSize); 
}

void showEndGameMsg(Game g) {
    if (gameIsDraw(g)) {
        printf("Game is a draw!\n"); 
    } else {
        Player winner = getWinner(g); 
        char winnerStr[10];
        getPlayerString(winner, winnerStr);         
        printf("%s has won!\n", winnerStr); 
    }
}