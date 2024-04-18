#include "DList.h"
#include <iostream>
using namespace std;

int main(void){
    DList dl;
    int num;
    cin >> num;
    dl.Insert(num);
    cin >> num;
    dl.Insert(num);
    cin >> num;
    dl.Insert(num);
    dl.Print();
}