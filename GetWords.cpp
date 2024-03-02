#include <iostream>
#include <string>
#include <json/json.h>
#include <typeinfo>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace Json;
using namespace sf;

class Words
{
public:
    std::string phrase, hint, comment;
    std:: string hiddenWord;
    void readFile(string Cat);
    string readComment(string);
    bool compareGuessed(char &, string &);
    void replaceWord(string &);
    bool compareWord(string &);
    void makeUppercase(char &);

    string guessedLetters();
};

void Words::readFile(string Cat)
{
    Json::Value file, selectedWord, hintRead;
    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> file;

    srand(time(0));
    int size = file["categories"][Cat].size();
    int randomIndex = rand() % (size);

    selectedWord = file["categories"][Cat][randomIndex]["phrase"];

    // Read the hint for the phrase from file

    hintRead = file["categories"][Cat][randomIndex]["hint"];

    // convert the json object to string

    this->phrase = selectedWord.asString();

    this->hint = hintRead.asString();

    for (int i = 0; i < phrase.length(); i++)
    {
        if (phrase[i] == ' ')
            this->hiddenWord.push_back(' ');

        else
            this->hiddenWord.push_back('-');
    }

    word_file.close();
}

string Words::readComment(string expression)
{
    Value word;

    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;

    srand(time(0));

    int size = word["expressions"][expression].size();
    int randomIndex = rand() % (size);

    this->comment = word["expressions"][expression][randomIndex].asString();
    word_file.close();
    return comment;
}

void Words::makeUppercase(char &inputChar)
{
    if (inputChar <= 122 && inputChar >= 97)
        inputChar = inputChar - 32;
}

bool Words::compareGuessed(char &inputChar, string &guessedString)
{

    for (int i = 0; i < guessedString.length(); i++)
    {
        if (inputChar == guessedString[i])
            return true;
    }
    return false;
}
void Words::replaceWord(string &inputChar)
{
    for (int i = 0; i < this->phrase.length(); i++)
    {
        if (inputChar[0] == this->phrase[i])
            this->hiddenWord[i] = this->phrase[i];
        if (this->phrase[i] == ' ')
            continue;
    }
}

bool Words::compareWord(string &inputChar)
{
    for (int i = 0; i < this->phrase.length(); i++)
    {
        if (inputChar[0] == this->phrase[i])
            return true;
        if (this->phrase[i] == ' ')
            continue;
    }
    return false;
}