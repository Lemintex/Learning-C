#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strcomp(char* s, char* t);

int main() {
    char* s = "Hello ";
    char* t = "world!";
    char *result = strcomp(s, t);
    printf("%s", result);
}

char *strcomp(char *s, char *t) {
    char *result = (char*)malloc((strlen(s) + strlen(t) + 1) * sizeof(char));
    while (*s) {
        printf("Hi");
        *result++ = *s++;
    }
    while (*result++ = *t++);
    *result = '\0';
    return result;
}