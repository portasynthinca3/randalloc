#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define RANDALLOC_SIZE (1*1024*1024)
_Static_assert(RANDALLOC_SIZE < RAND_MAX);

static void* rand_start;

void _init_alloc(void) {
    srand(time(NULL));
    rand_start = sbrk(0);
    sbrk(RANDALLOC_SIZE);
}

void* __wrap_malloc(size_t size) {
    int offset = rand() % RANDALLOC_SIZE;
    return (uint8_t*)rand_start + offset;
}

void __wrap_free(void* ptr) {
    // BLAZING FAST
}

void* __wrap_calloc(size_t nmemb, size_t size) {
    if (size && nmemb > SIZE_MAX / size) {
        errno = ENOMEM;
        return NULL;
    }
    size_t total = nmemb * size;
    void* r = malloc(total);
    if (total) {
        memset(r, '\0', total);
    }
    return r;
}

void* __wrap_realloc(void* ptr, size_t size) {
    return ptr;
}
