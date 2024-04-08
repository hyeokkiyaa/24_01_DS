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
    Stack(int size);
    ~Stack();
    void Push(Element item);
    Element Pop();
    bool IsFullsS() const;
    bool IsEmptyS() const;
    void Print();
};

#endif