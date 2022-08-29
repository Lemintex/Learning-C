#ifndef _CALC_H
#define _CALC_H
#define NUMBER_FOUND 0

void push(double);
double pop(void);

int getOp(char[]);
double stringToDouble(char s[]);
int checkSign(char c);

void copyInputToBuffer(char s[]);
int getChar(void);
void ungetChar(int);

#endif