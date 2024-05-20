#include "functionsforhw10.h"
using namespace std;

string removePunctuation(string line)
{
    string result = "";
    for (size_t i = 0; i < line.length(); i++)
    {
        if (isalpha(line[i]) || isdigit(line[i])) // value must equal either alpha or digit to add into result
        {
            result += line[i];
        }
        else
        {
            result += " "; // if other than alphabet or digit then make space
        }
    }
    return result;
}

bool checkExist(countWord *list, string token, int *count)
{
    for (int i = 0; i < (*count); i++)
    {
        if (list[i].word == token)
        {
            return true; // if the word exist return true
        }
    }
    return false; // otherwise return false
}

int getIndex(countWord *list, string token, int *count) // get index of word in the array, if it does not exist return -1
{
    for (int i = 0; i < (*count); i++)
    {
        if (list[i].word == token)
        {
            return i;
        }
    }
    return -1;
}

string toUpperCase(string word) // change small case to upper case
{
    string result = "";
    for (size_t i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z') // case of value of small case
        {
            result += word[i] - ('a' - 'A');
        }
        else
        {
            result += word[i];
        }
    }
    return result;
}

void counting(string line, countWord *list, int *count)
{
    string token = "";
    for (size_t i = 0; i < line.length(); i++)
    {
        if (line[i] != ' ') // if it does not count whitespace
        {
            token += line[i]; // add to token
        }
        else if (!token.empty()) // if whitespace appeared and token is not empy
        {
            token = toUpperCase(token);          // change to uppercase
            if (!checkExist(list, token, count)) // if the token is not in the array
            {
                list[*count].word = token;  // add to the array
                list[*count].totalNum += 1; // increase 1 by word appearance count
                (*count)++;                 // increase number of array
            }
            else
            {
                list[getIndex(list, token, count)].totalNum++; // if exists then just increase the number of appearances of word
            }
            token = ""; // reset token for next word
        }
    }
}

void printCheck(countWord *list, int *count)
{
    if ((*count) < 5) // meaning less than 5 words in the array
    {
        cout << "Number is not enough to print out the 5 most frequent words";
        return;
    }
    for (int i = 0; i < 5; i++) // top 5
    {
        cout << list[i].word << ":" << list[i].totalNum << endl;
    }
}

void print(countWord *list, int *count) // for checking print all
{
    for (int i = 0; i < (*count); i++)
    {
        cout << list[i].word << ":" << list[i].totalNum << endl;
    }
}

void swap(countWord *first, countWord *second) // swap first value of struct and second value of struct
{
    countWord temp = *first;
    *first = *second;
    *second = temp;
}

void quickSort(countWord *list, int left, int right)
{
    int pivotNum, i, j;
    string pivotWord;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivotNum = list[left].totalNum;
        pivotWord = list[left].word;
        do
        {
            do
                i++;
            // descending order of totalNum, if totalNum equals then check word
            while (i <= right && (list[i].totalNum > pivotNum || (list[i].totalNum == pivotNum && list[i].word < pivotWord)));
            do
                j--;
            while (j > left && (list[j].totalNum < pivotNum || (list[j].totalNum == pivotNum && list[j].word > pivotWord)));
            if (i < j)
                swap(&list[i], &list[j]);
        } while (i < j);
        swap(&list[left], &list[j]);
        quickSort(list, left, j - 1);  // first part
        quickSort(list, j + 1, right); // the rest part
    }
}

void getData(countWord *list, int *count)
{
    string filename;
    // get input of textfile
    cout << "Type textfile: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) // file does not exist
    {
        cout << "File does not exist";
        return;
    }
    string line;
    while (getline(file, line))
    {
        line = removePunctuation(line); // remove punctuation first
        counting(line, list, count);    // then count
    }
}