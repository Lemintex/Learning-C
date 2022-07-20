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