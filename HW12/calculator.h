#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <stack>
#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:
    string PostFixEquation="";
    stack<char> stack; // pointer to Stack object
    std::stack<double> stack2;

public:
    // Member functions
    string getPostFixEquation(string st);
    double calculate(string st);
    static int priority(char ch); // Static member function
    bool isOperator(char ch);
    static double doOperator(char ch, double n1, double n2);
};

#endif
