#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML");

    Texture texture;
    if (!texture.loadFromFile("./images/peter5.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
     float scaleX = 200.0f / sprite.getTexture()->getSize().x;
    float scaleY = 500.0f / sprite.getTexture()->getSize().y;
    sprite.setScale(scaleX, scaleY);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();

        window.draw(sprite);

        window.display();
    }
}