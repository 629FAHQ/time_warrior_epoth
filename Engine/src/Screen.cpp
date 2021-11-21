#include <ctime>
#include <ncurses.h>

#include "Screen.hpp"

#include "common.hpp"
#include "Engine.hpp"
#include "Game.hpp"
#include "Controller.hpp"


Screen::Screen()
{
    size = INTSIZE(MAX_HEIGHT, MAX_WIDTH);
    startPoint = INTPOS(0, 0);

    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(AScreen *parentScreen)
{
    parentScreen->PushSubScreen(parentScreen);
    
    const Screen *castedParentScreen = dynamic_cast<Screen *>(parentScreen);

    size = castedParentScreen->size;
    startPoint = castedParentScreen->startPoint;
    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(AScreen *parentScreen, INTSIZE& size)
:size(size)
{
    parentScreen->PushSubScreen(parentScreen);
 
    const Screen *castedParentScreen = dynamic_cast<Screen *>(parentScreen);
    
    startPoint = castedParentScreen->startPoint;
    window = CreateNewWindow(size, startPoint);
}

Screen::Screen(AScreen *parentScreen, INTSIZE &size, INTPOS &relativeStartPoint)
:size(size)
{
    parentScreen->PushSubScreen(parentScreen);

    const Screen *castedParentScreen = dynamic_cast<Screen *>(parentScreen);
    
    startPoint = castedParentScreen->startPoint + relativeStartPoint;
}

Screen::~Screen()
{
    while(!subScreens.empty())
    {
        AScreen *subScreen = subScreens.back();
        SAFE_DELETE(subScreen);
        subScreens.pop_back();
    }

    if(window)
    {
        DestroyWindow(window);
    }
}


void Screen::Tick()
{

    // ** AScreen::Tick() have to be called at the end of this method. **
    AScreen::Tick();
}

void Screen::Draw()
{
    box(window, 0, 0);
    Game* game = (Game *) Engine::GetCurrentGame();
    AController* controller = game->controller;

    time_t playedClock = game->GetPlayedClock();
    double playedTime = game->GetPlayedTime();
    double deltaTime = game->GetDeltaTime();
    mvwprintw(window, 3, 0, "playedClock: %d", playedClock);
    mvwprintw(window, 4, 0, "playedTime: %f", playedTime);
    mvwprintw(window, 5, 0, "deltaTime: %f", deltaTime);

    int key = controller->GetPressedKey();
    mvwprintw(window, 1, 0, "pressed key: %3d", key);

     
    if(controller->IsKeyHit())
    {
        mvwprintw(window, 2, 0, "pressed!");
    }else{
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
	wborder(window, ' ', ' ', ' ',' ',' ',' ',' ',' ');
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