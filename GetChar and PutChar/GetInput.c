#include <stdio.h>

int main() {
    int c;
    printf("Enter some text\n");
    while ((c = getchar()) != '\n') {
        putchar(c);
    }
}
