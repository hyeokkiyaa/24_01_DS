#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

void input(string &line, char &option, int &num, string &name)
{
    option = line[0];
    string trimmedLine = line.substr(2);

    string number;
    int spaceIndex;
    switch (option)
    {
    case 'a':
        spaceIndex = line.find(' ');
        number = line.substr(0,spaceIndex);
        num = stoi(number);
        trimmedLine = line.substr(spaceIndex);
        name = line;
        break;

    case 'd':
    
        break;
    }

    while (trimmedLine[index] != ' ')
    {
        number += trimmedLine[index++];
    }
    num = stoi(number);

    name = trimmedLine.substr(index + 1);
}

int main(void)
{
    string line;
    char option = '\0';
    int num;
    string name;
    BST bst;
    while (option != 'q')
    {
        getline(cin, line);
        input(line, option, num, name);
        switch (option)
        {
        case 'q':
            break;
            break;

        default:
            cout << 1 << endl;
            break;
        }
    }
}
