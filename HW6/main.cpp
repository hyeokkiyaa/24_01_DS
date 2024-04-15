#include <iostream>
#include "calculator.h"

using namespace std;

int main(void)
{
    string str;
    cout << "Type Equation:" << endl;
    cout << ">> ";
    getline(cin, str);

    Calculator calc;                      // Calculator 객체 생성
    cout << calc.getPostFixEquation(str)<<endl; // 객체를 통해 getPostFixEquation 함수 호출
    cout << calc.calculate(calc.getPostFixEquation(str));

    return 0;
}
