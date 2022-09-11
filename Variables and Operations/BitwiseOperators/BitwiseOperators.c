#include <stdio.h>

unsigned int setBits(unsigned int x, int n, int p, unsigned int y);
unsigned int invertBits(unsigned int x, int n, int p);
unsigned int leftRotate(unsigned int x, int n);

int main() {
    unsigned int a = setBits(218, 3, 3, 170);
    printf("%d\n",a);

    unsigned int b = invertBits(218, 3, 3);
    printf("%d\n", b);

    unsigned int c = leftRotate(16, 2);
    printf("%d\n", c);
}

/*
    takes x and changes n bits from position p (0 is leftmost bit) with n rightmost bits in y
    EXAMPLE
    x = 1111 1111
    y = 1010 1010
    p = 2
    n = 1
    returns 1111 1011

    NOTE: THIS FUNCTION RETURNS 32 BIT UNSIGNED INTEGER
*/
unsigned int setBits(unsigned int x, int n, int p, unsigned int y) {
    //x = 1101 1010 = 218
    //y = 1010 1010 = 170
    unsigned bitmask = ~0; //create a mask with all bits 1                                                  1111 1111
    bitmask = bitmask << n; //shift left n to make rightmost bits 0                                         1111 1000
    bitmask = ~bitmask; //invert to make only n rightmost bits 1                                            0000 0111

    y = y & bitmask; //extract n bits from y by applying mask                                               0000 0010
    y = y << p; //shift y bits left into position                                                           0001 0000
    bitmask = bitmask << p; //reuse bitmask to remove unwanted bits from x by first shifting p              0011 1000
    
    bitmask = ~bitmask; //invert mask to only remove unwanted segment of x                                  1100 0111
    x = x & bitmask; //apply mask to x                                                                      1100 0010

    //now we have an x and y compopnent, to complete the operation they have to be merged
    return x | y; //combine x and y                                                                         0001 0000 | 1100 0010 = 1101 0010 = 210
}

/*
    takes x and inverts n bits from position p (0 is leftmost bit)
    EXAMPLE
    x = 1111 1111
    p = 2
    n = 1
    returns 1111 1011

    NOTE: THIS FUNCTION RETURNS 32 BIT UNSIGNED INTEGER
*/
unsigned int invertBits(unsigned int x, int n, int p) {
    // x = 1101 1010
    unsigned bitmask = ~0; //create a mask withall bits 1                                                   1111 1111
    bitmask = bitmask << n; //shiftn left n to make rightmost bits 0                                        1111 1000
    bitmask = ~bitmask; //invert to make only n rightmost bits 1                                            0000 0111
    bitmask = bitmask << p; //shift left p to position mask correctly                                       0011 1000

    unsigned int flip = x; // copy x for inverse portion                                                    1101 1010
    flip = ~flip; //invert copy                                                                             0010 0101
    flip = flip & bitmask; //apply mask to copy (inverse of x)                                              0010 0000

    bitmask = ~bitmask; //invert mask to remove unwanted bits                                               1100 0111

    x = x & bitmask; //removes unwanted bits from x by applying mask                                        1100 0010
    return x | flip; //combine x and flip                                                                   1100 0010 | 0010 0000 = 1110 0010 
}

/*
    takes x and shifts every bit n spaces to the left
    EXAMPLE
    x = 0110 1111
    n = 1
    returns 1101 1110

    NOTE: THIS FUNCTION RETURNS 32 BIT UNSIGNED INTEGER
*/
unsigned int leftRotate(unsigned int x, int n) {
    unsigned bitmask = ~0; //create a mask with all bits 1
    bitmask = bitmask << 32 - n; //shift mask to left end of integer (only n leftmost bits are 1)
    unsigned carry = x & bitmask; //apply mask to x in new variable
    carry = carry >> 32 - n; //shift leftmost bits back to right

    x = x << n; //shift x left n
    return x | carry; //combine x and carry
}