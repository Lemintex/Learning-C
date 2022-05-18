#include <stdio.h>

int main() {
    long nc = 0;
    int c;
    printf("Enter some text\n");
    while ((c = getchar()) != '\n') {
        printf("%d", c);
        nc++;
        // printf("%ld\n", nc);
    }
    printf("Number of characters: %ld\n", nc);
    // return 0;
}
