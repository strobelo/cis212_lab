# CIS212 Lab 3: Basic C programming and Make
Derek Strobel

## `man` : Not just for shell commands

* `man` pages also contain entries for C system calls and library functions
* But we need to install these:
```
$ sudo pacman -S man-pages
```

* `man` sections: (these can be found using `man man`)
    * `man 1 {PAGE}`: Shell commands
    * `man 2 {PAGE}`: C System calls
    * `man 3 {PAGE}`: C Library calls (also called `libc`; you'll use these a lot)
    * ...

* So let's try:
```
$ man 2 getcwd
$ man 3 printf
$ man 3 sqrt
```

## Vim: Setting up for programming
Enable syntax highlighting in Vim:
```
:syntax on
```

## `cat`
Today we're going to implement a barebones `cat` using C. 
```
+ lab3
    - cat.c
    - Makefile
```

Skeleton `cat.c`:
```C
#include<stdio.h> /* Including the header file for libc I/O functions */

int main(int argc, char* argv[]) { /* our main function */

}
```

Skeleton `Makefile`: (NOTE that line 6 has to be indented with an actual TAB character)
```Makefile
CC=gcc # using the GCC compiler
CCFLAGS=-W -Wall # tell GCC that we want to be notified of any warnings in our code
OBJECTS=cat.o # we have only one source file, so it will be compiled into just one object file

# tell Make that our executable depends on having compiled our object file
mycat: $(OBJECTS)
    # tell Make how to compile our executable by linking our object files (there's only one to link in this case, cat.o)
    $(CC) $(CCFLAGS) -o mycat $(OBJECTS)

# tell Make that it should recreate cat.o anytime cat.c is changed
# no rule below this dependency means it will use the default built-in rule (which sees that cat.c is a C file and thus uses the C compiler)
cat.o: cat.c
```

Now we can compile our (empty, useless husk of a) program with:
```
$ make
```

And we can even run our program (which does literally nothing right now) with:
```
$ ./mycat
```

## Testing our code
How to check our code is the same as Linux `cat`?
```
$ diff <(cat file1.txt file2.txt) <(./mycat file1.txt file2.txt)
```