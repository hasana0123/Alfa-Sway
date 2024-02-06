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
    Value word;

    //Opens the json file where words for games are stored

    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;

    //Randomly generate words of Category selected by users

    srand(time(0));
    int randomIndex = rand() % 5;
    Value wordToGuess = word["categories"][Cat][randomIndex]["phrase"];
    Value hint = word["categories"][Cat][randomIndex]["hint"];
    cout << "Word to guess ===>" << wordToGuess << endl;
    cout << "Hint===>" << hint;

    word_file.close();
}

void play(string);

void CategorySelection()
{
    int Category;
    cout << "Which Category do you want to play?" << endl;
    cout << "1: Places  2: Movies/Series" << endl;
    cout << "Enter here: .....";
    cin >> Category;
    switch (Category)
    {
    case 1:
        readFromFile("places");
        break;
    case 2:
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