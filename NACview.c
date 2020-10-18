#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"

void displayBoard(Game g) {
    for (int i = 0; i < tableSize; i++) {
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
        printf("\n"); 
        if(i != tableSize - 1) {
            for (int x = 0; x < tableSize; x++) {
                printf("______"); 
            }
        }
        printf("\n\n"); 
    }
}

void getMove(Player p, Move *m) {
    char currPlayerStr[10]; 
    getPlayerString(p, currPlayerStr); 
    printf("%s, please enter in your move:\n", currPlayerStr);
    printf("x: ");
    scanf("%d", &(m->x)); 
    printf("y: "); 
    scanf("%d", &(m->y));  
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
    printf("Please Enter in a valid move.\n"); 
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