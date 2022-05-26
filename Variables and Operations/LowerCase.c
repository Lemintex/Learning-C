#include <stdio.h>


int main() {
    const int LIMIT = 1000;
    char lower[LIMIT];
    int c;
    printf("Enter a phrase\n");
    for (int i = 0; ((c = getchar()) != '\n'); i++) {
        if (c >= 'A' && c <= 'Z') {
            c = c + 'a' - 'A';
        }
        lower[i] = c;
    }
    printf("String: %s", lower);
}