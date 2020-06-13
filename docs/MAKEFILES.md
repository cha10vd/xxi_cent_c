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

# Environment variables in C
---------------
