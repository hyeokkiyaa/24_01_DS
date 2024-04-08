#include "stack.h"

using namespace std;

Stack::Stack(int max_stack_size)
{
    top = -1;
    max_size = max_stack_size;
    stack = new Element[max_size];
}

Stack::~Stack()
{
    delete (stack);
}

void Stack::Push(Element item)
{
    if (IsFullsS())
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        stack[++top] = item;
    }
}

Element Stack::Pop()
{
    if (IsEmptyS())
    {
        cout << "Stack is empty" << endl;
        return (Element)0;
    }
    else
    {
        return stack[top--];
    }
}

bool Stack::IsFullsS() const
{
    return (top == max_size - 1);
}

bool Stack::IsEmptyS() const
{
    return (top == -1);
}