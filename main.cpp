#include <iostream>
#include <json/json.h>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace Json;

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

    selectedWord = word["categories"][Cat][randomIndex]["phrase"].asString();

    // Read the hint for the phrase from file

    hintRead = word["categories"][Cat][randomIndex]["hint"].asString();

    // convert the json object to string

    string wordToGuess = selectedWord.asString();
    string hint = hintRead.asString();
    cout << "Hint===>" << hint << endl;
    cout << wordToGuess << endl
         << endl
         << endl;

    // Make the phrase hidden for user to guess

    char hiddenWord[wordToGuess.length()];

    for (int i = 0; i < wordToGuess.length(); i++)
    {
        if (wordToGuess[i] == ' ')
            hiddenWord[i] = ' ';

        else
            hiddenWord[i] = '.';
    }
    cout << hiddenWord << endl;

    word_file.close();
}

void play(string hiddenWord, string wordToGuess, string hiint)
{
    int chances = 6, flag = 0;

    cout << "-----------------------" << endl;
    cout << "THE GAME BEGINS NOW!" << endl;
}

void CategorySelection()
{
    int Category;
    cout << "Which Category do you want to play?" << endl;
    cout << "1: Places  2: Movies 3:cartoons 4:series" << endl;
    cout << "Enter here: ===>";
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
}

int main()
{
    CategorySelection();
    return 0;
}