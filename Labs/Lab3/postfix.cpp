// Author:            Michael Beebower
// Assignment Number: Lab 3
// File Name:         postfix.cpp
// Course/Section:    COSC 2436 Section 001
// Date:              3/14/2019
// Instructor:        Michael Miller

/*----------------------------------------------------------------------------------------------------------------------
    Ch. 6, Programming Problem 5, pg. 219

    Design and implement a class of postfix calculators.
    Use the algorithm given in this character to evaluate postfix expressions as entered into the calculator.
    Use only the operators +, -, *, and /.
    Assume that the postfix expressions are syntactically correct.

    Make sure to implement the algorithm (Evaluating Postfix Expressions 6.3.1) as a function. (not as part of main)
    Note while C does have the atoi function it may be easier to simply subtract the char '0' from the char digit.
    Remember to upload all files before submitting.

 ---------------------------------------------------------------------------------------------------------------------*/

#include <iostream>     // std::cout, std::cin
#include <string>       // std::string
#include <stack>        // std::stack

// Function Prototypes
bool evaluatePostfix(std::string str);

int main()
{
    std::string expression;
    bool done = false;

    while (!done) {
        std::cout << "\nEnter a postfix expression: ";
        std::getline(std::cin, expression);
        if (!expression.empty()) {
            if (!evaluatePostfix(expression))
                std::cout << "Invalid postfix expression. Possibly not enough operands and/or too many operators.\n";
        }
        else
            done = true;
    }

    return 0;
}

bool evaluatePostfix(std::string str)
{
    std::stack<int> iStack;
    int operand1, operand2;
    int result = 0;
    std::string operators = "+-*/";
    bool validFlag = true;

    for (char& ch : str)
    {
        //std::cout << ch;
        //std::cout << "(ch - '0'): " << (ch - '0') << std::endl;

        if (isdigit(ch))
        { // Push the value of the operand ch onto the stack;
            //std::cout << ch << " is an operand.\n";
            //operand1 = ch - '0';
            iStack.push(ch - '0');
        }
        else if (operators.find(ch) != -1)   // ch is an operator named op
        {
            //std::cout << ch << " is an operator.\n";
            //std::cout << "\nStack size: " << iStack.size() << std::endl;

            if (iStack.size() > 1)
            {   // Evaluate and push the result
                operand2 = iStack.top();
                // Pop the stack
                iStack.pop();

                operand1 = iStack.top();
                // Pop the stack
                iStack.pop();

                switch (ch) {   // result = operand1 op operand2;
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0) {
                            std::cout << "Divide by zero.\n";
                            validFlag = false;
                            break;
                        }
                        else
                            result = operand1 / operand2;
                        break;
                    default:;
                }

                // Push result onto the stack
                iStack.push(result);
            } else // if stack size is not greater than 1
                {
                    //std::cout << "\nInvalid postfix expression. Possibly not enough operands and/or too many operators.\n";
                    validFlag = false;
                    //if (iStack.size() == 1)
                    //    iStack.pop();   // if invalid expression, empty the stack so that
                    break;
                }
        }
        else    // not a valid operator or operand
        {
            std::cout << ch << " is not a valid operator or operand.\n";
            validFlag = false;
            break;
        } // end if-else

    } // end for loop

    if (iStack.size() == 1 && validFlag)
        std::cout << "Result: " << iStack.top();
    else
        validFlag = false;

    return validFlag;
} // end evaluatePostfix