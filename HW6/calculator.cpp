#include "calculator.h"

using namespace std;

string Calculator::getPostFixEquation(string st)
{
    Stack *stack = new Stack(100); // Stack 객체 생성, 매개변수 전달
    string PostFixEquation = "";   // PostFixEquation 초기화

    int length = st.length();
    string number;
    for (int i = 0; i < length; i++)
    {
        char ch = st[i];
        if (isspace(ch)) // 공백 문자면 건너뜀
        {
            continue;
        }

        if (isdigit(ch) || ch == '.') // 숫자이거나 소수점이면
        {
            number = "";
            int shift = 1;
            number += ch;
            while (isdigit(st[i + shift]) || st[i + shift] == '.') // 숫자 또는 소수점이면 계속해서 읽음
            {
                number += st[i + shift];
                shift++;
            }
            PostFixEquation += number; // 숫자를 후위 표기법 수식에 추가
            i += shift - 1;            // 숫자 다음 위치로 이동
        }
        else if (isOperator(ch)) // 연산자이면
        {
            while (!stack->IsEmptyS() && priority(stack->Peek()) >= priority(ch)) // 스택의 top에 있는 연산자의 우선순위가 현재 연산자보다 크거나 같을 때까지
            {
                PostFixEquation += stack->Pop(); // 스택에서 pop하여 후위 표기법 수식에 추가
            }
            stack->Push(ch); // 현재 연산자를 스택에 push
        }
        else if (ch == '(') // 여는 괄호이면
        {
            stack->Push(ch); // 스택에 push
        }
        else if (ch == ')') // 닫는 괄호이면
        {
            while (!stack->IsEmptyS() && stack->Peek() != '(') // 여는 괄호가 나올 때까지
            {
                PostFixEquation += stack->Pop(); // 스택에서 pop하여 후위 표기법 수식에 추가
            }
            stack->Pop(); // 여는 괄호를 스택에서 pop하여 제거
        }
    }

    while (!stack->IsEmptyS()) // 스택에 남아 있는 연산자들을 모두 pop하여 후위 표기법 수식에 추가
    {
        PostFixEquation += stack->Pop();
    }

    delete stack; // 동적으로 할당된 메모리 해제
    return PostFixEquation;
}

int Calculator::priority(char ch) // Changed to static member function
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    }
    return 0;
}

bool Calculator::isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Calculator::setNumber(string st)
{
    // 구현 필요
}

double Calculator::calculate(string st)
{
    // 구현 필요
    return 0.0; // 임시 반환 값
}
