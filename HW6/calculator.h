#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "stack.h"
#include "stack2.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Calculator
{
private:
    string PostFixEquation="";
    Stack *stack; // pointer to Stack object
    Stack2 *stack2;

public:
    // Member functions
    string getPostFixEquation(string st);
    double calculate(string st);
    static int priority(char ch); // Static member function
    bool isOperator(char ch);
    static double doOperator(char ch, double n1, double n2);
};

#endif
