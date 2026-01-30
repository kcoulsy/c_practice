#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function needs to be declared before they are used - at least the prototype
int add(int a, int b);
void print_array(int arr[], int size);
int max_int(int a, int b);
int min_int(int a, int b);
void mut_array(int arr[]);

int main(void) {
    int sum = add(5, 3);
    printf("Sum: %d\n", sum);

    // arrays
    int numbers[5] = {1, 2, 3, 4, 5};
    numbers[0] = 10;

    for (int i = 0; i < 5; i++) {
        printf("Number %d: %d\n", i + 1, numbers[i]);
    }

    // strings
    char name[] = "Kristian";
    // in memory this looks like this:
    // 'k' 'r' 'i' 's' 't' 'i' 'a' 'n' '\0'
    // \0 marks the end of the string
    printf("Name: %s\n", name);

    // char word[5] = "Hello"; // no space for the \0

    // common string fns
    int len = strlen(name); // does not include the \0
    char name_cpy[len + 1];
    strcpy_s(name_cpy, len + 1, name);
    printf("Name copy: %s\n", name_cpy);

    int result = strcmp(name, name_cpy);
    printf("Comparison result: %d\n", result); // returns 0 if equal

    // scopes
    {
        // int y = 20;
        // variables die wheh the scope ends
    }

    // y is gone here


    int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    print_array(nums, 10);

    char reversed_name[len + 1];
    for (int i = 0; i < len; i++) {
        reversed_name[i] = name[len - i - 1];
    }
    reversed_name[len] = '\0';
    printf("Reversed name: %s\n", reversed_name);

    mut_array(nums);
    print_array(nums, 10);

    return 0;
}

// stack mental model:
// a and b are copied and stored on the stack
// they are then destroyed when the function ends
int add(int a, int b) {
    return a + b;
}

// there is a hidden pointer here
// int arr[] = int *arr
// arrays decay to pointers when passed into arrays
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: %d\n", i + 1, arr[i]);
    }
    // doing something like sizeof would be a bug
    // sizeof(arr); because arr is a pointer
    // that's why we passed the size explicitly
}

int max_int(int a, int b) {
    return a > b ? a : b;
}

int min_int(int a, int b) {
    return a < b ? a : b;
}

void mut_array(int arr[]) {
    arr[0] = 100;
}
