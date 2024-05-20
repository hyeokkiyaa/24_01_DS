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

    quickSort(list, 0, n - 1);
    printCheck(list, count);
}