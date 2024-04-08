#include <iostream>
#include "stack.h"

using namespace std;

int main(void)
{
    Stack *stack = new Stack(5);

    stack->Push(1);
    stack->Push(2);
    
    stack->Print();
    return 0;
}