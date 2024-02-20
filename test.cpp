#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int main()
{
    const int WindowWidth = 1500;
    const int WindowHeight = 800;
    RenderWindow window(VideoMode(WindowWidth, WindowHeight), "SFML");

    Texture texture;
    Text text;
    Font font;
    Vector2 position(0.f, 0.f);

    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

    if (!texture.loadFromFile("./images/peter5.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);

    float scaleX = (0.15f * WindowWidth) / sprite.getTexture()->getSize().x;
    float scaleY = (0.8f * WindowHeight) / sprite.getTexture()->getSize().y;
    sprite.setScale(scaleX, scaleY);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        int x = sprite.getTexture()->getSize().x;
        position.x = (WindowWidth - x / 4);
        position.y = WindowHeight / 5;
        sprite.setPosition(position);

        if (!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
            return EXIT_FAILURE;
        text.setFont(font);
        text.setString("Guess the Word!");
        text.setFillColor(Color::White);
        text.setPosition(WindowWidth / 2, WindowHeight / 2);
        // text.setCharacterSize();
        text.setStyle(Text::Bold);
        text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);
        window.clear();

        window.draw(text);
        window.draw(sprite);

        window.display();
    }
}