#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include "DList.h"

using namespace std;

typedef int Element;
class Stack
{
private:
    DList list;
    
public:
    Stack();         // setting stack
    ~Stack();                // to delete stack
    void Push(Element item); // insert value
    Element Pop();           // getting value top of the stack
    Element Peek();
};

#endif