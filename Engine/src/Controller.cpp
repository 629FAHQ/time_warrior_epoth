#include <ncurses.h>

#include "Controller.hpp"

void Controller::InitializeController()
{
    noecho();
    // nodelay(stdscr, TRUE); // Get input as negative value...
    keypad(stdscr, TRUE);
}

bool Controller::IsKeyHit() 
{
    int ch = GetPressedKey();
    if (ch != ERR) {
        return TRUE;
    } else {
        return FALSE;
    }
    
}

void Controller::UpdateController()
{
    currentKey = getch();
}