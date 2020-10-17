#include <stdio.h>
#include <stdlib.h>

#include "NACview.h"

void displayBoard(Game g) {
    for (int i = 0; i < tableSize; i++) {
        for (int j = 0; j < tableSize; j++) {
            int move = getMove(g, j, i); 
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

