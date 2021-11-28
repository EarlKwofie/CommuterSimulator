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
} origin, bounds, playerLocation, workLocation;

int spacing, mp_border, mp_block, mp_max_x, mp_max_y, mp_rows, mp_cols;

/*
    Generates a the gridded map for the user, and calculates its size
        block_width - size of square grid modules (blocks)
        road_width - space between blocks
        blocks_row - amount of blocks in a row
        blocks_column - amount of blocks in a column    
        
 */

void drawMap(int blockWidth, int roadWidth, int blocks_row, int blocks_col)
{   
   
    //determines intermediate space between the center points of each block
    int btwn_top = round(blockWidth/2) + roadWidth;
    
    //assigning map values to external variables within the file
    mp_border = btwn_top;
    mp_block = blockWidth;
    mp_rows = blocks_row;
    mp_cols = blocks_col;
    spacing = roadWidth + blockWidth;
    
    
    //determines the outermost spawn points for the user
    bounds.x = btwn_top + ((mp_cols - 1) * spacing);
    bounds.y = btwn_top + ((mp_rows - 1) * spacing); 
    origin.x = btwn_top; 
    origin.y = btwn_top;
   
     
    //determines the outermost boundary of play space
    mp_max_x = (spacing * blocks_col) + roadWidth;
    mp_max_y = (spacing * blocks_row) + roadWidth;

    WINDOW *gameWin;
    gameWin = newwin(mp_max_y, mp_max_x, 0, 0);
     
    //creates a series of blocks representing the city blocks
    for(int i = mp_border; i <= bounds.x; i+=spacing)
    {
        for(int j = mp_border; j <= bounds.y; j+=spacing)
        {
           for(int k = 0; k < mp_block; k++)
                { mvvline(i-round(mp_block/2),j-round(mp_block/2)+k,BOUNDARY,mp_block);}        
        }
    }

    wrefresh(gameWin);    
}

/*
    Determines a random location to place the player on the map
    Also determines the user destination, or the place the player works
*/
void setPlayer()
{
    
    playerLocation.y = rand() % mp_rows;
    playerLocation.x = rand() % mp_cols;
    
        do
        {

            workLocation.x = rand() % mp_rows;
            workLocation.y = rand() % mp_cols;

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



int atWork(char space)
{
    return (space == 'W');
}

int getNodeCoordinate(int coordinate)
{
    return (mp_border + (coordinate * spacing)); 
}

/*
    Returns the location of the player, primarily for the initial position
*/
int getPlayerStartX()
{
    return getNodeCoordinate(playerLocation.x);
}

/*
    Returns the location of the player, primarily for the initial position
*/
int getPlayerStartY()
{
    return getNodeCoordinate(playerLocation.y);
}

/*
    Checks if the player can move on to the space given
*/
int isAvailable(int x, int y) 
{   
   char test;   
 
   test = mvinch(y,x);
   return ( test == PATH );
}

/*
   Gives you the X maximum boundary  
*/
int getBoundaryX()
{
    return mp_max_x;
}

/*
    Gives you the Y maximum boundary
*/
int getBoundaryY()
{
    return mp_max_y;
}
