#include <stdio.h>
#include <stdlib.h>

#include "NAC.h"

#ifndef NACVIEW_h
#define NACVIEW_H 

void displayBoard(Game g); 
bool getMove(Player p, Move *m); 
void getPlayerString(Player p, char *str); 
void showInvalidMoveError(); 
void showEndGameMsg(Game g);

#endif
