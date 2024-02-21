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
    RectangleShape button1(Vector2f(150.f, 80.f));
    RectangleShape button2(Vector2f(150.f, 80.f));
    Text text, play, quit;
    Font font;
    Event event2;
    Vector2 position(0.f, 0.f);

    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

    // Sprite for hanging peter
    if (!texture.loadFromFile("./images/peter1.png"))
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

        // text guess the word
        if (!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
            return EXIT_FAILURE;
        text.setFont(font);
        text.setString("LESGOOO!");
        text.setFillColor(Color::White);
        text.setPosition(WindowWidth / 3.5, WindowHeight / 6);
        text.setCharacterSize(50);
        text.setStyle(Text::Bold);
        text.setOrigin(text.getLocalBounds().width / 2.f, text.getLocalBounds().height / 2.f);

        button1.setFillColor(Color(87, 146, 21));
        button1.setOutlineThickness(15.f);
        button1.setOutlineColor(Color(28, 222, 90));
        button1.setPosition(WindowWidth / 5, WindowHeight / 2);
        button1.setOrigin(button1.getLocalBounds().width / 2.f, button1.getLocalBounds().height / 2.f);

        play.setFont(font);
        play.setString("PLAY");
        play.setFillColor(Color(240, 247, 180));

        FloatRect textRect1 = play.getLocalBounds();
        play.setOrigin(textRect1.left + textRect1.width / 1.5f,
                       textRect1.top + textRect1.height / 0.85f);
        play.setPosition(button1.getPosition().x,
                         button1.getPosition().y);

        button2.setFillColor(Color(213, 97, 59));
        button2.setOutlineThickness(15.f);
        button2.setOutlineColor(Color(250, 142, 84));
        button2.setPosition(WindowWidth / 2.5, WindowHeight / 2);
        button2.setOrigin(button1.getLocalBounds().width / 2.f, button1.getLocalBounds().height / 2.f);

        quit.setFont(font);
        quit.setString("QUIT");
        quit.setFillColor(Color(240, 247, 180));

        FloatRect textRect2 = quit.getLocalBounds();
        quit.setOrigin(textRect2.left + textRect2.width / 1.5f,
                       textRect2.top + textRect2.height / 0.85f);
        quit.setPosition(button2.getPosition().x,
                         button2.getPosition().y);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            // left key is pressed: move our character
            play.move(-1.f, 0.f);
            play.setFillColor(Color::Yellow);

            button1.setOutlineColor(Color(80, 252, 25));
            if (Keyboard::isKeyPressed(Keyboard::Scan::Enter))
                texture.loadFromFile("./images/peter5.png");
            sprite.setTexture(texture);
            sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right))
        {
            // right key is pressed: move our character
            quit.move(1.f, 0.f);
            quit.setFillColor(Color::Yellow);
            button2.setOutlineColor(Color(255, 19, 0));
            if (Keyboard::isKeyPressed(Keyboard::Scan::Enter))
                window.close();
        }
        window.clear();

        window.draw(text);
        window.draw(sprite);
        window.draw(button1);
        window.draw(play);
        window.draw(button2);
        window.draw(quit);

        window.display();
    }
}