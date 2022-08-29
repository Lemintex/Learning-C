#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAX_OP_SIZE 100
int main()
{
    int type;
    char s[MAX_OP_SIZE];
    int c;
    for (int i = 0; (c = getchar()) != '\n'; i++)
    {
        s[i] = c;
    }
    copyInputToBuffer(s);

    printf("%.3f", stringToDouble("4.35"));
    while((type = getOp(s)) != '\n')
    {
        double operandA;
        double operandB;
        double product;
        switch (type)
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
                product = pop();
                break;

            case NUMBER_FOUND:
                push(stringToDouble(s));
                break;

            default:
                break;
            }
        }
}