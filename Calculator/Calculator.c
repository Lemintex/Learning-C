/*
    a basic single integer calculator that uses reverse polish notation and returns the result
    reverse polish notation means operands precede the operator, so:
    (5 + 1) / (2 + 1) = 2
    is written as:
    5 1 + 2 1 + / = : resulting in 2

    or ((5 + 1) / 2) + 1 = 4
    is written as
    5 1 + 2 / 1 + = : resulting in 4

    this is a first version so doesn't handle input errors, integers > 9, or decimal inputs
*/

#include <stdio.h>
#define MAX_STACK_SIZE 100

// stack variables
int stackIndex = 0;
double stack[MAX_STACK_SIZE];

// stack functions
double push(double n);
double pop();

// calculator logic
double result;
void nextChar(int c);
int numericCheck(int c);

// pushes n to the top of the stack
double push(double n)
{
    if (stackIndex < MAX_STACK_SIZE)
    {
        stack[stackIndex] = n;
        stackIndex++;
        return n;
    }
    else
    {
        printf("Stack full");
        return 0;
    }
}

// pops and returns the top of the stack
double pop()
{
    if (stackIndex > 0)
    {
        stackIndex--;
        return stack[stackIndex];
    }
    else
    {  
        printf("Stack empty");
        return 0;
    }
}

// resets the stack index
void empty()
{
    stackIndex = 0;
}

int main()
{
    int c;
    while ((c = getchar()) !=  '\n')
    {
        if (!numericCheck(c) && c != ' ')
        {
            nextChar(c);
        }
    }
    printf("Result: %.2f.", result);
}

// checks for an operator
// where operand order doesnt matter I decided not to write in shorthand form to improve readability
void nextChar(int c)
{
    double operandA;
    double operandB;
    double product;
    switch (c)
    {
    case '+':
        operandA = pop();
        operandB = pop();
        product = operandA + operandB;
        push(product);
        break;

    case '-':
        operandA = pop();
        operandB = pop();
        product = operandB - operandA;
        push(product);
        break;

    case '*':
        operandA = pop();
        operandB = pop();
        product = operandB * operandA;
        push(product);
        break;

    case '/':
        operandA = pop();
        if (operandA == 0.0)
        {
            printf("Can't divide by 0");
        }
        else
        {
            operandB = pop();
            product = operandB / operandA;
            push(product);
        }
        break;

    case '=':
        result = pop();
        break;

    default:
        break;
    }
}

// checks if c is a numeric character
int numericCheck(int c)
{
    if (c >= '0' && c <= '9')
    {
        push(c - '0');
        return 1;
    }
    return 0;
}