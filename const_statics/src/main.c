#include "const.h"
#include "static.h"

int main(void) {
    // consts
    const int MAX_SIZE = 100;
    const float PI = 3.14159;
    const char* GREETING = "Hello, World!";
    // these can't be reassigned
    // MAX_SIZE = 1; <- error: assignment of read-only variable 'MAX_SIZE'
    //
    print_string("Hello\n");
    const_pointers();

    char *non_const = "Hello";
    print_str_2(non_const); // both of these can be passed in
    print_str_2(GREETING); // both of these can be passed in

    print_str_3(GREETING); // <- passing a const into the function even though it's not const
    // it will build and run so be careful but at least clang is highlighting it

    // statics
    // int level = log_level; <- Use of undeclared identifier 'log_level';
    log_message("Hello");
    set_log_level(2);
    log_message("World");

    fn_local_static();
    fn_local_static();
    fn_local_static();
    return 0;
}
