#pragma once

#include <vector>
#include <ncurses.h>


class AScreen {
public:
    std::vector<AScreen *> subScreens;
    
public:
    AScreen();
    virtual ~AScreen();
    virtual void Tick();
    virtual void Draw() = 0;
    virtual void UpdateScreen() = 0;
    virtual void EraseScreen() = 0;

    void PushSubScreen(AScreen * subScreen);
};