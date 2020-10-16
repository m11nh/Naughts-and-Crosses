#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NACview.h"
#include "NAC.h"

char *getPlayerString(Player p); 

int main(int argc, char *argv[]) {
    Player n = Naught, c = Cross;  
    Game g = newGame(n);
    while (!playerHasWon(n, g) && !playerHasWon(c, g)) {
        Player current = getPlayerTurn(g);
        char * currentPlayerString = getPlayerString(current); 
        int x, y; 
        printf("%s, please enter in your move:\n", currentPlayerString);
        printf("x: ");
        scanf("%d", &x); 
        printf("y: "); 
        scanf("%d", &y);  
        enterMove(g, current, x, y); 
        displayBoard(g); 
        free(currentPlayerString); 
    }
    char * p; 
    if (playerHasWon(n, g)) {
        p = getPlayerString(n); 
        printf("%s has won\n", p); 
    } else if (playerHasWon(c, g)) {
        p = getPlayerString(c); 
        printf("%s, has won\n", p); 
    } else {
        printf("Draw\n"); 
    }
    free(p); 
}

char *getPlayerString(Player p) {
    char *str; 
    if (p == Naught) {
        str = malloc(7);
        strcpy(str, "Naught"); 
    } else if (p == Cross) {
        str = malloc(6); 
        strcpy(str, "Cross"); 
    } else {
        str = NULL; 
    }
    return str; 
}