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

void play(string, string, string);
bool compareWithGuessed(char, string);
int compareWithOriginal(string, char);
char makeUppercase(char);
string replaceGuessedLetters(string, string, char);
void showGuessed(string guessedLetters);

void readFromFile(string Cat)
{
    Value word, selectedWord, hintRead;

    // Opens the json file where words for games are stored

    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;

    // Randomly generate words of Category selected by users

    srand(time(0));
    int size = word["categories"][Cat].size();
    int randomIndex = rand() % (size);

    // Read the phrase from file

    selectedWord = word["categories"][Cat][randomIndex]["phrase"];

    // Read the hint for the phrase from file

    hintRead = word["categories"][Cat][randomIndex]["hint"];

    // convert the json object to string

    string wordToGuess = selectedWord.asString();

    string hint = hintRead.asString();
    cout << "Hint===>" << hint << endl;
    cout << wordToGuess << endl
         << endl
         << endl;

    // Make the phrase hidden for user to guess

    string hiddenWord;

    for (int i = 0; i < wordToGuess.length(); i++)
    {
        if (wordToGuess[i] == ' ')
            hiddenWord.push_back(' ');

        else
            hiddenWord.push_back('^');
    }

    // Start Game

    play(hiddenWord, wordToGuess, hint);

    word_file.close();
    return;
}

// Read the expressions from file randomly and print in console

void readExpressions(string expression)
{
    Value word;

    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;

    srand(time(0));

    int size = word["expressions"][expression].size();
    int randomIndex = rand() % (size);

    cout << word["expressions"][expression][randomIndex].asString() << endl;

    word_file.close();
}

void play(string hiddenWord, string wordToGuess, string hint)
{
    int chances = 6, flag;
    char guess;
    string guessedLetters;

    cout << "-----------------------" << endl;
    cout << "          LET'S GO!" << endl
         << endl;
    do
    {
        cout << "|---------------------------------------------------------|" << endl;
        cout << "|     Chances = " << chances << endl;
        cout << "|---------------------------------------------------------|" << endl;
        cout << "|     Hint: " << hint << "                                 " << endl;
        cout << "|---------------------------------------------------------|" << endl;
        cout << "      To guess: " << hiddenWord << "                                 " << endl;
        cout << "|---------------------------------------------------------|" << endl;
        cout << "      Guessed Letters are===> " << endl;
        showGuessed(guessedLetters);
        cout << endl;
        cout << "|---------------------------------------------------------|" << endl
             << endl;

        // Input the guess from Users

        cout << "Enter the alphabet===>";
        cin >> guess;
        cout << "---------------------------------------------" << endl;

        // Convert user guessed letters to uppercase
        guess = makeUppercase(guess);

        // Compare the guessed letter with already guessed letters

        if (compareWithGuessed(guess, guessedLetters))
        {
            cout << "          Letter has already been chosen. \n       Choose another letter!" << endl;
            continue;
        }
        // For new guess, compare the guessed word with the word needed to be guessed
        else
        {
            flag = compareWithOriginal(wordToGuess, guess);
            switch (flag)
            {
                // Case for incorrect guess
            case 0:
                readExpressions("incorrect");
                chances--;

                if (chances == 0 && (hiddenWord != wordToGuess))
                {
                    cout << "The phrase was " << wordToGuess << endl;
                    cout << "I WILL NEVER FORGET YOU!" << endl;
                }
                break;
                // Case for correct guess
            case 1:
                readExpressions("correct");

                hiddenWord = replaceGuessedLetters(wordToGuess, hiddenWord, guess);
                if (hiddenWord == wordToGuess)
                {
                    cout << "The phrase was " << wordToGuess << endl;
                    cout << "MY PRECIOUS! THANK YOU!" << endl;
                    return;
                }
                break;
            }
        }

        // Add the guessed letters to stack

        guessedLetters.push_back(guess);

    } while (chances != 0);
    return;
}

char makeUppercase(char guess)
{
    if (guess <= 122 && guess >= 97)
        guess = guess - 32;

    return guess;
}

// Show users the already guessed letters in console so they don't repeat it

void showGuessed(string guessedLetters)
{
    for (int i = 0; i < guessedLetters.length(); i++)
    {
        cout << guessedLetters[i] << ", ";
    }
}

// To replace the hidden letters with guessed letters if the guess is correct

string replaceGuessedLetters(string wordToGuess, string hiddenWord, char guess)
{
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        if (wordToGuess[i] == ' ')
            continue;

        if (wordToGuess[i] == guess)

            hiddenWord[i] = guess;
    }
    return hiddenWord;
}

bool compareWithGuessed(char guess, string guessedLetters)
{
    for (int i = 0; i < guessedLetters.length(); i++)
    {
        if (guess == guessedLetters[i])
            return true;
    }
    return false;
}

int compareWithOriginal(string wordToGuess, char guess)
{
    int flag = 0;
    for (int i = 0; i < wordToGuess.length(); i++)
    {
        if (guess == wordToGuess[i])
            flag = 1;
    }
    return flag;
}


void CategorySelection()
{
    int Category;
    cout << "\n         Which Category do you want to play?" << endl;
    cout << "         1: Places  2: Movies 3:cartoons 4:series\n"
         << endl;
    cout << "         Enter here: ===>";
    cin >> Category;
    switch (Category)
    {
    case 1:
        readFromFile("places");
        break;
    case 2:
        readFromFile("movies");
        break;
    case 3:
        readFromFile("cartoons");
        break;
    case 4:
        readFromFile("series");
        break;
    default:
        break;
    }
    return;
}

int main()
{
   Game game;
   game.play();

}