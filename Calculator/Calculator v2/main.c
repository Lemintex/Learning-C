#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

#define MAX_OP_SIZE 100

int main() {
    int type;
    char s[MAX_OP_SIZE];
    int c;
    int i;
    for (i = 0; (c = getchar()) != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';

    // puts the input in the buffer
    copyInputToBuffer(s);

    double product = 0;

    // handle elements in the order needed
    while((type = getOp()) != '\0') {
        double operandA;
        double operandB;
        switch (type) {
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
                if (operandA == 0.0) {
                    printf("Can't divide by 0");
                }
                else {
                    operandB = pop();
                    product = operandB / operandA;
                    push(product);
                }
                break;

            case '=':
                product = pop();
                break;

            case NUMBER_FOUND:
                push(stringToDouble());
                break;

            default:
                break;
        }
    }
    // print the result
    printf("Answer: %.2f", product);
}