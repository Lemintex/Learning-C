#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strappend(const char* s, const char* t);

int main() {
    char* s = "Hello ";
    char* t = "world!";
    char* result;
    result = strappend(s, t);
    printf("%s", result);
}

char* strappend(const char* s, const char* t) {
    char* result;
    int n = 0;
    result = (char*)malloc((strlen(s) + strlen(t) + 1) * sizeof(char));
    for(; *s; n++, s++) {
        *(result+n) = *s;
    }
    for(;*(result+n) = *t; t++, n++);
    return result;
}