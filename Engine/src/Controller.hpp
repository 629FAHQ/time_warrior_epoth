#pragma once

#include <ncurses.h>

#include "AController.hpp"


class Controller : public AController {
public:
    enum EKey {
        NO_INPUT=ERR,
    };
public:
    void InitializeController() override;
    bool IsKeyHit() override;
    void UpdateController() override;
};