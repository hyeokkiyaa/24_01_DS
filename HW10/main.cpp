#include <iostream>
#include "functionsforhw10.h"
using namespace std;

int main(void)
{
    int countNum = 0;                      // counting number of lists
    int *count = &countNum;                // pointer value
    countWord *list = new countWord[2048]; // max words are state to 2048
    getData(list, count);                  // get data from file
    int n = *count;                        // put number of list into var
    if (n == 0)                            // meaning file is empty
    {
        cout << "File is empty";
        return 0;
    }
    quickSort(list, 0, n - 1); // sort -> by number if numbers eqaul then words in dictionary order
    printCheck(list, count);   // printout result
    delete[] list;
    delete count;
}