#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINES 20
#define MAX_LENGTH 50

void storeinput(char input[]);
int readlines(char input[], char *lines[], int sizes[]);
int getline(char input[], int *character, char **line, int *size);
void sortlines(char *lines[], int n);
void printlines(char *lines[], int sizes[], int n);


// because VScode uses '/n' for end of input, I'll use '|' for line seperator
int main() {
    char input[LINES * MAX_LENGTH];
    char* lines[LINES];
    int sizes[LINES];
    int nlines;
    storeinput(input);
    if ((nlines = readlines(input, lines, sizes)) > 0) {
        sortlines(lines, nlines);
        printlines(lines, sizes, nlines);
    }
}

void storeinput(char *input) {
    char c;
    int i;
    for (i = 0; (c = getchar()) != '\n'; i++) {
        input[i] = c;
    }
    input[i] = '\0';
}

int readlines(char input[], char *lines[], int sizes[]) {
    int character = 0;
    int n = 0;
    int lastline;
    do {
        lastline = getline(input, &character, &lines[n], &sizes[n]);
        n++;
    }
    while (lastline);
    return n;
}


int getline(char input[], int *character, char **start, int *size) {
    *size = 0;

    while (input[*character] != '|') {
        if (*size == 0) {
            *start = (char *) &(input[*character]);
        }
        *character += 1;
        *size += 1;
        if (!input[*character]) return 0;
    }
    input[*character] = '\n';
    *character += 1;
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

void printlines(char *lines[], int sizes[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("String %d: %.*s\n", i + 1, sizes[i], lines[i]);
	}
}