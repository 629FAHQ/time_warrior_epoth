#include "AScreen.hpp"


AScreen::AScreen()
{

}

AScreen::~AScreen()
{

}

void AScreen::Tick()
{
    EraseScreen();
    Draw();
    
    for(AScreen *subScreen: subScreens)
    {
        subScreen->Tick();
    }

    UpdateScreen();
}

void AScreen::PushSubScreen(AScreen *subScreen)
{
    this->subScreens.push_back(subScreen);
}
