# Scratch project


[![Build Status](https://travis-ci.org/andry-dev/sdl-scratch.svg?branch=master)](https://travis-ci.org/andry-dev/sdl-scratch)
[![Build status](https://ci.appveyor.com/api/projects/status/norpt182g02fyqwc?svg=true)](https://ci.appveyor.com/project/andry-dev/sdl-scratch)

This isn't something serious, this is just a scratch project for an engine and a game

I'll do something here, don't know what

I mean, you probably got what this project is all about:

Random ideas.

Anyway I managed to get ~~Travis-CI~~, Appveyor and CMake to work

# Does this compile on...?

tl;dr: I can't get shit done with Travis because the compilers are too old

To compile on OS X, here are the brew commands:

``` bash
brew install sdl2
brew install sdl2_image
brew install glew
```

To compile on Linux, search on your distro's repo for these packages:

```
sdl2
sdl2_image
glew
```

You also need the development versions.

You need a compiler that supports *at least* C++14:

 * GCC 5 and G++ 5

 * Clang 3.8

If you (unfortunately) use Windows, grab the latest version of VS 2015

Yes, *Visual Studio 2015*, 2013 *won't* work

# Wait, how can you even verify that it compiles?

I'm building all of this on my Linux box, so Linux is covered

Appveyor works, so Windows is covered

The only one that I won't know is OS X; So I have to assume that "Compiles on Linux -> Compiles on OS X"
