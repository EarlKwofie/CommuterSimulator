#ifndef MAP_H
#define MAP_H

#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

void drawMap(int,int,int,int);
void setPlayer(int,int);
int getNodeCoordinate(int);
int getPlayerStartX();
int getPlayerStartY();
int isAvailable(int,int);
int atWork(char);
//int checkWin();

#endif /*MAP_H*/
