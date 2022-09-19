#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 20
#define MAX_LENGTH 50
int readlines();
int getline(char* current, int* length);
void printlines(char* lines[], int n);

// because VScode uses /n for 
int main() {
    char* lines[LINES];
    int nlines;
    if ((nlines = readlines(lines)) > 0) {
        printlines(lines, nlines);
    }
}

int readlines(char* lines[]) {
    int n = 0;
    int* length;
    int lastline;
    char current[MAX_LENGTH];
    char* p;
    do {
        lastline = getline(current, length);
        p = (char*) malloc((*length + 1) * sizeof(char));
        current[*length] = '\0';
        strcpy(p, current);
        lines[n++] = p;
    }
    while (lastline);
    return n;
}

int getline(char* current, int* length) {
    *length = 0;
    char c;
    while ((c = getchar()) != '|') {
        if (c == '\n') return 0;
        current[*length] = c;
        *length = *length + 1;
    }
    return 1;
}

void printlines(char* lines[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Line %d: %s\n", i+1, lines[i]);
    }
}