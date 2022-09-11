#include <stdio.h>

#define IN  0
#define OUT 1

/*  this is an improved state machine
    by seperating logic into their respective states it becomes
    easier to debug and change
*/
int main() {
    int c;
    int state = OUT;

    printf("Write some words\n");
    while((c = getchar()) != '\n') {
        switch (state) {
        case IN:
            if (c == ' ' || c == '\t') {
                putchar('\n');
                state = OUT;
            }
            else {
                putchar(c);
            }
            break;
        
        case OUT:
            if (c != ' ' && c != '\t') {
                putchar(c);
                state = IN;
            }  
            break;

        default:
            break;
        }        
    }
}