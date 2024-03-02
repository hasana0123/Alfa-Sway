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
    void playGame(Button &, Button &, RectangleShape &, Text &);
    void quitGame(Button &, Button &, RectangleShape &, Text &);
    void showInitialPage();
    void secondPage(RenderWindow &window, Sprite &);
    void thirdPage(RenderWindow &window, Sprite &, int &);
    void setTextProperty(Text &text, string, float);
    void setButtonProperty(RectangleShape &box, Text &text, Button &button);
    void selectMenu(int &, RectangleShape &, Button button[], Text text[]);
};

void Game::setTextProperty(Text &text, string phrase, float widthRatio)
{

    text.setString(phrase);
    text.setPosition(WindowWidth / widthRatio, WindowHeight / 4);
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

void Game::thirdPage(RenderWindow &window, Sprite &sprite, int &activeKey)
{
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

void Game::selectMenu(int &activeKey, RectangleShape &Active, Button button[4], Text text[4])
{

    Active.setPosition(button[activeKey].boxPositionX - 15, button[activeKey].boxPositionY - 20);
    Active.setOutlineColor(Color::Yellow);

    text[activeKey].setFillColor(Color(252, 234, 21));
    text[activeKey].setCharacterSize(button[activeKey].textCharacterSize + 3);
    for (int i = 0; i < 4; i++)
    {
        if (activeKey == i)
            button[i].Activate();
        else
            button[i].Deactivate();
    }

    for (int i = 0; i < 4; i++)
    {
        if (!button[i].isActive)
        {
            text[i].setFillColor(button[i].textFillColor);
            text[i].setCharacterSize(button[i].textCharacterSize);
        }
    }
}

void Game::secondPage(RenderWindow &window, Sprite &sprite)
{
    Font font;
    if (!font.loadFromFile("./Fonts/Roboto-Black.ttf"))
        return;

    int activeKey = -1;
    RectangleShape Active(Vector2f(230.f, 130.f));

    Button placeButton, seriesButton, cartoonButton, moviesButton;
    RectangleShape placeShape(Vector2f(200.f, 90.f)), seriesShape(Vector2f(200.f, 90.f)), cartoonShape(Vector2f(200.f, 90.f)), movieShape(Vector2f(200.f, 90.f));
    Text placeText, seriesText, cartoonText, movieText, chooseText;

    Button choiceButtons[4] = {placeButton, seriesButton, cartoonButton, moviesButton};
    RectangleShape choiceShape[4] = {placeShape, seriesShape, cartoonShape, movieShape};
    Text choiceText[4] = {placeText, seriesText, cartoonText, movieText};

    for (int i = 0; i < 4; i++)
    {
        choiceButtons[i].setBoxSize(150.f, 80.f);
        choiceButtons[i].setBoxColor(Color(87, 146, 21), Color(115, 222, 90));
        choiceButtons[i].setTextColor(Color(240, 247, 180));
        choiceButtons[i].setTextSize(30.f);
        choiceText[i].setFont(font);
    }

    choiceButtons[0].setText("PLACES");
    choiceButtons[0].setPosition(WindowWidth / 6, WindowHeight / 2);
    choiceButtons[0].isActive = false;
    choiceButtons[1].setText("SERIES");
    choiceButtons[1].setPosition(WindowWidth / 3, WindowHeight / 2);
    choiceButtons[1].isActive = false;
    choiceButtons[2].setText("CARTOONS");
    choiceButtons[2].setPosition(WindowWidth / 2, WindowHeight / 2);
    choiceButtons[2].isActive = false;
    choiceButtons[3].setText("MOVIES");
    choiceButtons[3].setPosition(WindowWidth / 1.5, WindowHeight / 2);
    choiceButtons[3].isActive = false;

    chooseText.setFont(font);

    setTextProperty(chooseText, "Choose a Category:", 3.f);

    Active.setFillColor(Color(0, 0, 0, 0));
    Active.setOutlineColor(Color(187, 183, 132));
    Active.setOutlineThickness(10.f);
    Active.setPosition(choiceButtons[0].boxPositionX - 15, choiceButtons[0].boxPositionY - 20);

    for (int i = 0; i < 4; i++)
        setButtonProperty(choiceShape[i], choiceText[i], choiceButtons[i]);

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::KeyPressed)
            {
                if (event.key.scancode == Keyboard::Scan::Left)
                {
                    activeKey--;
                    if (activeKey == -1)
                        activeKey = 3;
                    if (activeKey == -2)
                        activeKey = 0;
                    selectMenu(activeKey, Active, choiceButtons, choiceText);
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Scan::Right))
            {
                activeKey++;
                if (activeKey == 4)
                    activeKey = 0;
                selectMenu(activeKey, Active, choiceButtons, choiceText);
            }

            if (event.key.scancode == Keyboard::Scancode::Enter)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (choiceButtons[i].isActive)
                        thirdPage(window, sprite, activeKey);
                }
            }
        }
        window.clear();
        window.draw(sprite);
        for (int i = 0; i < 4; i++)
        {
            window.draw(choiceShape[i]);
            window.draw(choiceText[i]);
        }
        window.draw(Active);
        window.draw(chooseText);
        window.display();
    }
}

void Game::playGame(Button &play, Button &quit, RectangleShape &Active, Text &playText)
{
    Active.setPosition(play.boxPositionX - 20, play.boxPositionY - 20);
    playText.setFillColor(Color(252, 234, 21));
    playText.setCharacterSize(play.textCharacterSize + 10);
    play.Activate();
    quit.Deactivate();
}

void Game::quitGame(Button &play, Button &quit, RectangleShape &Active, Text &quitText)
{
    Event event;
    Active.setPosition(quit.boxPositionX - 20, quit.boxPositionY - 20);
    quitText.setFillColor(Color(252, 234, 21));
    quitText.setCharacterSize(quit.textCharacterSize + 10);

    play.Deactivate();
    quit.Activate();
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
    play.isActive = true;

    quit.setBoxSize(150.f, 80.f);
    quit.setBoxColor(Color(213, 97, 59), Color(250, 142, 84));
    quit.setText("QUIT");
    quit.setTextColor(Color(240, 247, 180));
    quit.setTextSize(30.f);
    quit.setPosition(WindowWidth / 1.8, WindowHeight / 1.75);
    quit.isActive = false;

    Active.setFillColor(Color(0, 0, 0, 0));
    Active.setOutlineColor(Color::Yellow);
    Active.setOutlineThickness(10.f);
    Active.setPosition(WindowWidth / 3.12, WindowHeight / 1.83);

    sprite.setColor(Color(177, 0, 255));

    setTextProperty(letsPlay, "LET'S PLAY!", 2.5);
    setButtonProperty(Play, playText, play);
    setButtonProperty(Quit, QuitText, quit);

    playText.setFillColor(Color(252, 234, 21));
    playText.setCharacterSize(play.textCharacterSize + 10);

    while (window.isOpen())
    {

        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.key.scancode == Keyboard::Scan::Left)
                {
                    QuitText.setCharacterSize(quit.textCharacterSize);
                    QuitText.setFillColor(Color(quit.textFillColor));
                    playGame(play, quit, Active, playText);
                }
                if (event.key.scancode == Keyboard::Scan::Right)
                {
                    playText.setCharacterSize(play.textCharacterSize);
                    playText.setFillColor(Color(play.textFillColor));

                    quitGame(play, quit, Active, QuitText);
                }

                if (event.key.scancode == Keyboard::Scancode::Enter)
                {
                    if (quit.isActive)
                        window.close();

                    if (play.isActive)
                    {
                        secondPage(window, sprite);
                    }
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
}