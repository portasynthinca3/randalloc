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

## Contribution Policy
Due to various compliance requirements, you are now required to submit a DNA
test in the CONTRIBUTORS file as part of your first pull request to this
repository. If it is found out that you are more than 50% Russian by blood,
your pull request will be rejected. Additionally, if it is found out that you
are more than 10% Russian by blood, you must provide one of the following or
your pull request will be rejected:
  - A photo of a valid ID or equivalent document proving that you are not
    citizen of the Russian Federation;
  - A photo of a valid residence permit or equivalent document issued by a state
    other than the Russian Federation before Sept. 21st, 2022 (the start of
    mobilization in the Russian Federation);
  - A video of you burning down your Russian ID and passport and subsequently
    singlehandedly overthrowing your dictator.

In addition to all the requirements outlined above, you must prove that you have
never worked for a Russian-based company sanctioned by the glorious U.S. of A.

These requirements are retroactive; shall we ever find out that your status
(family tree, citizenship, residency and/or employment history) now conflicts
one or more of these requirements, your patch will be totally removed from the
git log. No revert commit, no anything. Just undo & force push.

**NOTICE:** This is a humorous policy that won't actually be applied. Of course,
everyone who knows me is aware that I, myself, am Russian by nationality. There
are actual contribution policies like this out in the wild though. I made this
one to poke fun at real anti-Russian discrimination in the open source community
that was sparked by the Linux maintainers ban.
