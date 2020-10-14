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
    
    printf("enterMove tests passed!\n"); 
} 

static void testGetMove() {
    printf("Testing getMove...\n"); 

    printf("getMove tests passed!\n"); 
} 

static void testValidMove() {
    printf("Testing validMove...\n"); 

    printf("validMove tests passed!\n"); 
} 

static void testPlayersTurn() {
    printf("Testing playersTurn...\n"); 

    printf("playersTurn tests passed!\n"); 
} 

static void testGameIsOver() {
    printf("Testing gameIsOver...\n"); 

    printf("gameIsOver tests passed!\n"); 
} 

static void testPlayerHasWon() {
    printf("Testing playerHasWon...\n"); 

    printf("playerHasWon tests passed!\n"); 
} 
