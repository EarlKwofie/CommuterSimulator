#include "map.h"

#define MP_ROWS 3
#define MP_COLS 3
#define MP_ROADWIDTH 2
#define MP_BLOCKWIDTH 3

#define BACKGROUND ' '
#define BORDER '#'

WINDOW *gameScreen;

bool isAvailable(int,int);

int main(void)
{
    initscr();
    cbreak();
    keypad(stdscr,TRUE);
    noecho();
    
    clear();
         
    gameScreen = newwin(100,100,0,0);    
        
    setMap(MP_BLOCKWIDTH,MP_ROADWIDTH,MP_ROWS,MP_COLS);
    refresh();

    int ch;
    int x = 0;
    int y = 0;
    int time = 0;
      
    do
    {
        mvaddch(y, x, BORDER);
        move(y, x);
        refresh();

        ch = getch();
        switch (ch) 
        {
        case KEY_UP:
        case 'w':
        case 'W':
            if ((y > 0) && isAvailable(y - 1, x)) 
            {
                attron(COLOR_PAIR(2));
                mvaddch(y, x, BACKGROUND);
                attroff(COLOR_PAIR(2));
                y = y - 1;
            }
            break;
        case KEY_DOWN:
        case 's':
        case 'S':
            if ((y < getBoundaryY() - 1) && isAvailable(y + 1, x)) 
            {
                attron(COLOR_PAIR(2));
                mvaddch(y, x, BACKGROUND);
                attroff(COLOR_PAIR(2));
                y = y + 1;
            }   
            break;
        case KEY_LEFT:
        case 'a':
        case 'A':
            if ((x > 0) && isAvailable(y, x - 1)) {
            attron(COLOR_PAIR(2));
            mvaddch(y, x, BACKGROUND);
            attroff(COLOR_PAIR(2));
            x = x - 1;
            }
            break;
        case KEY_RIGHT:
        case 'd':
        case 'D':
            if ((x < getBoundaryX()) && isAvailable(y, x + 1)) {
            attron(COLOR_PAIR(2));
            mvaddch(y, x, BACKGROUND);
            attroff(COLOR_PAIR(2));
            x = x + 1;
            }
            break;
        }

        time++;
        attron(COLOR_PAIR(1));
        mvprintw(getBoundaryY() + 2, 0, "Time Allotted: %d", time);
        attroff(COLOR_PAIR(1));
    }while((ch != 'q') && (ch !='Q'));
  
    endwin();
}
