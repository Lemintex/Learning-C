#include <stdio.h>

#define LIMIT 100

/*
    this program takes an input string of hex values
    and prints the integer values

    eg:0x100x31 = 16, 49
    
*/

int convertHex(char c[], int values[]);
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
    int len = convertHex(hex, values);
    for (int i = 0;i < len; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", values[i]);
    }
}

int convertHex(char c[], int values[]) {
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
            int num = hexValue(c[i]);
            if (num >= 0) {
                val += num;
                state = SECOND;
            }
            else {
                state = PREFIX;
            }
            break;

        case SECOND:
            int num = hexValue(c[i]);
            if (num >= 0) {
                val = val * 16 + num;
                values[v++] = val;
                val = 0;
            }
            state = PREFIX;
 
            break;
        
        default:
            break;
        }
    }
    return v;
}

int hexValue(char c) {
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= '0' && c  <= '9') {
        return c - '0';
    }
    return -1;
}