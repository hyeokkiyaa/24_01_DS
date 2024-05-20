#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct countWord // set values
{
    string word;      // word
    int totalNum = 0; // number of word appeared
};

string removePunctuation(string line);                      // make pure words only
bool checkExist(countWord *list, string token, int *count); // check if words exist in the array
int getIndex(countWord *list, string token, int *count);    // if exist then get index of word
string toUpperCase(string word);                            // change words into uppercase
void counting(string line, countWord *list, int *count);    // count the number of appearances of words
void printCheck(countWord *list, int *count);               // result of top 5 words appear
void swap(countWord *first, countWord *second);             // swap two values from list
void quickSort(countWord *list, int left, int right);       // sort -> number then word
void getData(countWord *list, int *count);                  // get Data from text file
void print(countWord *list, int *count);                    // print all the value of the lists