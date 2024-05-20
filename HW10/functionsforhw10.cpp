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
    if((*count)<5){
        cout << "Number is not enough to print out the 5 most frequent words";
        return;
    }
    for (int i = (*count)-1; i > (*count)-6; i--)
    {
        cout << list[i].word << ":" << list[i].totalNum << endl;
    }
}

void swap(countWord *first, countWord *second){
    countWord temp = *first;
    *first = *second;
    *second = temp;
}

void quickSortNo(countWord *list, int left, int right){
    int pivot, i,j;
    if(left<right){
        i =left;
        j=right+1;
        pivot = list[left].totalNum;
        do {
            do i++; while(i <= right && list[i].totalNum < pivot);
            do j--; while(j > left && list[j].totalNum > pivot);
            if(i<j)
                swap(&list[i], &list[j]);
        }while(i<j);
        swap(&list[left], &list[j]);
        quickSortNo(list,left,j-1);
        quickSortNo(list,j+1,right);
    }
}

void quickSortString(countWord *list, int left, int right){
    int i,j;
    string pivot;
    if(left<right){
        i =left;
        j=right+1;
        pivot = list[left].word;
        do {
            do i++; while(i <= right && list[i].word > pivot);
            do j--; while(j > left && list[j].word < pivot);
            if(i<j)
                swap(&list[i], &list[j]);
        }while(i<j);
        swap(&list[left], &list[j]);
        quickSortString(list,left,j-1);
        quickSortString(list,j+1,right);
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