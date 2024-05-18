#include <iostream>
#include <fstream>
using namespace std;

string removePunctuation(string line)
{
    string result = "";
    for (int i = 0; i < line.length(); i++)
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

struct countWord
{
    string word;
    int totalNum = 0;
};

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
    for (int i = 0; i < word.length(); i++)
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
    for (int i = 0; i < line.length(); i++)
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
    for (int i = 0; i < (*count); i++)
    {
        cout << list[i].word << " " << list[i].totalNum << endl;
    }
}

int main(void)
{
    int countNum = 0;
    int *count = &countNum;

    countWord *list = new countWord[2048];
    string check = "In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification [1][2][3]. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data [4].";
    check = removePunctuation(check);
    counting(check, list, count);
    printCheck(list, count);
}