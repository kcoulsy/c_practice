
// a normal function - ex: would call with add(1, 2);
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// function pointer declaration
int (*func)(int, int);
// read it inside out
// func is the pointer
// *func = pointer to
// (int, int) = a function taking 2 params both ints
// int returns an int
//
// the parenthesis around *func are important!
// int *func(int, int) would be a regular function that returns an int pointer


int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

int main(void) {

    // both of these are valid
    func = add;
    func = &add;

    int result = func(1, 2);

    result = calculate(1, 2, add);
    result = calculate(1, 2, multiply);
    // Function pointers
    // a function lives in memory
    // a function pointer points to that function in memory
    // aka stores the address

    // so rather than saying store this function directly
    // we say "store WHICH function to call later"


    return 0;
}
