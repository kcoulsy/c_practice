#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    printf("Hello, World!\n");

    // variables
    int a = 10;
    float b = 3.14; // 32 bit float
    char c = 'A';
    double d = 2.718; // 64 bit double

    // print variables
    printf("int a = %d\n", a);
    printf("float b = %f\n", b);
    printf("char c = %c\n", c);
    printf("double d = %lf\n", d);

    printf("\n");

    printf("Input an integer: ");
    int x;

    printf("int x = %d\n", x); // printing before assignment
    scanf_s("%d", &x); // <- &x is a pointer to the memory location of x

    // Input an integer: int x = 32759
    // sd
    // int x = 32759
    // x is positive
    // it didn't break when non int was inputted but it did fail
    // it returned 0 items successfully read and so x was never assigned
    // it printed whatever was in memory at the address of x

    printf("int x = %d\n", x);

    // if else statements simple enough
    if (x > 0) {
        printf("x is positive\n");
    } else if (x < 0) {
        printf("x is negative\n");
    } else {
        printf("x is zero\n");
    }

    printf("\n");

    // same with switch
    switch(x) {
        case 0:
            printf("x is zero\n");
            break;
        case 1:
            printf("x is one\n");
            break;
        default:
            printf("x is not zero or one\n");
            break;
    }

    printf("\n");

    // for loop
    // for (int i = 0; i < x; i++) {
    //     printf("%d ", i);
    // }

    printf("\n");

    // while loops
    // int y = 0;
    // while (y < 10) {
    //     printf("%d ", y);
    //     y++;
    // }

    printf("\n");

    int first = 4;
    int second = 10;
    // arithmatic
    int add = first + second;
    int subtract = first - second;
    int multiply = first * second;
    int divide = first / second;
    int modulus = first % second;

    printf("add = %d\n", add);
    printf("subtract = %d\n", subtract);
    printf("multiply = %d\n", multiply);
    printf("divide = %d\n", divide);
    printf("modulus = %d\n", modulus);

    // logical operators
    bool contained = x > 0 && x < 10;
    bool either = x == 0 || x == 1;
    bool neither = !(x == 0 || x == 1);

    // ternary operator
    int result = x > 0 ? x : -x;


    // pointer safety basics
    // 1. Always initialize variables]
    int some_val = 0;
    printf("%d\n",  some_val);   // undefined behavior
    // habit -> if don't know value set it to 0

    // 2. one variable per decleration
    int* k, j;
    // k is a pointer, j is a regular int

    // 3. match scanf types
    int w;
    scanf_s("%f", &w); // float/int mismatch could cause memory corruption

    // 4 don't assume scanf worked
    int t;
    if (scanf_s("%d", &t) != 1) {
        printf("Invalid input\n");
        t = 0;
    }

    return 0;
}
