#pragma once

#include <ncurses.h>

class AController
{
public:
    int currentKey;

public:
    AController();
    virtual ~AController();
    virtual void InitializeController() = 0;
    virtual void UpdateController() = 0;
    virtual bool IsKeyHit() = 0;

    inline int GetPressedKey() { return currentKey; };
};