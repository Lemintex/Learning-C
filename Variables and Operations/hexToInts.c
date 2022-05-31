#include <stdio.h>

#define LIMIT 100

void convertHex(char c[], int values[]);
int hexValue(char c);
enum STATE {PREFIX, FIRST, SECOND};

int main() {
    char hex[LIMIT];
    int values[LIMIT];
    char input;
    int output;
    for (int i = 0; (input = getchar()) != '\n'; i++) {
        hex[i] = input;
    }
    convertHex(hex, values);
    printf("%d", values);
}

void convertHex(char c[], int values[]) {
    int state = PREFIX;
    int v = 0;
    int val = 0;
    for (int i = 0; c[i] != '\n'; i++) {
        switch (state) {
        case PREFIX:
            if (c[i] == '0') {
                if (c[i + 1] == 'x' || c[i + 1] == 'X') {
                    i++;
                    state = FIRST;
                }
            }
            break;
        
        case FIRST:
            val += hexValue(c[i]);
            state = SECOND;
            break;

        case SECOND:
            val = val * 16 + hexValue(c[i]);
            values[v++] = val;
            val = 0;
            state = PREFIX;
            break;
        
        default:
            break;
        }
    }
}

int hexValue(char c) {
    if (c >= 'A' && c <= 'F') {
        c = c - 'A' + 'a';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= '0' && c  <= '9') {
        return c - '0';
    }
    return -1;
}