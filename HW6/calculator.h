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
    Stack *stack; // pointer to Stack object

public:
    // Constructor and Destructor
    Calculator(int stackSize = 100) : stack(new Stack(stackSize)) {}
    ~Calculator() { delete stack; }

    // Member functions
    string getPostFixEquation(string st);
    double calculate(string st);
    static int priority(char ch); // Static member function
    bool isOperator(char ch);
    void setNumber(string st); // Function definition
};

#endif
