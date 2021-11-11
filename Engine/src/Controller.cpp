#include <ncurses.h>

#include "Controller.hpp"

void Controller::InitializeController()
{
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
}

bool Controller::IsKeyHit() 
{
    int ch = getch();
    
    if (ch != ERR) {
        ungetch(ch);
        return TRUE;
    } else {
        return FALSE;
    }
    
}

void Controller::UpdateController()
{
    currentKey = getch();
}