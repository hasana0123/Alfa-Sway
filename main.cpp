#include <iostream>
#include <json/json.h>
#include <typeinfo>
#include <fstream>
using namespace std;
using namespace Json;

void readFromFile(string Cat)
{
    Value word;
    ifstream word_file("wordsAndHints.json", std::ifstream::binary);
    word_file >> word;
    cout << typeid(word).name();
}



void CategorySelection()
{
    int Category;
    cout<<"Which Category do you want to play?"<<endl;
    cout<<"1: Places  2: Movies/Series"<<endl;
    cout<<"Enter here: .....";
    cin>>Category;
    switch (Category)
    {
    case 1:
        readFromFile("places");
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