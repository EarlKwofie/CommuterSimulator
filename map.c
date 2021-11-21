#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <math.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 50
#define PATH ' '
#define BOUNDARY '~'
#define PLAYER 'P'
#define WORK 'W'

struct Point{
    int x,y;
};

struct Point origin, bounds, playerLocation, workLocation;
int spacing, mp_border, mp_block;

/*
    Generates a the map by which the player moves around
 */
void drawMap(int blockWidth, int roadWidth, int blocks_row, int blocks_col)
{
    
    int tempGrid[blocks_row][blocks_col];
    int x,y;
    
    //determines intermediate space between the center points of each block
    int btwn_top = round(blockWidth/2) + roadWidth;
    int btwn = roadWidth + blockWidth;
    
    mp_border = btwn_top;
    spacing = btwn;
    mp_block = blockWidth;

    //determines center point of the blocks within the bounds of the map
    int max_width = btwn_top + ((blocks_col - 1) * btwn);
    int max_height = btwn_top + ((blocks_row - 1) * btwn); 

    //creates a series of blocks representing the city blocks
    for(int i = btwn_top; i <= max_width; i+=btwn)
    {
        for(int j = btwn_top; j <= max_height; j+=btwn)
        {
           for(int k = 0; k < blockWidth; k++)
                { mvvline(i-round(blockWidth/2),j-round(blockWidth/2)+k,BOUNDARY,blockWidth);}        
        }
    }
    
    //determining the coordinates of the 2 most outer spawn points
    origin.x = btwn_top;
    origin.y = btwn_top;
    
    
    bounds.x = max_width;
    bounds.y = max_height;
}

//Determines a random location to place the player on the map
void setPlayer(int blocks_row, int blocks_col)
{
    
    playerLocation.y = rand() % blocks_row;
    playerLocation.x = rand() % blocks_col;
    
        do
        {

            workLocation.x = rand() % blocks_row;
            workLocation.y = rand() % blocks_col;

        }while(playerLocation.y == workLocation.y && playerLocation.x == workLocation.x);
     
    mvvline(getNodeCoordinate(playerLocation.y)-1, getNodeCoordinate(playerLocation.x), PATH, round(mp_block/2) + 2);
    mvvline(getNodeCoordinate(playerLocation.y)-1, getNodeCoordinate(playerLocation.x)-1, PATH, round(mp_block/2));
    mvvline(getNodeCoordinate(playerLocation.y)-1, getNodeCoordinate(playerLocation.x)+1, PATH, round(mp_block/2));
    mvaddch(getNodeCoordinate(playerLocation.y), getNodeCoordinate(playerLocation.x), PLAYER);
    
    mvvline(getNodeCoordinate(workLocation.y)-1, getNodeCoordinate(workLocation.x), PATH, round(mp_block/2) + 2);
    mvvline(getNodeCoordinate(workLocation.y)-1, getNodeCoordinate(workLocation.x)-1, PATH, round(mp_block/2));
    mvvline(getNodeCoordinate(workLocation.y)-1, getNodeCoordinate(workLocation.x)+1, PATH, round(mp_block/2));
    mvaddch(getNodeCoordinate(workLocation.y), getNodeCoordinate(workLocation.x), WORK);
}


int getNodeCoordinate(int coordinate)
{
    return (mp_border + (coordinate * spacing)); 
}

//returns the location of the player, primarily for the initial position
int getPlayerStartX()
{
    return getNodeCoordinate(playerLocation.x);
}

//returns the location of the player, primarily for the initial position
int getPlayerStartY()
{
    return getNodeCoordinate(playerLocation.y);
}

/*
    Checks if the player can move on to the space given
*/
int isAvailable(int x, int y) 
{
   int test = mvinch(y,x);
   return ( test == BOUNDARY );
}
