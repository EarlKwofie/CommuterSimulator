#include "map.h"

#define MP_ROWS 5
#define MP_COLS 5
#define MP_BLOCKSIZE 7
#define MP_ROADSIZE 2

int main(void)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    
    clear();
    
    drawMap(MP_BLOCKSIZE,MP_ROADSIZE,MP_ROWS,MP_COLS);
    setPlayer(MP_ROWS,MP_COLS);
    
    
    int max_X = (MP_COLS * MP_BLOCKSIZE) + ((1 + MP_COLS)*(MP_ROADSIZE));
    int max_Y = (MP_ROWS * MP_BLOCKSIZE) + ((1 + MP_ROWS)*(MP_ROADSIZE)); 
    int x = getPlayerStartX();
    int y = getPlayerStartY();
    int ch;


 //Still working on player movement   
 /*   do
    {
        move(y,x);
       
        refresh();
        ch = getch();
        
        switch(ch)
        {
            case KEY_UP:
                case 'w':
                case 'W':
                    if( y > 0 && isAvailable(y - 1,x) == 1);
                    {
                         mvaddch(y,x,' ');
                         y = y - 1;        
                    }
                    break;
           
             case KEY_DOWN:
                case 's':
                case 'S':
                    if( (y < max_Y- 1) && isAvailable(y + 1,x) == 1)
                    { 
                          mvaddch(y,x,' ');
                          y = y + 1; 
                    }
                    break;
             
              case KEY_RIGHT:
                 case 'd':
                 case 'D':
                     if((x < max_X - 1) && isAvailable(y, x + 1) == 1)
                     {
                            mvaddch(y,x,' ');
                            x = x + 1;
                     }
                     break;
               
                case KEY_LEFT:
                   case 'a':
                   case 'A':
                       if((x > 0) && isAvailable(y, x - 1) == 1)
                       {
                              mvaddch(y,x,' ');
                              x = x - 1;
                        }
                        break;
            }
        }while( ch != 'q' || ch != 'Q' );  */  

      
     getch(); 
     //Next Map
     clear();
     drawMap(MP_BLOCKSIZE,MP_ROADSIZE,MP_ROWS,MP_COLS);
     setPlayer(MP_ROWS,MP_COLS);
     
     getch();
     //Next Map
     clear();
     drawMap(MP_BLOCKSIZE,MP_ROADSIZE,MP_ROWS,MP_COLS);
     setPlayer(MP_ROWS,MP_COLS);
        
     getch();  
     endwin();
}
