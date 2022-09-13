#include <stdio.h>
#include "calculate.h"

#define BUFFER_SIZE 100

static int buffer_index = 0;
static char buffer[BUFFER_SIZE];

void copyInputToBuffer(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		buffer[i] = s[i];
	}
	buffer[i] = '\0';
}

int getChar() {
	return buffer[buffer_index++];
}

void ungetChar() {
	buffer_index--;
}