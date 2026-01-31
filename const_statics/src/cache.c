#include <complex.h>
#include <stdlib.h>
#include <stdio.h>

static char *cache = NULL;
static size_t cache_size = 0;

const int ERROR_ALLOCATION_FAILED = -1;

static void cleanup_cache() {
    free(cache);
    cache = NULL;
    cache_size = 0;
}

int cache_init(size_t size) {
    if (cache) { return 0; }
    cache = malloc(size);
    if (!cache) {
        fprintf(stderr, "Failed to allocate cache\n");
        return ERROR_ALLOCATION_FAILED;
    }
    cache_size = size;
    atexit(cleanup_cache); // runs at program termination

    return 0;
}

char *get_cache(size_t *out_size) {
    if (!cache) {
        if (cache_init(1024) != 0) return NULL;
    }
    if (out_size) *out_size = cache_size;
    return cache;
}
