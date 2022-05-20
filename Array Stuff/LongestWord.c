#include <stdio.h>

#define OUT 0
#define IN  1

#define MAX_WORD_LENGTH 1000

/*
    prints the longest word in a sentence
    bug if final word is the biggest and followed by '\n'
*/

int main() {
    char longestWord[MAX_WORD_LENGTH];
    char currentWord[MAX_WORD_LENGTH];
    int longestWordLength = 0;
    int state = OUT;

    char c;
    int currentWordLength = 0;
    printf("ENTER\n");
    while ((c = getchar()) != '\n') {
        switch (state) {
        case OUT:
            if (c != ' ' && c != '\t') {
                state = IN;
                currentWordLength = 0;
                currentWord[currentWordLength] = c;
                currentWordLength++;
            }
            break;
        
        case IN:
            if (c == ' ' || c == '\t') {
                if (currentWordLength > longestWordLength) {
                    copyWord(longestWord, currentWord, currentWordLength);
                    longestWordLength = currentWordLength;
                }
                currentWordLength = 0;
                state = OUT;
            }
            else {
                currentWordLength++;
                currentWord[currentWordLength] = c;
            }
            break;

        default:
            break;
        }
    }

    // FIXES ISSUE

    if (currentWordLength > longestWordLength) {
        copyWord(longestWord, currentWord, currentWordLength);
        longestWordLength = currentWordLength;
    }

    printf("Length: %d Word: %s", longestWordLength, longestWord);
}

void copyWord(char to[], char wordToCopy[], int wordLength) { //ideally this int arg isn't needed but for now imma leave it
    for (int i = 0; i <= wordLength; i++) {
        to[i] = wordToCopy[i];
    } 
}