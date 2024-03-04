#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Images
{
public:
    Texture texture, texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8;
    Sprite sprite;

    void returnImage(int &, int, int);
};

void Images::returnImage(int &life, int winflag, int correct)
{

    if (!this->texture1.loadFromFile("./images/peter1.png"))
        return;
    if (!this->texture2.loadFromFile("./images/peter2.png"))
        return;
    if (!this->texture3.loadFromFile("./images/peter3.png"))
        return;
    if (!this->texture4.loadFromFile("./images/peter5.png"))
        return;
    if (!this->texture5.loadFromFile("./images/peter4.png"))
        return;
    if (!this->texture6.loadFromFile("./images/peter6.png"))
        return;
    if (!this->texture7.loadFromFile("./images/peter7.png"))
        return;
    if (!this->texture8.loadFromFile("./images/peter8.png"))
        return;
    if (correct == 0)
    {
        if (winflag == 0)
        {
            switch (life)
            {
            case 1:
                texture = texture5;

                break;
            case 2:
                texture = texture4;

                break;
            case 3:
                texture = texture3;

                break;
            case 4:
                texture = texture7;

                break;
            case 5:
                texture = texture1;
                break;
            default:
                break;
            }
        }
    }
    else
        texture = texture2;
    if (winflag == 1)
        texture = texture8;
    if (winflag == 0 && life == 0)
        texture = texture6;
    this->sprite.setTexture(texture);
}