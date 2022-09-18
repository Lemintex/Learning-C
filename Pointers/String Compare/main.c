#include <stdio.h>

int strcompare(char* s, char* t);

int main() {
    char s[] = "Hello";
    char t[] = "Hello";
    printf("%d", strcompare(s, t));
}

// returns <0 if s occurs alphabetically before t, 0 if s == t, and >0 if s occurs alphabetically after t
int strcompare(char* s, char* t) {
    int i = 0;
    while (*(s+i) == *(t+i)) {
        i++;
        if (!*(s + i) && !*(t + i)) return 0;
    }
    return (*(s+i) - *(t + i));
}