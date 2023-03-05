#ifndef _CALC_H
#define _CALC_H
#define NUMBER_FOUND 1

void push(double);
double pop(void);

int getOp(void);
double stringToDouble(void);
int checkSign(char c);

void copyInputToBuffer(char s[]);
int getChar(void);
void ungetChar(void);

#endif