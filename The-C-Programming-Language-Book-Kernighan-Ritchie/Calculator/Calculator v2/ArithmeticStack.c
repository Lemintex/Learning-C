#include <stdio.h>
#include "calculate.h"

#define MAX_STACK_SIZE 100

static int stackIndex = 0;
static double stack[MAX_STACK_SIZE];

// pushes n to the top of the stack
void push(double n) {
    if (stackIndex < MAX_STACK_SIZE) {
        stack[stackIndex] = n;
        stackIndex++;
    }
    else {
        printf("Stack full");
    }
}

// pops and returns the top of the stack
double pop() {
    if (stackIndex > 0) {
        stackIndex--;
        return stack[stackIndex];
    }
    else {  
        printf("Stack empty");
        return 0;
    }
}