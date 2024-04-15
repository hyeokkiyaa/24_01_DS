#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include "stack.h"
#include <iostream>

using namespace std;

class Calculator
{
private:
    int length;
    string PostFixEquation;
    double result;

public:
    string getPostFixEquation(string);
    double calculate(string);
};

#endif