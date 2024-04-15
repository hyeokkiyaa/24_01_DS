#include "stack2.h"

using namespace std;

Stack2::Stack2(int max_stack_size) // setting stack to use
{
    top = -1;
    max_size = max_stack_size;
    stack = new Element2[max_size];
}

Stack2::~Stack2() // deleting stack class
{
    delete (stack);
}

void Stack2::Push2(Element2 item) // inserting value in stack
{
    if (IsFullsS2()) // if stack is fulle
    {
        cout << "Stack is full" << endl;
    }
    else // if stack is not full
    {
        stack[++top] = item; // add item
    }
}

Element2 Stack2::Pop2() // retrieve item from stack
{
    if (IsEmptyS2()) // if it is empty
    {
        cout << "Stack is empty" << endl;
        return (Element2)0;
    }
    else // if stack is not empty
    {
        return stack[top--]; // reduce top and return value the top of the stack
    }
}

Element2 Stack2::Peek2(){
    if (IsEmptyS2()){
        cout << "Stack is empty" << endl;
        return (Element2)0;
    } else {
        return stack[top];
    }
}

bool Stack2::IsFullsS2() const
{
    return (top == max_size - 1); // if it is true then stack is full
}

bool Stack2::IsEmptyS2() const
{
    return (top == -1); // if it is true then stack is empty
}

void Stack2::Print2()
{
    for (int i = top; i >= 0; i--) // since it is not popping we just return values that is in the stack
    {
        cout << stack[i] << endl;
    }
}
