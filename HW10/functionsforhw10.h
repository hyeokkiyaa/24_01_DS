#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct countWord
{
    string word;
    int totalNum = 0;
};

string removePunctuation(string line);
bool checkExist(countWord *list, string token, int *count);
int getIndex(countWord *list, string token, int *count);
string toUpperCase(string word);
void counting(string line, countWord *list, int *count);
void printCheck(countWord *list, int *count);
void swap(countWord *first, countWord *second);
void quickSort(countWord *list, int left, int right);
void getData(countWord *list, int *count);
void print(countWord *list, int *count);