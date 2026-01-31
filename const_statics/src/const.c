#include <stddef.h>
#include <stdio.h>

void print_string(const char* str) {
    // we can't dereference and modify a const pointer
    // *str = 'H'; <- error: assignment of read-only variable 'str
    printf("%s\n", str);
    // the data can't change but the point can
    char *str2 = "Hello2";

    // this wont error
    str = str2;
    printf("%s\n", str);
}

void const_pointers(void) {
    int x = 5;
    int y = 10;
    int * const p = &x;
    // p = &y; <- error: assignment of read-only variable 'p'
    *p = 10; // we can modify the data pointed to by the const pointer

    // or we can do both
    const int * const q = &y;
    // q = &x; <- error: assignment of read-only variable 'q'
    // *q = 5; <- error: assignment of read-only variable 'q'
}

size_t count_char(const char *s, char c) {
    size_t count = 0;
    while (*s != '\0') {
        if (*s == c) {
            count++;
        }
        s++;
    }
    return count;
}

void print_str_2(const char *str) {
    printf("%s\n", str);
}

void print_str_3(char *str) {
    printf("%s\n", str);
}
