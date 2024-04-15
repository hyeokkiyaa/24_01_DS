#include "calculator.h"
using namespace std;

string Calculator::getPostFixEquation(string st)
{

    int length = st.length();
    string number;
    for (int i = 0; i < length; i++)
    {
        number = "";
        int shift = 1;
        if (isdigit(st[i]) || st[i] == '.')
        {
            number += st[i];
            while (isdigit(st[i + shift]) || st[i + shift] == '.')
            {
                number += st[i + shift];
                shift++;
            }
            PostFixEquation += number;
            i += shift;
        }
        else if (st[i] != ' ')
        {
            if (stack->IsEmptyS())
            {
                stack->Push(st[i]);
            }
            else
            {
                if (st[i] == '(')
                {
                    if (priority(stack->Peek() < priority(st[i])))
                    {
                        stack->Push(st[i]);
                    }
                    else
                    {
                        PostFixEquation += stack->Pop();
                    }
                }
            }
        }
    }
    return PostFixEquation;
}

int priority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    default:
        return 3;
    }
}
void setNumber(string)
{
}

double calculate(string)
{
}