#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>

using namespace std;

typedef int Element;

typedef struct t_list_node
{
    Element data;
    struct t_list_node *link;
} list_node;

class Linked_Stack
{
private:
    list_node* top;
public:
    Linked_Stack();         // setting stack
    ~Linked_Stack();                // to delete stack
    void Push(Element item); // insert value
    Element Pop();           // getting value top of the stack   
    Element Peek();           // printing elements of the stack, peaking
};

#endif