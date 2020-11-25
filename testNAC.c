#include <assert.h>
#include <stdio.h>

#include "NAC.h"

static void testGameIsOver(); 
static void testEnterMove(); 
static void testValidMove(); 
static void testNewGame(); 
static void testGetPlayerTurn(); 
static void testGetCoordState(); 
static void testGetEmptySlots(); 
static void testGetWinner(); 
static void testGameIsDraw(); 

int main() {
    testGameIsOver(); 
    testEnterMove(); 
    testValidMove(); 
    testNewGame(); 
    testGetPlayerTurn(); 
    testGetCoordState(); 
    testGetEmptySlots(); 
    testGetWinner(); 
    testGameIsDraw(); 
}

static void testGameIsOver() {
    printf("Testing gameIsOver...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    bool stop = false; 
    assert(gameIsOver(g) == false); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 2) && (j == 1)) {
                stop = true; 
                break; 
            }
            assert(gameIsOver(g) == false); 
            m.x = i; 
            m.y = j; 
            enterMove(g, m); 
        }
        if (stop) {
            break; 
        }
    }
    assert(gameIsOver(g) == true); 
    printf("gameIsOver tests passed!\n"); 
} 

static void testEnterMove() {
    printf("Testing enterMove...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    m.x = 0; 
    m.y = 0; 
    enterMove(g, m);
    assert(getCoordState(g, 0, 0) == c);
    printf("enterMove tests passed!\n"); 
} 

static void testValidMove() {
    printf("Testing validMove...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    m.x = 0; 
    m.y = 0; 
    assert(validMove(g, m) == true); 
    m.x = 1; 
    m.y = 2; 
    enterMove(g, m); 
    assert(validMove(g, m) == false); 
    printf("validMove tests passed!\n"); 
} 

static void testNewGame() {
    printf("Testing newGame...\n"); 
    Player p = Naught; 
    Game g = newGame(p); 
    assert(getPlayerTurn(g) == p); 
    assert(getEmptySlots(g) == tableSize*tableSize); 
    printf("newGame tests passed!\n"); 
} 

static void testGetPlayerTurn() {
    printf("Testing playerTurn...\n"); 
    Player n = Naught; 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    assert(getPlayerTurn(g) == c);
    m.x = 1; 
    m.y = 2; 
    enterMove(g, m); 
    assert(getPlayerTurn(g) == n);
    m.x = 2;
    m.y = 2;
    enterMove(g, m); 
    assert(getPlayerTurn(g) == c);
    printf("getPlayerTurn tests passed!\n"); 
} 

static void testGetCoordState() {
    printf("Testing getCoordState...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    m.x = 0; 
    m.y = 0; 
    assert(getCoordState(g, 0, 0) == -1);
    assert(getCoordState(g, 0, 1) == -1);
    enterMove(g, m);
    assert(getCoordState(g, 0, 0) == c);
    assert(getCoordState(g, 0, 1) == -1);
    printf("getCoordState tests passed!\n"); 
}

static void testGetEmptySlots() {
    printf("Testing getEmptySlots...\n"); 
    // empty slots when game initialised - should be number of squares
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    assert(getEmptySlots(g) == tableSize * tableSize);
    // empty slots when a move has made - should decrement by 1
    m.x = 0; 
    m.y = 0; 
    enterMove(g, m); 
    assert(getEmptySlots(g) == tableSize * tableSize - 1);
    printf("getEmptySlots tests passed!\n"); 
}

static void testGetWinner() {
    printf("Testing getWinner...\n"); 
    Player c = Cross; 
    Game g = newGame(c); 
    Move m; 
    bool stop = false; 
    assert(gameIsOver(g) == false); 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((i == 2) && (j == 1)) {
                stop = true; 
                break; 
            }
            assert(getWinner(g) == -1); 
            m.x = i; 
            m.y = j; 
            enterMove(g, m); 
        }
        if (stop) {
            break; 
        }
    }
    assert((getWinner(g) == Cross) || (getWinner(g) == Naught)); 
    printf("getWinner tests passed!\n"); 
}

static void testGameIsDraw() {
    printf("Testing gameIsDraw...\n"); 
    Player c = Naught; 
    Game g = newGame(c); 
    Move m; 
    assert(gameIsDraw(g) == false);
    m.x = 2;
    m.y = 0;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 0;
    m.y = 0;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 0;
    m.y = 1;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 0;
    m.y = 2;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 1;
    m.y = 1;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 1;
    m.y = 0;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 1;
    m.y = 2;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 2;
    m.y = 1;
    enterMove(g, m); 
    assert(gameIsDraw(g) == false);
    m.x = 2;
    m.y = 2;
    enterMove(g, m); 
    assert(gameIsDraw(g) == true);
    printf("gameIsDraw tests passed!\n"); 
}