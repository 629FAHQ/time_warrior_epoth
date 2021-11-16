#include <ncurses.h>

#include "Controller.hpp"

void Controller::InitializeController()
{
    noecho();
    nodelay(stdscr, TRUE); // Get input as negative value...
    keypad(stdscr, TRUE);
}

bool Controller::IsKeyHit() 
{
    return GetPressedKey() != ERR;
}

void Controller::UpdateController()
{
    currentKey = getch();
}