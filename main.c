#include "map.h"

int main(void)
{
    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    
    drawMap(7,2,5,5);
    setPlayer(5,5);
    refresh();
    
    int x = getPlayerStartX();
    int y = getPlayerStartY();
    int ch;
    
    do
    {
        move(y,x);
        refresh();
        ch = getch();
        
        switch(ch)
        {
            case KEY_UP:
                case 'w':
                case 'W':
                    if( y > 0 && isAvailable(--y,x) == 0);
                    {
                         mvaddch(y,x,' ');
                         y--;        
                    }
                    break;
           
             case KEY_DOWN:
                case 's':
                case 'S':
                    if( (y < LINES - 1) && isAvailable(++y,x) == 0)
                    { 
                          mvaddch(y,x,' ');
                          y++; 
                    }
                    break;
             
              case KEY_RIGHT:
                 case 'd':
                 case 'D':
                     if((x < COLS - 1) && isAvailable(y, ++x) == 0)
                     {
                            mvaddch(y,x,' ');
                            x++;
                     }
                     break;
               
                case KEY_LEFT:
                   case 'a':
                   case 'A':
                       if((x > 0) && isAvailable(y, --x) == 0)
                       {
                              mvaddch(y,x,' ');
                              x--;
                        }
                        break;
            }
        }while( ch != 'q' || ch != 'Q' );          
    
    drawMap(7,2,5,5);
    setPlayer(5,5);
    refresh();
    getch();
    
    endwin();
}
