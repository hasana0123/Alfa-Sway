#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button
{
public:
    float boxWidth, boxHeight, boxPositionX, boxPositionY, textPositionX, textPositionY, textCharacterSize;
    Color boxFillColor, boxOutlineColor, textFillColor;
    string inText;
    bool isActive;

    void setPosition(float, float);
    void setBoxSize(float, float);
    void setTextSize(float);
    void setBoxColor(Color, Color);
    void setTextColor(Color);
    void setText(string);
    void Activate();
    void Deactivate();
};

void Button::setBoxSize(float width, float height)
{
    this->boxWidth = width;
    this->boxHeight = height;
}

void Button::setTextSize(float size)
{
    this->textCharacterSize = size;
}

void Button::setPosition(float x, float y)
{

    this->boxPositionX = x;
    this->boxPositionY = y;
    this->textPositionX = x+35;
    this->textPositionY = y + 17.5;
}

void Button::setBoxColor(Color fill, Color Outline)
{
    this->boxFillColor = fill;
    this->boxOutlineColor = Outline;
}

void Button::setTextColor(Color fill)
{
    this->textFillColor = fill;
}

void Button::setText(string text)
{
    Font font;
    if (!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
        return;
    this->inText = text;
}

void Button::Activate()
{
    this->isActive = true;
}

void Button::Deactivate()
{
    this->isActive = false;
}