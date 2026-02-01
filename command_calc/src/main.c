#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// pretty ugly code - I just wanted some 'real' example using funciton pointers

int is_int(const char *str) {
    char *endptr;
    strtol(str, &endptr, 10);

    // If endptr points to the end, the whole string was a number
    return (*endptr == '\0');
}

int is_operator(char c) {
    return strchr("+-*/", c) != NULL;
}

int add(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int subt(int a, int b) { return a - b; }
int divi(int a, int b) { return a / b; }

int (*calc)(int, int);

int main(void) {
    char cmds[1000];
    fgets(cmds, 100, stdin);
    size_t len = strlen(cmds);
    if (len > 0 && cmds[len-1] == '\n') {
        cmds[len-1] = '\0';
    }


    int first_num;
    int second_num;
    char operation;
    char *context;

    char *token = strtok_s(cmds, " ", &context);

    int pos = 0;
    int error = 0;
    while (token != NULL && error == 0) {
        switch(pos) {
            case 0:
                if (!is_int(token)) {
                    printf("First param must be a nubmer!\n");\
                    error = 1;
                } else {
                    first_num = atoi(token);
                }
                break;
            case 1:
                if (!is_operator(token[0])) {
                    printf("Second param must be one of: + -\n");
                    error = 2;
                } else {
                    operation = token[0];
                }
                break;
            case 2:
                if (!is_int(token)) {
                    printf("Third param must be a nubmer!\n");
                    error = 3;
                } else {
                    second_num = atoi(token);
                }
                break;
            default:
                break;

        }
        printf("Token: %s\n", token);
        token = strtok_s(NULL, " ", &context);    // Continue splitting
        pos++;
    }
    if (error > 0) {
        printf("Invalid syntex (error %d)", error);
        return 1;
    }

    switch(operation) {
        case '+': calc = add; break;
        case '-': calc = subt; break;
        case '*': calc = mult; break;
        case '/': calc = divi; break;
    }

    printf("%d %c %d = %d", first_num, operation, second_num, calc(first_num, second_num));

    return 0;
}
