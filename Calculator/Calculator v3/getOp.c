#include <stdio.h>
#include <ctype.h>
#include "calc.h"
int index = 0;

// gets next operand or operator
int getOp(char s[])
{
    int c = s[index];
    while (c == ' ')
    {
        index++;
    }
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        return s[index++];
    }
    return NUMBER_FOUND;
}

// converts string s to double and returns it
double stringToDouble(char s[])
{
    double number = 0.0;
    double decimal = 0.0;
    int sign = 0;
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t')
    {
        i++;
        index++;
    }
    if (checkSign(s[i]) == '-')
    {
        i++;
        index++;
        sign = -1;
    }
    else
    {
        sign = 1;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        number *= 10;
        number += s[i] - '0';
        i++;
        index++;
    }
    if (s[i] == '.')
    {
        double mult = 1.0;
        i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            double p = s[i] - '0';
            mult /= 10;
            decimal += p * mult;
            i++;
            index++;
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