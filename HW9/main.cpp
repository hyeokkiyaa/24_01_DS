// time taken: about 11 hours
#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

int main(void)
{
    BST bst;
    string input;
    string value;
    for (int i = 0; i < 5; i++)
    {
        cin >> input >> value;
        bst.insert_node(input, value);
    }
    bst.Print();
}
