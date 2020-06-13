# The minimal makefile setup
----------

```make
P=program_name
OBJECTS=
CFLAGS= -g -Wall -O3
LDLIBS=
CC=c99

$(P): $(OBJECTS)
```

## Differences between `bash` and `make` syntax:
1. __Accessing variables__:
    * __bash:__ `$var`
    * __make:__ `$(var)`
Make requires that any variable names longer than 1 character be given in parentheses.

## Telling `make` about variable values:
### 1. __Setting and exporting__:
```bash
export CFLAGS=' -g -Wall -O3'
export P=program_name
```

This syntax will be sessionwide and these values can be set permanently by adding it to the `.bashrc` file.

Ommitting the `export` directive shortens the variable's lifetime to a single line. `PANTS=kakhi env | grep PANTS` works, but `PANTS=kakhi; env | grep PANTS` won't.

Note that unlike in the shell, variable assignment in the makefile permits spaces around the `=` sign.

### 2. __When calling `make`__:

```bash
make CFLAGS="-g -Wall" # Set a makefile variable. Not visible by child programs called by make
CFLAGS="-g -Wall" make # Set an enviromental variable visible to make and its children.
```

### Default variables in `make`:

* `$@`: Full target filename - Target is NOT source code (e.g. `a.c`), but rather file to be built (e.g. `a.o`)
* `$*`: target file with suffix cut off (e.g. `$*` for `a.o` yields `a`)
* `$^`:

# Environment variables in C
---------------

It is often useful that these enviroment variables be accessible in the c program itself. This functionality is provided by the _C standard library_ `stdlib.h` in the form of the `getenv` function.

```c
#include <stdlib.h>
#include <stdio.h>

// Compiled using gcc env_name_get.c -o env_name_get

int main(){
    char *uname = getenv("MYNAME");
    printf("%s\n", uname);
}
```

This can then be called using:

```bash
MYNAME=victor ./env_name_get
```

# The rules
-------

### `makefile` execution procedure

geeral `makefile` syntax:

```make
target: dependencies
        script
```

1. `make target` is called
2. The listed `dependencies` are checked.
  * If the `target` is a file and
  * If the `dependencies` are all files:
    * If: target newer than all the dependencies __Nothing to do__
    * else: processing of target put on hold, dependencies run or generated (via another target?) and when dependency scripts finished, __target's script executed__

### Default `make` execution

When no target is specified (e.g. the command `make` c.f. `make target` is executed) the first target in file is called.

### Multiple targets

Multiple targets can be specified separated by spaces: `make tgt1 tgt2`

### Implicit rules

Consider the following `makefile`:

```make
P=domath
OBJECTS=addition.o subtraction.o

$(P): $(OBJECTS)
```

`domath`: Program to be compiled

`addition.o, subtraction.o`: object file dependencies.

neither objects are listed as targets in the makefile. __The implicit rule assumes that the `fname.o` file must be compiled from the `fname.c` file__.

Because our `domath` target does not specify a script, GNU make assumes `domath` depends on `domath.o` and that this, in turn, on `addition.o` and `subtraction.o`. _GNU make fills in its default script for linking .o files into an executable._

#### Default script for compiling an `.o` object file from a `.c` source code file:
```
$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $*.
```

#### Default script for building an executable program  from`.o` object files:

```
$(CC) $(LDFLAGS) first.o second.o nth.o $(LDLIBS)
```
