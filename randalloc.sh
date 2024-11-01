#!/usr/bin/env sh
gcc -O0 -g -Wl,--wrap=malloc -Wl,--wrap=free -Wl,--wrap=realloc main.c randalloc.c -o main
./main
