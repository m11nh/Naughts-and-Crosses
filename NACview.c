#include <stdio.h>
#include <stdlib.h>

#include "NACview.h"

void displayBoard(Game g) {
    for (int i = 0; i < tableSize; i++) {
        for (int j = 0; j < tableSize; j++) {
            int move = getMove(g, j, i); 
            if (move == Naught) {
                printf("| X |"); 
            } else if (move == Cross) {
                printf("| O |"); 
            } else {
                printf("|   |"); 
            }
        }
        printf("\n"); 
        for (int x = 0; x < tableSize; x++) {
            printf("_____"); 
        }
        printf("\n"); 
    }
}

