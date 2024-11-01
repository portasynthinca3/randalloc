#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void _init_alloc(void);

int main(int argc, const char** argv) {
    _init_alloc();

    const char* static_str = "Hello, World!";
    char* dynamic = malloc(strlen(static_str) + 1);
    strcpy(dynamic, static_str);
    printf("%p: %s", dynamic, dynamic);
}
