// time taken: about 11 hours
#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

// input function made
void input(string &line, char &option, int &num, string &name)
{
    option = line[0];
    switch (option)
    {
    // case of a will have to obtain two values one for key and one for name in order
    case 'a':
        if (line.length() > 2)
        {
            int spaceIndex = line.find(' ');
            if (spaceIndex != -1)
            {
                num = stoi(line.substr(2, spaceIndex - 2));
                line = line.substr(2, spaceIndex - 2);
                name = line.substr(spaceIndex + 1);
            }
        }
        break;

    case 'd':
        num = stoi(line.substr(2));
        break;
    }
}

int main(void)
{
    string line;
    char option;
    int num = 0;
    string name = "";
    BST bst;
    do
    {
        getline(cin, line);
        input(line, option, num, name);
        switch (option)
        {
        case 'q': // quit
            break;
            break;

        case 'a': // add # name
            bst.insert_node(num, name);
            break;

        case 'd': // del #
            bst.delete_node(num);
            break;

        case 'p': // print
            bst.Print();
            break;
        }

    } while (option != 'q');
}
