#include <iostream>
#include <json/json.h>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include "Game.cpp"

using namespace std;
using namespace Json;


int main()
{
    Game game;
    game.showInitialPage();
    return 0;
}