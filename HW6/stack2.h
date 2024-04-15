#ifndef __STACK2_H__
#define __STACK2_H__
#include <iostream>

using namespace std;

typedef double Element2;

class Stack2
{
private:
    int top;
    int max_size;
    Element2 *stack;
public:
    Stack2(int size);         // setting stack
    ~Stack2();                // to delete stack
    void Push2(Element2 item); // insert value
    Element2 Pop2();           // getting value top of the stack
    bool IsFullsS2() const;   // if it is true then stack is full
    bool IsEmptyS2() const;   // if it is true then stack is empty
    void Print2();            // printing elements of the stack, peaking
    Element2 Peek2();
};

#endif