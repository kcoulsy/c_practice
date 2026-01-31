
#include <stdio.h>

// there are no exceptions in C, but we can use error codes to indicate errors

const int ERR_FILE_OPEN = -1;
const int ERR_PARSE = -2;
const int NO_ERROR = 0;

int read_int_from_file(const char *path, int *out_value) {
    FILE *f = fopen(path, "r");
    if (!f) {
        return ERR_FILE_OPEN; // e.g., error opening file
    }

    if (fscanf(f, "%d", out_value) != 1) {
        fclose(f);
        return ERR_PARSE; // parse error
    }

    fclose(f);
    return NO_ERROR; // success
}

void example_error(void) {
    int value;
    int err = read_int_from_file("number.txt", &value);
    if (err == NO_ERROR) {
        printf("Read value: %d\n", value);
    } else if (err == ERR_FILE_OPEN) {
        printf("Failed to open file\n");
    } else if (err == ERR_PARSE) {
        printf("Failed to parse integer\n");
    }
}


int process_two_files(const char *a, const char *b) {
    FILE *fa = NULL;
    FILE *fb = NULL;
    int result = -1; // assume error

    fa = fopen(a, "r");
    if (!fa) goto cleanup;

    fb = fopen(b, "w");
    if (!fb) goto cleanup;

    // ... do work, check for errors

    result = 0; // success

cleanup:
    if (fb) fclose(fb);
    if (fa) fclose(fa);
    return result;
}
