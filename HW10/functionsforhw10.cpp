#include "functionsforhw10.h"
using namespace std;

string removePunctuation(string line)
{
    string result = "";
    for (size_t i = 0; i < line.length(); i++)
    {
        if (isalpha(line[i]) || isdigit(line[i]))
        {
            result += line[i];
        }
        else
        {
            result += " ";
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
            return true;
        }
    }
    return false;
}

int getIndex(countWord *list, string token, int *count)
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

string toUpperCase(string word)
{
    string result = "";
    for (size_t i = 0; i < word.length(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
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
        if (line[i] != ' ')
        {
            token += line[i];
        }
        else if (!token.empty())
        {
            token = toUpperCase(token);
            if (!checkExist(list, token, count))
            {
                list[*count].word = token;
                list[*count].totalNum += 1;
                (*count)++;
            }
            else
            {
                list[getIndex(list, token, count)].totalNum++;
            }
            token = "";
        }
    }
}

void printCheck(countWord *list, int *count)
{
    if ((*count) < 5)
    {
        cout << "Number is not enough to print out the 5 most frequent words";
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << list[i].word << ":" << list[i].totalNum << endl;
    }
}

void print(countWord *list, int *count)
{
    for (int i = 0; i < (*count); i++)
    {
        cout << list[i].word << ":" << list[i].totalNum << endl;
    }
}

void swap(countWord *first, countWord *second)
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
            while (i <= right && (list[i].totalNum > pivotNum || (list[i].totalNum == pivotNum && list[i].word < pivotWord)));
            do
                j--;
            while (j > left && (list[j].totalNum < pivotNum || (list[j].totalNum == pivotNum && list[j].word > pivotWord)));
            if (i < j)
                swap(&list[i], &list[j]);
        } while (i < j);
        swap(&list[left], &list[j]);
        quickSort(list, left, j - 1);
        quickSort(list, j + 1, right);
    }
}

void getData(countWord *list, int *count)
{
    string filename;
    cout << "Type textfile: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "File does not exist";
        return;
    }
    string line;
    while (getline(file, line))
    {
        line = removePunctuation(line);
        counting(line, list, count);
    }
}