#include <iostream>
#include <json/json.h>
#include <typeinfo>
#include <fstream>
using namespace std;

void readFromFile()
{
    Json::Value word;
    std::ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;

    std::cout << word;
    cout << typeid(word).name();
}

int main()
{
    readFromFile();
    return 0;
}