#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[], char s3[]);

main() {
    const int MAX_SIZE = 10;
    char s1[MAX_SIZE];
    squeeze("aaron", "nobile", s1);
    printf("%s", s1);
}

void squeeze(char s1[], char s2[], char s3[]) {
    bool found;
    int index = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        found = false;
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            s3[index++] = s1[i];
        }
    }
    printf("done");
}