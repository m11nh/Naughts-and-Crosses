#include <assert.h>
#include <stdio.h>

#include "NAC.h"

static void testNewGame(); 
static void testEnterMove(); 
static void testGetMove(); 
static void testValidMove(); 
static void testPlayersTurn(); 
static void testGameIsOver(); 
static void testPlayerHasWon(); 

int main() {
    testNewGame(); 
    testEnterMove(); 
    testGetMove(); 
    testValidMove(); 
    testPlayersTurn(); 
    testGameIsOver(); 
    testPlayerHasWon(); 
}

static void testNewGame() {
    printf("Testing newGame...\n"); 
    Player p = Naught; 
    Game g = newGame(p); 
    assert(getPlayerTurn(g) == p); 
    assert(getEmptySlots(g) == tableSize*tableSize); 
    printf("newGame tests passed!\n"); 
} 

static void testEnterMove() {
    printf("Testing enterMove...\n"); 
    Player n = Naught; 
    Player c = Cross; 
    Game g = newGame(c); 
    enterMove(g, c, 1, 1); 
    assert(getMove(g, 1, 1) == c);
    enterMove(g, n, 1, 2); 
    assert(getMove(g, 1, 2) == n); 
    assert(getMove(g, 0, 0) == -1); 
    printf("enterMove tests passed!\n"); 
} 

static void testGetMove() {
    printf("Testing getMove...\n"); 
    Player n = Naught; 
    Player c = Cross; 
    Game g = newGame(c); 
    enterMove(g, c, 1, 1); 
    assert(getMove(g, 1, 1) == c);
    enterMove(g, n, 1, 2); 
    assert(getMove(g, 1, 2) == n); 
    assert(getMove(g, 0, 0) == -1); 
    printf("getMove tests passed!\n"); 
} 

static void testValidMove() {
    printf("Testing validMove...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    assert(validMove(g, 0, 0) == true); 
    enterMove(g, c, 1, 2); 
    assert(validMove(g, 1, 2) == false); 
    printf("validMove tests passed!\n"); 
} 

static void testPlayersTurn() {
    printf("Testing playersTurn...\n"); 
    Player n = Naught; 
    Player c = Cross; 
    Game g = newGame(c); 
    assert(getPlayerTurn(g) == c);
    enterMove(g, c, 1, 2); 
    assert(getPlayerTurn(g) == n);
    enterMove(g, n, 1, 2); 
    assert(getPlayerTurn(g) == c);
    printf("playersTurn tests passed!\n"); 
} 

static void testGameIsOver() {
    printf("Testing gameIsOver...\n"); 
    Player c = Cross; 
    Player n = Naught; 
    Player turn = c; 
    Game g = newGame(c); 
    assert(gameIsOver(g) == false); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            assert(gameIsOver(g) == false); 
            enterMove(g, turn, i, j); 
            turn = (turn == c) ? n : c; 
        }
    }
    assert(gameIsOver(g) == true); 
    printf("gameIsOver tests passed!\n"); 
} 

static void testPlayerHasWon() {
    printf("Testing playerHasWon...\n"); 
    Player n = Naught; 
    Player c = Cross; 
    Game g = newGame(n); 

    // vert case
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 0, 0); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 1, 0); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 0, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 1, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 0, 2); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 2, 0); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 

    endGame(g); 
    g = newGame(n); 

    // horiz case
    enterMove(g, n, 0, 2); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 0, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 1, 2); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 1, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 2, 2); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 1, 0); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 

    endGame(g); 
    g = newGame(n); 

    // diagonal case
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 0, 0); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 0, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 1, 1); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 1, 0); 
    assert(playerHasWon(n, g) == false); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, n, 2, 2); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 
    enterMove(g, c, 0, 2); 
    assert(playerHasWon(n, g) == true); 
    assert(playerHasWon(c, g) == false); 

    endGame(g); 
    printf("playerHasWon tests passed!\n"); 
} 
