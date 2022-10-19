#ifndef _CALC_H
#define _CALC_H
#define NUMBER_FOUND 1

// STACK
void push(double);
double pop(void);

// CHARACTER LOGIC
int getOp(void);
double stringToDouble(void);
int checkSign(char c);

// STRING BUFFER
void copyInputToBuffer(char s[]);
int getChar(void);
void ungetChar(void);

#endif