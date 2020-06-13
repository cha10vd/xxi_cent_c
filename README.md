# 21st Century C
------------
Work from Ben Klemens's 21st Century C book

### Basic packages:

_These are essential tools for a complete(ish) compilation environment_

* __GDB__ - Debugging
* __Valgrind__ - Memory debugging
* __gprof__ - Profiler
* __make__ - build automation tool
* __pkg-config__ - Library finder
* __Doxygen__ - Document generator
* __Autotools__

### Useful libraries for practice:

_These libraries are employed throughout the course of the book for exercises_

* __libcURL__
* __libGLib__
* __libGSL__
* __libSQLite3__
* __libXML2__

## Steps for compilation

1. Set up variable for compiler flags.
2. Set up variable for libraries to link to.
    * Sometimes, may need distinct variables for __compiletime linking__ and __runtime linking__.
    * Library linking instructions written twice: For _compiler_ and _linker_. At the `compiler` level, the header `#include` declaration will paste in the function declaration, but not the function. The resulting  `*.o` file will contain a reference to a libary function. The `linker` interconnects the reference in the oject to the function in the library.
3. Set up system to use these vars to orchestrate compilation.

## useful compilation flags

* `-g` - Adds necessary symbols for debugging: Variable and function names
* `-std=gnu11` - Allows code conforming to C11 & POSIX standards
* `-O3` - Agressive optimization: May need to be dialled down
* `-Wall` - Adds compiler warnings
* Manual path specification:
    1. Include path: `-I`
    2. Link path: `-L`

__Order matters__: When linking, the object `*.o` MUST be given before the link flags, e.g.:
```
gcc specific.o -lbroad -lgeneral
```

having the object file first gives allows the linker to note unresolved `function`, `structure` and `variable` names. It then goes sequentially through the slecified linked libraries looking for the necessary definitions.

# Further reading
-------------
1 [makefiles](docs/MAKEFILES.md)
