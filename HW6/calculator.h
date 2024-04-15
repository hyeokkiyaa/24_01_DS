#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:
    int length;
    double *num;
    string PostFixEquation;
    double result;
    Stack *stack = new Stack(100); // stack starts

public:
    string getPostFixEquation(string);
    double calculate(string);
    int priority(char);
};

#endif