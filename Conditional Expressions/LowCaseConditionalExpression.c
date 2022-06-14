#include <stdio.h>


int main() {
    const int LIMIT = 1000;
    char lower[LIMIT];
    int c;
    printf("Enter a phrase\n");
    for (int i = 0; ((c = getchar()) != '\n'); i++) {
        lower[i] = (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
    }
    printf("String: %s", lower);
}