#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>

using namespace std;

typedef int Element;

class Stack
{
private:
    int top;
    int max_size;
    Element *stack;

public:
    Stack(int size);         // setting stack
    ~Stack();                // to delete stack
    void Push(Element item); // insert value
    Element Pop();           // getting value top of the stack
    bool IsFullsS() const;   // if it is true then stack is full
    bool IsEmptyS() const;   // if it is true then stack is empty
    void Print();            // printing elements of the stack, peaking
};

#endif