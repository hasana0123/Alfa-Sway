#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

RectangleShape
    choice1(Vector2f(180.f, 100.f)),
    choice2(Vector2f(180.f, 100.f)), choice3(Vector2f(180.f, 100.f)), choice4(Vector2f(180.f, 100.f));
RectangleShape choices[4] = {choice1, choice2, choice3, choice4};
Text text, play, quit, places, series, cartoons, movies;
Text cats[4] = {places, series, cartoons, movies};
RectangleShape selectMenu(int catsActive, RectangleShape button4)
{
    cout << catsActive << endl;
    cout << button4.getPosition().x << endl;
    switch (catsActive)
    {
    case 0:

        button4.setPosition(choices[0].getPosition().x / 1.58,
                            choices[0].getPosition().y / 1.23);
        cats[0].setFillColor(Color::Yellow);
        button4.setOutlineColor(Color(80, 252, 25));
        break;
    case 1:
        button4.setPosition(choices[1].getPosition().x / 1.58,
                            choices[1].getPosition().y / 1.23);
        cats[1].setFillColor(Color::Yellow);
        button4.setOutlineColor(Color(80, 252, 25));
        break;
    case 2:
        button4.setPosition(choices[2].getPosition().x / 1.58,
                            choices[2].getPosition().y / 1.23);
        cats[2].setFillColor(Color::Yellow);
        button4.setOutlineColor(Color(80, 252, 25));
        break;
    case 3:
        button4.setPosition(choices[3].getPosition().x / 1.58,
                            choices[3].getPosition().y / 1.23);
        cats[3].setFillColor(Color::Yellow);
        button4.setOutlineColor(Color(80, 252, 25));
        break;

    default:
        break;
    }
    return button4;
}

void window1()
{

    const int WindowWidth = 1500;
    const int WindowHeight = 800;
    RenderWindow window(VideoMode(WindowWidth, WindowHeight), "SFML");

    Texture texture;
    RectangleShape button1(Vector2f(150.f, 80.f)), button2(Vector2f(150.f, 80.f));
    Font font;
    Vector2 position(0.f, 0.f);

    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

    // Sprite for hanging peter
    if (!texture.loadFromFile("./images/peter5.png"))
        return;
    Sprite sprite(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);

    float scaleX = (0.15f * WindowWidth) / sprite.getTexture()->getSize().x;
    float scaleY = (0.8f * WindowHeight) / sprite.getTexture()->getSize().y;
    sprite.setScale(scaleX, scaleY);

    static int catsActive = 0;
    while (window.isOpen())
    {
        RectangleShape button3(Vector2f(190.f, 120.f)), button4(Vector2f(220.f, 140.f));
        static int initialActive = 0;
        static int secondPageActive = 0;

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
            return;
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

        button3.setOutlineColor(Color::White);
        button3.setOutlineThickness(5.f);
        button3.setFillColor(Color(255, 255, 255, 0));
        button3.setPosition(button1.getPosition().x / 1.58,
                            button1.getPosition().y / 1.23);

        if (Keyboard::isKeyPressed(Keyboard::Left) && secondPageActive == 0)
        {
            // left key is pressed: move our character
            initialActive = 0;
            play.move(-5.f, 5.f);
        }

        if (Keyboard::isKeyPressed(Keyboard::Scan::Right) && secondPageActive == 0)
        {
            // right key is pressed: move our character
            initialActive = 1;
            quit.move(5.f, 5.f);
        }

        if (initialActive == 0)
        {
            button3.setPosition(button1.getPosition().x / 1.58,
                                button1.getPosition().y / 1.23);
            play.setFillColor(Color::Yellow);
            button1.setOutlineColor(Color(80, 252, 25));
            if (Keyboard::isKeyPressed(Keyboard::Scan::Enter))
            {
                // window2();
                secondPageActive = 1;
            }
        }
        else if (initialActive == 1)
        {
            button3.setPosition(button2.getPosition().x / 1.225,
                                button2.getPosition().y / 1.23);
            quit.setFillColor(Color::Yellow);
            button2.setOutlineColor(Color(255, 19, 0));
            if (Keyboard::isKeyPressed(Keyboard::Scan::Enter))
                window.close();
        }

        if (secondPageActive == 1)
        {
            window.clear(Color::Red);

            for (int i = 0; i < 4; i++)
            {
                choices[i].setFillColor(Color(87, 146, 21));
                choices[i].setOutlineThickness(15.f);
                choices[i].setOutlineColor(Color(28, 222, 90));
                choices[i].setOrigin(choices[i].getLocalBounds().width / 2.f, choices[i].getLocalBounds().height / 2.f);
                cats[i].setFont(font);
                cats[i].setFillColor(Color(240, 247, 180));

                FloatRect textRect1 = cats[i].getLocalBounds();
                cats[i].setOrigin(textRect1.left + textRect1.width / 1.65f,
                                  textRect1.top + textRect1.height / 0.85f);
                cats[i].setPosition(choices[i].getPosition().x,
                                    choices[i].getPosition().y);
            }
            choices[0].setPosition(WindowWidth / 6, WindowHeight / 2);
            choices[1].setPosition(WindowWidth / 3, WindowHeight / 2);
            choices[2].setPosition(WindowWidth / 2, WindowHeight / 2);

            choices[3].setPosition(WindowWidth / 1.5, WindowHeight / 2);

            cats[catsActive].move(5.f, 5.f);

            cats[0].setString("PLACES");
            cats[3].setString("MOVIES");
            cats[1].setString("SERIES");
            cats[2].setString("CARTOONS");
            button4.setOutlineColor(Color::White);
            button4.setOutlineThickness(5.f);
            button4.setFillColor(Color(255, 255, 255, 0));
            button4.setPosition(choices[1].getPosition().x / 4,
                                choices[1].getPosition().y / 1.27);
            if (event.type == Event::KeyPressed)
            {
                if (event.key.scancode == Keyboard::Scan::Left)
                {
                    // left key is pressed: move our character
                    catsActive--;
                    if (catsActive == -1)
                        catsActive = 3;
                    choices[catsActive].move(-5.f, 5.f);
                    button4 = selectMenu(catsActive, button4);
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Scan::Right))
            {
                // right key is pressed: move our character
                catsActive++;
                if (catsActive == 4)
                    catsActive = 0;
            cout << "bbefore: " << button4.getPosition().x << endl;
                // button4 = selectMenu(catsActive, button4);
            }
            for (int i = 0; i < 4; i++)
            {
                window.draw(choices[i]);
                window.draw(cats[i]);
            }

            window.draw(button4);
            window.display();

            initialActive = 3;
            continue;
        }
        window.clear();
        window.draw(text);
        window.draw(sprite);
        window.draw(button1);
        window.draw(play);
        window.draw(button2);
        window.draw(quit);
        window.draw(button3);
        window.display();
    }
}
int main()
{
    window1();
    return 0;
}