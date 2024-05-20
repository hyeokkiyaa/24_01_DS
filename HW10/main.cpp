#include <iostream>
#include "functionsforhw10.h"
using namespace std;

int main(void)
{
    int countNum = 0;
    int *count = &countNum;
    countWord *list = new countWord[2048];
    getData(list, count);
    int n = *count;
    if (n == 0)
    {
        cout << "File is empty";
        return 0;
    }
    quickSortNo(list, 0, n - 1);
    int store = list[0].totalNum;
    int index = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (list[i].totalNum == store)
        {
            count++;
        }
        else
        {
            quickSortString(list, index, index + count);
            index = i;
            count = 0;
            store = list[i].totalNum;
        }
    }
    printCheck(list, count);
}