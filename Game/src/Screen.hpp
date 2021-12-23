#pragma once

#include <ncurses.h>
#include <vector>
#include "Common.hpp"

class Screen
{
public:
    WINDOW *window;
    INTSIZE size;
    INTPOS startPoint;
    std::vector<Screen *> subScreens;

public:
    Screen();
    Screen(Screen *parentScreen);
    Screen(Screen *parentScreen, INTSIZE &size);
    Screen(Screen *parentScreen, INTSIZE &size, INTPOS &relativeStartPoint);
    virtual ~Screen();

    virtual void Tick();
    virtual void Draw();
    virtual void UpdateScreen();
    virtual void EraseScreen();
    virtual void PushSubScreen(Screen *subScreen);

    static void UpdateAllScreen();
    static void EraseAllScreen();
    static WINDOW *CreateNewWindow(INTSIZE &size, INTPOS &startPoint);
    static void DestroyWindow(WINDOW *local_win);
};