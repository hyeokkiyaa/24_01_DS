#include <iostream>
#include <fstream>
#include "functionsforhw10.h"
using namespace std;

int main(void)
{
    int countNum = 0;
    int *count = &countNum;

    countWord *list = new countWord[2048];
    string check = "In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification [1][2][3]. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data [4].";
    check = removePunctuation(check);
    counting(check, list, count);
    int n = *count;
    quickSort(list,0,n-1);
    printCheck(list, count);
}