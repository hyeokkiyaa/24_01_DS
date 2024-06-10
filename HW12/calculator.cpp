#include "calculator.h"

using namespace std;

string Calculator::getPostFixEquation(string st)
{
    
    int length = st.length(); // length of the string that is got from the user

    string number; // var for number to be changed later

    for (int i = 0; i < length; i++) // one by one as char
    {
        char ch = st[i];
        if (isspace(ch)) // if ch is space then just skip
        {
            continue;
        }

        else if (isdigit(ch) || ch == '.') // if ch is number or . meaning it is changed to be number
        {
            number = "";                                           // reset to null
            int shift = 1;                                         // for index to be added later
            number += ch;                                          // char value added to number as it is just number
            while (isdigit(st[i + shift]) || st[i + shift] == '.') // if the next value is number or . then keep adding
            {
                number += st[i + shift]; // add the value in
                shift++;                 // shift the index
            }
            PostFixEquation += number; // add then complete number into final answer
            PostFixEquation += " ";    // for convenience
            i += shift - 1;            // shifting the loop
        }
        else if (isOperator(ch)) // if it is operator
        {
            while (!stack.empty() && priority(stack.top()) >= priority(ch))
            {                                    // check if the stack is empty or not and if ch's priority is higher
                char charadd = stack.top();
                stack.pop();
                PostFixEquation += charadd; // if not then add to the return answer
                PostFixEquation += " ";
            }
            stack.push(ch); // otherwise just push
        }

        else if (ch == '(') // if it is open parenthesis
        {
            stack.push(ch); // push it to stack
        }
        else if (ch == ')') // if ch is closing parenthesis
        {
            while (!stack.empty() && stack.top() != '(') // until finding open parenthesis
            {
                char charadd = stack.top();
                stack.pop();
                PostFixEquation += charadd; // stack pop and add to result answer
                PostFixEquation += " ";
            }
            stack.pop(); // removing opening parenthesis
        }
    }

    while (!stack.empty()) // the rest in the stack to be pop out
    {
        char charadd = stack.top();
        stack.pop();
        PostFixEquation += charadd;
        PostFixEquation += " ";
    }

    return PostFixEquation;
}

// calculating postfixedequation
double Calculator::calculate(string st)
{
    string number;                    // number to be formed
    double result;                    // returning result
    int length = st.length();         // length of the string that is called

    for (int i = 0; i < length; i++)
    {
        char ch = st[i]; // for convenince set st[i] as ch
        if (ch == ' ')   // if it is space skip
        {
            continue;
        }
        // process for retrieving number
        else if (isdigit(ch) || ch == '.') // number or .
        {
            number = "";
            int shift = 1;
            number += ch;
            while (isdigit(st[i + shift]) || st[i + shift] == '.')
            {
                number += st[i + shift];
                shift++;
            }
            stack2.push(stod(number)); // number to be pushed into the stack
            i += shift - 1;
        }
        else if (isOperator(ch)) // if it is operator
        {
            double a, b; // get two values
            a = stack2.top();
            stack2.pop();
            b = stack2.top();
            
            stack2.pop();
            stack2.push(doOperator(ch, a, b)); // do calculations in each case
        }
    }
    double stacklast = stack2.top();
    result = stacklast; // result to be added
    stack2.pop();
    return result;
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

double Calculator::doOperator(char ch, double n1, double n2)
{
    switch (ch)
    {
    case '+':
        return n2 + n1;
        break;
    case '-':
        return n2 - n1;
        break;
    case '*':
        return n2 * n1;
        break;
    default:
        return n2 / n1;
        break;
    }
}
