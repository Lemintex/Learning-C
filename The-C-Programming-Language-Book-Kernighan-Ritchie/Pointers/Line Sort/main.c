#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 20
#define MAX_LENGTH 50
int readlines();
int getline(char* current, int* length);
void sortlines(char* lines[], int n);
void printlines(char* lines[], int n);

// because VScode uses '/n' for end of input, I'll use '|' for line seperator
int main() {
    char* lines[LINES];
    int nlines;
    if ((nlines = readlines(lines)) > 0) {
        sortlines(lines, nlines);
        printlines(lines, nlines);
    }
}

int readlines(char* lines[]) {
    int n = 0;
    int length = 0;
    int lastline;
    char current[MAX_LENGTH];
    char* p;
    do {
        lastline = getline(current, &length);
        p = (char*) malloc((length + 1) * sizeof(char));
        current[length] = '\0';
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

void sortlines(char* lines[], int n) {
    char* temp;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            for (int j = i - gap; j >= 0; j -= gap) {
                if (strcmp(lines[j], lines[j + gap]) <= 0) break;
                temp = lines[j];
                lines[j] = lines[j + gap];
                lines[j + gap] = temp;
            }
        }
    }
}

void printlines(char* lines[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Line %d: %s\n", i+1, lines[i]);
    }
}