#include <ctime>
#include <ncurses.h>

#include "Screen.hpp"

#include "Common.hpp"
#include "Engine.hpp"
#include "Game.hpp"
#include "Controller.hpp"

Screen::Screen()
{
    size = INTSIZE(MAX_HEIGHT, MAX_WIDTH);
    startPoint = INTPOS(0, 0);

    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(Screen *parentScreen)
{
    parentScreen->PushSubScreen(this);

    size = parentScreen->size;
    startPoint = parentScreen->startPoint;
    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(Screen *parentScreen, INTSIZE &size)
    : size(size)
{
    parentScreen->PushSubScreen(this);

    startPoint = parentScreen->startPoint;
    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(Screen *parentScreen, INTSIZE &size, INTPOS &relativeStartPoint)
    : size(size)
{
    parentScreen->PushSubScreen(this);

    startPoint = parentScreen->startPoint + relativeStartPoint;
}

Screen::~Screen()
{
    while (!subScreens.empty())
    {
        Screen *subScreen = subScreens.back();
        SAFE_DELETE(subScreen);
        subScreens.pop_back();
    }

    if (window)
    {
        DestroyWindow(window);
    }
}

void Screen::Tick()
{
    EraseScreen();
    Draw();

    for (Screen *subScreen : subScreens)
    {
        subScreen->Tick();
    }

    UpdateScreen();
}

void Screen::Draw()
{
    box(window, 0, 0);
    Game *game = (Game *)Engine::GetCurrentGame();
    Controller *controller = game->controller;

    time_t playedClock = game->GetPlayedClock();
    double playedTime = game->GetPlayedTime();
    double deltaTime = game->GetDeltaTime();
    mvwprintw(window, 3, 0, "playedClock: %d", playedClock);
    mvwprintw(window, 4, 0, "playedTime: %f", playedTime);
    mvwprintw(window, 5, 0, "deltaTime: %f", deltaTime);

    int key = controller->GetPressedKey();
    mvwprintw(window, 1, 0, "pressed key: %3d", key);

    if (controller->IsKeyHit())
    {
        mvwprintw(window, 2, 0, "pressed!");
    }
    else
    {
        mvwprintw(window, 2, 0, "not pressed!");
    }
}

void Screen::UpdateScreen()
{
    wrefresh(window);
}

void Screen::UpdateAllScreen()
{
    refresh();
}

WINDOW *Screen::CreateNewWindow(INTSIZE &size, INTPOS &startPoint)
{
    WINDOW *_window;

    _window = newwin(size.height, size.width, startPoint.y, startPoint.x);

    return _window;
}

void Screen::DestroyWindow(WINDOW *window)
{
    wborder(window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    delwin(window);
}

void Screen::EraseScreen()
{
    werase(window);
}

void Screen::EraseAllScreen()
{
    erase();
}

void Screen::PushSubScreen(Screen *subScreen)
{
    this->subScreens.push_back(subScreen);
}