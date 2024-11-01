# randalloc
randalloc is a 🚀 **BLAZING FAST**, 🚀 **MEMORY SAFE** and 🚀 **THREAD SAFE**
memory allocator. It works like this:
```c
void* malloc(size_t s) { return (void*)rand(); }
```

Actually, _a bit more_ is required to actually make `rand` work like that. Go
read [`randalloc.c`](https://github.com/portasynthinca3/randalloc/blob/master/randalloc.c),
it's just 36 lines long.

## Run it!
```
git clone https://github.com/portasynthinca3/randalloc.git
cd randalloc
cat main.c # just kinda look at what the code does
sh randalloc.sh
```

## Use it!
  - Yank [`randalloc.c`](https://github.com/portasynthinca3/randalloc/blob/master/randalloc.c)
    from this repo and paste it into your project.
  - Call `_init_alloc` as close to entry as possible.
  - Compile your project with `-Wl,--wrap=malloc -Wl,--wrap=free -Wl,--wrap=realloc`.
  - Enjoy  🚀 **BLAZING FASTNESS**, 🚀 **MEMORY SAFETY** and 🚀 **THREAD
    SAFETY** in your very own project that you chose to write in a legacy
    language!

## Performance
The allocator runs in O(1) time. And that constant is quite small, not gonna lie.

Have I measured it? No. But it's fast; like look at it!

## Memory safety
Assuming you are fortunate enough that your allocations don't overlap, your code
will be memory safe!

## Thread safety
This allocator does not need to take any extra precautions to ensure thread
safety. That not only means it's 🚀 **BLAZING SAFE**, it's also 🚀 **THREAD
FAST**!

Wait, no, I think I might have mixed up something.

## Why?
  - I just discovered the `--wrap` linker flag and my mind was absolutely
    **blown**.
  - I saw the original implementation in someone's Discord status.
  - Yes, I am a little child.

## Licensing
This project is hereby licensed under the [WTFPL](http://www.wtfpl.net/txt/copying/).
