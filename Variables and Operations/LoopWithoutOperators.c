#include <stdio.h>

/*
    the book wants me too not use || or &&, so here it is
*/
const int LIMIT = 1000;
int main() {
    char string[LIMIT];
    char c;
    for (int i = 0; i < LIMIT - 1; i++) {
        if ((c=getchar()) ==                '\n') {
            break;
        }
        string[i] = c;
    }
    printf("String:%s", string);
}