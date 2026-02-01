#include <stdio.h>

int main(void) {
    // in C ints are stored in binary format
    // 5 = 00000101
    // 3 = 00000011

    // bitwise AND (&)
    int result = 5 & 3;
    // result = 00000001
    // why?
    // Row A: 1 0 1
    // Row B: 0 1 1

    // rule: Only if BOTH are 1 → result is 1
    // 1 & 1 = 1
    // 1 & 0 = 0
    // 0 & 1 = 0
    // 0 & 0 = 0
    // Row A: 1 0 1
    // Row B: 0 1 1
    //        x x ✓
    //      = 0 0 1
    //
    // & is often used like a filter:
    // Keep only the bits that are ON in both numbers
    int result2 = 6 & 3; // 0110 & 0011 = 0010 = 2
    printf("%d\n", result2); // 2

    #define READ  (1 << 0)  // 00000001
    #define WRITE (1 << 1)  // 00000010
    #define EXEC  (1 << 2)  // 00000100

    int perms = READ | WRITE; // 00000011

    if (perms & WRITE) {
        printf("Has permissions\n");
        // perms: 00000011
        // WRITE: 00000010
        // ----------------
        // &     : 00000010  (non-zero → true)
    }

    // Example: lowest 4 bits only
    int x = 0b11010110;
    int low = x & 0b00001111;
    printf("low: %d\n", low); // 6 = 0110
    // Why useful?
    // Network packets
    // File formats
    // Hardware registers
    // These often say things like:
    // Bits 0–3 = type
    // Bits 4–7 = flags


    // bitwise OR |
    // 0 | 0 = 0, everything else is 1
    // aka turning bits on - if either has a 1 turn to 1
    int c = 5 | 3; // 000111 = 7
    // Row A: 0 1 0 1
    // Row B: 0 0 1 1
    //      = 0 1 1 1

    // bitwise XOR ^
    // same bits -> 0
    // different -> 1
    int d = 5 ^ 3; // = 6
    // Row A: 0 1 0 1
    // Row B: 0 0 1 1
    //      = 0 1 1 0
    //
    // trick:
    // x ^ x == 0
    // x ^ 0 == x
    // toggle bit 3:
    // x ^= (1 << 3);

    // bitwise NOT ~
    // flips every bit
    // unsigned char x = 5 = 00000101
    // ~x               // 11111010 = 250
    // prefer unsigned when using ~

    // left shift <<
    // shifts bits to the left filling the right with 0s
    // int x = 3;     // 00000011
    // x << 2;        // 00001100 = 12
    // rough equivilant:
    // x << n  ≈  x * (2^n)
    // used for fast multiplication and bitmasks
    // 1 << 5   // 00100000

    // right shift >>
    // shifts to the right
    // int x = 12;    // 00001100
    // x >> 3;        // 00000011
    // unsigned fills with 0
    // signed might fill with 1
    // x >> n  ≈  x / (2^n)


    #define LED_ON   (1 << 3)

    // PORTB |= LED_ON;   // turn LED on
    // PORTB &= ~LED_ON;  // turn LED off

    return 0;
}
