#include <stdio.h>
#include <string.h>
// program returns rightmost index of char c in string s, -1 is not found


int strIndex(char s[], char c);
int main() {
    char s[] = "This is a long string";
    char c = 's';

    printf("%d", strIndex(s, c));
}

int strIndex(char s[], char c) {
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}

// alternative without string library
/*
int strIndex(char s[], char c) {
    int last = -1;
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == c) {
            last = i;
        }
    }
    return last;
}
*/