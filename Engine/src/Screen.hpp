#pragma once

#include <ncurses.h>
#include "common.hpp"
#include "AScreen.hpp"

class Screen : public AScreen {
public:
    WINDOW *window;
    INTSIZE size;
    INTPOS startPoint;

public:
    Screen();
    Screen(AScreen *parentScreen);
    Screen(AScreen *parentScreen, INTSIZE &size);
    Screen(AScreen *parentScreen, INTSIZE &size, INTPOS &relativeStartPoint);
    virtual ~Screen();
    
    virtual void Tick() override;
    virtual void Draw() override;
    virtual void UpdateScreen() override;
    virtual void ClearScreen() override;

    static void UpdateAllScreen();
    static void ClearAllScreen();
    static WINDOW *CreateNewWindow(INTSIZE &size, INTPOS &startPoint);
    static void DestroyWindow(WINDOW *local_win);
};