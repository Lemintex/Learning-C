#include <stdio.h>
#include <ctype.h>
#include "calculate.h"

// gets next operand or operator
int getOp()
{
    int c = getChar();
    double number = 0.0;
    double decimal = 0.0;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == ' ' || c == '\0' || c == '=')
    {
        return c;
    }
    return NUMBER_FOUND;
}

// converts string s to double and returns it
double stringToDouble()
{
    double number = 0.0;
    double decimal = 0.0;
    int sign = 0;
    ungetChar();
    if (checkSign(getChar()))
    {
        sign = -1;
    }
    else
    {
        ungetChar();
        sign = 1;
    }
    int c;
    for (c = getChar(); c >= '0' && c <= '9'; c = getChar())
    {
        number *= 10;
        number += c - '0';
    }

    if (c == '.')
    {
        double mult = 1.0;
        while ((c = getChar()) >= '0' && c <= '9')
        {
            double p = c - '0';
            mult /= 10;
            decimal += p * mult;
        }
    }
    number += decimal;        
    return number * sign;
}

int checkSign(char c)
{
    if (c == '-')
    {
        return 1;
    }
    return 0;
}