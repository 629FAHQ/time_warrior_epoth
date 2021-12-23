#pragma once

#include <ncurses.h>

#include "Controller.hpp"

class Controller
{
public:
    int currentKey;
    enum EKey
    {
        NO_INPUT = ERR,
    };

public:
    void InitializeController();
    bool IsKeyHit();
    void UpdateController();

    inline int GetPressedKey() { return currentKey; };
};