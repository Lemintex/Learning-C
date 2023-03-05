/*
    NOTE: since visual studio code takes console input as a single line
    this program will use ',' to indicate a new line
    
    EXAMPLE: Did we take it too far?,Take it too far?,Did We chase the rabbit into wonderland? 
*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "it"; /* pattern to search for */
/* find all lines matching pattern */

int main()
{
    char line[MAXLINE];
    int found = 0;
    while (getline(line, MAXLINE) > 0)
    {
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            printf(" | ");
            found++;
        }
    }
    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != ',') {
        s[i] = c;
        i++;
    }
    if (c == ',') {// do not include ','
        s[i] = '\0';
    }
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {// for each character in the string
        j = i;
        k = 0;
        while (t[k] != '\0' && s[j] == t[k])// while the j'th character in the string is equal to the k'th in target 
        {
            j++;
            k++;
        }
        if (k > 0 && t[k] == '\0')// if target was found entirely
        {
            return i;
        }
    }
    return -1;
}