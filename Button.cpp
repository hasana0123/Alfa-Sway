#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Button
{
    float boxWidth, boxHeight, boxPositionX, boxPositionY, textPositionX, textPositionY, textCharacterSize;
    Color boxFillColor, boxOutlineColor, textFillColor;
    string inText;
    bool isActive;

public:
    void setPosition(float, float);
    void setBoxSize(float, float);
    void setTextSize(float);
    void setColor();
    void setText();
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
    this->textPositionX;
    // cats[i].setPosition(choices[i].getPosition().x,
    //                                     choices[i].getPosition().y);
}