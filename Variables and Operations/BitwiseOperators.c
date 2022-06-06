#include <stdio.h>

unsigned int setBits(unsigned int x, int n, int p, unsigned int y);
unsigned int invertBits(unsigned int x, int n, int p);

int main() {
    unsigned int a = setBits(218, 3, 3, 170);
    printf("%d",a);

    unsigned int b = invertBits(218, 3, 3);
    printf("%d", b);
}

/*
    takes x and changes n bits from position p with the bits in y at the same position
*/
unsigned int setBits(unsigned int x, int n, int p, unsigned int y) {

    //x = 1011 0001 = 177
    //y = 0011 0010 = 50
    unsigned bitmask = ~0; //all bits at 1                                                              1111 1111
    bitmask = bitmask << n; //n rightmost bits at 0                                                     1111 1000
    bitmask = ~bitmask; //only n rightmost bits at 1                                                    0000 0111

    y = y & bitmask; //extract n bits from y                                                            0000 0010
    y = y << p; //shift bits p places                                                                   0000 1000
    
    bitmask = bitmask << p; //reusing bitmask to remove unwanted bits from x by first shifting p        0001 1100
    bitmask = ~bitmask; //inverting mask to only remove some of x                                       1110 0011
    x = x & bitmask; //gets the x section                                                               1010 0001

    //now we have an x and y compopnent, to complete the operation they have to be merged
    return x | y;//1010 1001 = 169
}

unsigned int invertBits(unsigned int x, int n, int p) {
    // x = 1110 0010
    unsigned bitmask = ~0; //all bits at 1                                                              1111 1111
    bitmask = bitmask << n; //n rightmost bits at 0                                                     1111 1000
    bitmask = ~bitmask; //only n rightmost bits at 1                                                    0000 0111
    bitmask = bitmask << p; //mask shifted p                                                            0011 1000

    unsigned int flip = x; //x copy                                                                     1110 0010
    flip = ~flip; //inverse of x                                                                        0001 1101
    flip = flip & bitmask; //apply mask to inverse of x                                                 0001 1000

    // bitmask = bitmask << p; //reuse bitmask by to remove n bits at p by shifting p                      0001 1100
    bitmask = ~bitmask; //inverse of mask to remove unwanted bits                                       1110 0011

    x = x & bitmask; //removes unwanted bits from x                                                     1110 0010
    return x | flip; //1111 1010 
}