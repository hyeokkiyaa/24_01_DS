#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
    Stack *stack = new Stack(5); // stack starts

    stack->Push(1); // value to be inserted in stack
    stack->Push(2); // value to be inserted in stack

    stack->Print(); // printing result but not popping
    return 0;
}