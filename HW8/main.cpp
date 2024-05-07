#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

void input(string &line, char &option, int &num, string &name)
{
    option = line[0];
    switch (option)
    {
    case 'a':
        if (line.length() > 2)
        {
            int spaceIndex = line.find(' ');
            if (spaceIndex != -1)
            {
                num = stoi(line.substr(2, spaceIndex - 2));
                line = line.substr(2,spaceIndex-2);
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
        case 'q':
            break;
            break;

        case 'a':
            bst.insert_node(num,name);
            break;

        case 'd':
            bst.delete_node(num);
        
        case 'p':
            bst.Print();
            break;
        }

    } while (option != 'q');
}
