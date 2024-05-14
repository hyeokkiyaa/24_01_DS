#include <iostream>
#include <string>
#include <fstream>
#include "BST.h"
using namespace std;

int main(void)
{
    BST bst;
    string textFile;
    string mapFile;

    // Get names of each text files
    cout << "Type Text File: ";
    cin >> textFile;
    cout << "Type Map File: ";
    cin >> mapFile;

    string line;

    // Get map value and put them in the BST
    ifstream fileMap(mapFile);

    if (fileMap.is_open())
    {
        while (getline(fileMap, line))
        {
            string find;
            int index = line.find(":");
            find = line.substr(0, index);
            line = line.substr(index + 2); // since it has : and space
            bst.insert_node(find, line);   // insert find as key line as valuel
        }
    }
    else
    {
        cout << mapFile << " does not exist" << endl;
        return 0;
    }

    fileMap.close();


    //find and replace if it exists
    ifstream fileData(textFile);
    string token;   //for word
    string result = ""; //printint out
    if (fileData.is_open())
    {
        while (getline(fileData, line))
        {
            //reset token
            token = "";
            //length of the line, size_t since c++ suggest size_t for length
            for (size_t i = 0; i < line.length(); i++)
            {   
                //if space is not found
                if (line[i] != ' ')
                {
                    token += line[i];   //make as token
                }
                else
                {
                    //if space is found then compare the value with key in the bst if do, replace
                    if (bst.search(token))
                    {
                        token = bst.search(token)->value;
                        result += token + " ";
                        token = "";
                    }
                    else
                    {
                        result += token + " ";
                        token = "";
                    }
                }
            }
            //for the last one since it does not have space at the end
            if (bst.search(token))
            {
                token = bst.search(token)->value;
                result += token + " ";
            }
            else
            {
                result += token + " ";
            }
            result += "\n";
        }
    }
    else
    {
        cout << textFile << " does not exist" << endl;
        return 0;
    }
    fileData.close();

    //printout result
    cout << result;
}
