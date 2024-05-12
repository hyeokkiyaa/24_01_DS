// time taken: about 11 hours
#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
using namespace std;

int main(void)
{
    BST bst;
    string input;
    string value;

    cin >> input >> value;
    bst.insert_node(input, value);
    string token;
    ifstream file("map.txt");
    string result="";
    if(file.is_open()){
        while(file>>token){
            if(bst.search(token)!=NULL){
                result += bst.search(token)->value + " ";
            }
            else {
                result += token +" ";
            }
        }
    }
    cout << result;
    


}
