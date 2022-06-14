#include <stdio.h>
#define CHAR_LIMIT 4
void intToBase(int input, int base, char* baseCar);
char intToChar(int input);

int main() {
    char baseChar[CHAR_LIMIT];
    intToBase(30, 16, baseChar);
    printf("hi");
}

void intToBase(int input, int base, char* baseChar) {
    int charCount = 0;
    int inputCopy = input;
    do {
        charCount++;
    }
    while((inputCopy /= base) > 0);

    for(int i = 0; i < charCount; i++) {
        baseChar[i] = intToChar(input % base);
        input /= base;
        // return 
    }
}

char intToChar(int input) {
    char c = input + '0';
    if (c > '9') {
        c = c - '9' + 'A' - 1;
    }
    return c;
}