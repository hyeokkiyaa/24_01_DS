This is a calculator

first making equation to post fixed equation
then calculate.

stack.cpp -> char type (for operator)
stack2.cpp -> double type (for numbers)

calculator.cpp functions
    -> getPostFixEquation(string st) 
        parameter to get value of equation
        fix it to post fixed equation and return the new equation
    -> calculate(string st) 
        parameter would be post fixed equation and calculate the value
    -> priority(char ch)
        give value to operator +,- 1 and *,/ 2
    -> isOperator(char ch)
        return true or false; if it is operator then return true
    -> doOperator(char ch, double n1, double n2)
        do operations for each case 
        