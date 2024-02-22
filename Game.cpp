#include <iostream>
#include <SFML/Graphics.hpp>
#include "Button.cpp"

using namespace std;
using namespace sf;

class Game
{
   float WindowWidth=1500.f,WindowHeight=800.f;
public:
    void play();
    void quit();
};

void Game::play()
{
    Button play,quit;
    RenderWindow window(VideoMode(this->WindowWidth,this->WindowWidth),"Alfa-Sway");
    while (window.isOpen())
    {

    }
}

void showInitialPage()
{

}