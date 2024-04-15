#include "stack.h"

using namespace std;

Stack::Stack(int max_stack_size) // setting stack to use
{
    top = -1;
    max_size = max_stack_size;
    stack = new Element[max_size];
}

Stack::~Stack() // deleting stack class
{
    delete (stack);
}

void Stack::Push(Element item) // inserting value in stack
{
    if (IsFullsS()) // if stack is fulle
    {
        cout << "Stack is full" << endl;
    }
    else // if stack is not full
    {
        stack[++top] = item; // add item
    }
}

Element Stack::Pop() // retrieve item from stack
{
    if (IsEmptyS()) // if it is empty
    {
        cout << "Stack is empty" << endl;
        return (Element)0;
    }
    else // if stack is not empty
    {
        return stack[top--]; // reduce top and return value the top of the stack
    }
}

bool Stack::IsFullsS() const
{
    return (top == max_size - 1); // if it is true then stack is full
}

bool Stack::IsEmptyS() const
{
    return (top == -1); // if it is true then stack is empty
}

void Stack::Print()
{
    for (int i = top; i >= 0; i--) // since it is not popping we just return values that is in the stack
    {
        cout << stack[i] << endl;
    }
}
