#include <stdio.h>

#define MAX_LENGTH 100

void concat(char* s, char* t, char* result);

int main() {
    char s[] = "hello";
    char t[] = " world";
    char result[MAX_LENGTH];
    concat(s, t, result);

    printf("%s", result);
}

void concat(char* s, char* t, char* result) {
    while (*s != '\0') {
        *result++ = *s++;
    }
    while (*t != '\0') {
        *result++ = *t++;
    }
    *result = '\0';
    
}