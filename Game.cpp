#include <iostream>
#include <typeinfo>
#include <SFML/Graphics.hpp>
#include "Button.cpp"

using namespace std;
using namespace sf;

class Game
{
    float WindowWidth = 1500.f, WindowHeight = 800.f;

public:
    void playGame(Button &, Button &, RectangleShape &, Text &, RenderWindow &);
    void quitGame(Button &, Button &, RectangleShape &, Text &, RenderWindow &);
    void showInitialPage();
    void setTextProperty(Text &text, string);
    void setButtonProperty(RectangleShape &box, Text &text, Button &button);
};

void Game::setTextProperty(Text &text, string phrase)
{

    text.setString(phrase);
    text.setPosition(WindowWidth / 2.5, WindowHeight / 4);
    text.setFillColor(Color::White);
    text.setCharacterSize(50.f);
}

void Game::setButtonProperty(RectangleShape &box, Text &text, Button &button)
{
    box.setFillColor(button.boxFillColor);
    box.setOutlineColor(button.boxOutlineColor);
    box.setPosition(button.boxPositionX, button.boxPositionY);
    box.setOutlineThickness(10.f);

    text.setFillColor(button.textFillColor);
    text.setPosition(button.textPositionX, button.textPositionY);
    text.setCharacterSize(button.textCharacterSize);
    text.setString(button.inText);
}

void Game::playGame(Button &play, Button &quit, RectangleShape &Active, Text &playText, RenderWindow &window)
{
    Active.setPosition(play.boxPositionX - 20, play.boxPositionY - 20);
    playText.setFillColor(Color(252, 234, 21));
    playText.setCharacterSize(play.textCharacterSize + 10);
    play.Activate();
    quit.Deactivate();
}

void Game::quitGame(Button &play, Button &quit, RectangleShape &Active, Text &quitText, RenderWindow &window)
{
    Active.setPosition(quit.boxPositionX - 20, quit.boxPositionY - 20);
    quitText.setFillColor(Color(252, 234, 21));
    quitText.setCharacterSize(quit.textCharacterSize + 10);

    play.Deactivate();
    quit.Activate();

    if (Keyboard::isKeyPressed(Keyboard::Scan::Enter))
    {
        cout << "abc" << endl;
        window.close();
    }
}

void Game::showInitialPage()
{
    RenderWindow window(VideoMode(this->WindowWidth, this->WindowWidth), "Alfa-Sway");
    Button play, quit;
    RectangleShape Play(Vector2f(150.f, 80.f)), Quit(Vector2f(150.f, 80.f)), Active(Vector2f(190.f, 120.f));
    Text letsPlay, playText, QuitText;

    Font font;
    if (!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
        return;
    playText.setFont(font);
    QuitText.setFont(font);
    letsPlay.setFont(font);

    Texture texture;
    if (!texture.loadFromFile("./images/bg1.jpg"))
        return;
    Sprite sprite(texture);

    play.setBoxSize(150.f, 80.f);
    play.setBoxColor(Color(87, 146, 21), Color(115, 222, 90));
    play.setText("PLAY");
    play.setTextColor(Color(240, 247, 180));
    play.setTextSize(30.f);
    play.setPosition(WindowWidth / 3, WindowHeight / 1.75);

    quit.setBoxSize(150.f, 80.f);
    quit.setBoxColor(Color(213, 97, 59), Color(250, 142, 84));
    quit.setText("QUIT");
    quit.setTextColor(Color(240, 247, 180));
    quit.setTextSize(30.f);
    quit.setPosition(WindowWidth / 1.8, WindowHeight / 1.75);

    Active.setFillColor(Color(0, 0, 0, 0));
    Active.setOutlineColor(Color(255, 255, 255));
    Active.setOutlineThickness(10.f);
    Active.setPosition(WindowWidth / 3.12, WindowHeight / 1.83);

    sprite.setColor(Color(177, 0, 255));

    setTextProperty(letsPlay, "LET'S PLAY!");
    setButtonProperty(Play, playText, play);
    setButtonProperty(Quit, QuitText, quit);

    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if (event.type == Event::KeyPressed)
        {
            if (event.key.scancode == Keyboard::Scan::Left)
            {
                QuitText.setCharacterSize(quit.textCharacterSize);
                QuitText.setFillColor(Color(quit.textFillColor));
                playGame(play, quit, Active, playText, window);
            }
            if (event.key.scancode == Keyboard::Scan::Right)
            {
                playText.setCharacterSize(play.textCharacterSize);
                playText.setFillColor(Color(play.textFillColor));

                quitGame(play, quit, Active, QuitText, window);
            }
            cout<<"dhf  "<<event.key.scancode<<endl;
            cout<<"dhrdff  "<<Keyboard::Scancode::Enter<<endl;
            if (event.key.scancode == Keyboard::Scancode::Enter)
            {
                cout << "abc" << endl;
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(Quit);
        window.draw(QuitText);
        window.draw(Play);
        window.draw(playText);
        window.draw(letsPlay);
        window.draw(Active);
        window.display();
    }
}