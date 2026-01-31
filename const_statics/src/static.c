#include "static.h"
#include <stdio.h>

static int log_level = 0; // only visible in this file

static void write_prefix(void) {  // only callable inside this file
    printf("[LOG%d] ", log_level);
}

void set_log_level(int level) {
    log_level = level;
}

void log_message(const char *message) {
    write_prefix();
    printf("%s\n", message);
}

void fn_local_static(void) {
    static int count = 0; // initialized once, persists across calls
    printf("Count: %d\n", ++count);
}

// notes:
// statics are not stored on the stack, but in the data segment of the program
// so we should only use them for state data that needs to live for
// the whole program's lifetime, not just for the duration of a function call.
