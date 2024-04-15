#include <iostream>
#include "stack.h"
#include "calculator.h"

using namespace std;

int main(void)
{
    string str;
    cout << "Type Equation:" << endl;
    cout << ">> ";
    getline(cin, str);

    Calculator calc;                      // Calculator 객체 생성
    cout << calc.getPostFixEquation(str); // 객체를 통해 getPostFixEquation 함수 호출

    return 0;
}
