#include <iostream>
#include "calculator.h"

using namespace std;

int main(void)
{
    string str;
    cout << "Type Equation:" << endl;
    cout << ">> ";
    getline(cin, str);

    Calculator calc;                      // Calculator Class call
    cout << "Post Fixed Equation: " <<endl;
    cout << ">> ";
    cout << calc.getPostFixEquation(str)<<endl; // call getPostFixEquation under calc class

    cout << "result: " <<endl;
    cout << ">> ";
    cout<<fixed;
    cout.precision(2);
    cout << calc.calculate(calc.getPostFixEquation(str));// call calculate under calc class

    return 0;
}
