#include <stdio.h>

#define IN  0
#define OUT 1

/*  this is a bad state machine
    normally you switch the state first and do logic from there
    this improves scalability and readability

    alas, this book wants me to do it this way
*/
int main() {
    int c, state = OUT;

    printf("Write some words");
    while((c = getchar()) != '\n') {
        if (c == ' ' || c == '\t') {
            if (state == IN) {
                putchar('\n');
                state = OUT;
            }
        }
        else {
            state = IN;
            putchar(c);
        }
        
    }
}