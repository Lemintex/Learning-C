#include <stdio.h>

int length(char* s);

int main() {
    int n = length("Aaron");
    printf("%d", n);
}

int length(char* s) {
    char* p = s;
    while (*p != '\0') {
        p++;
    }
    return (p-s);
}