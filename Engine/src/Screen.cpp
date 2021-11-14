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

    DestroyWindow(window);

}


void Screen::Tick()
{

    // ** AScreen::Tick() have to be called at the end of this method. **
    AScreen::Tick();
}

void Screen::Draw()
{
    box(window, 0, 0);
    AController* controller = Engine::GetCurrentGame()->controller;
    Controller *castedController = dynamic_cast<Controller*>(controller);
    mvprintw(0, 0, "%d", window);

    int key = controller->GetPressedKey();
    mvwprintw(window, 0, 0, "pressed key: %3d", key);
    
    if(controller->IsKeyHit())
    {
        mvwprintw(window, 1, 0, "pressed!");
    }else{
        mvwprintw(window, 1, 0, "pressed!");
    }

    UpdateAllScreen();
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

void Screen::ClearScreen()
{
    wclear(window);
}

void Screen::ClearAllScreen()
{
    clear();
}