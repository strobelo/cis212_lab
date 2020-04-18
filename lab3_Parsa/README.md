This week we started programming in C.  
We started `cat.c`, and how we can parse options in C. We haven't finished it yet, and we are running a little behind. Next week, we have to finish `cat.c`, write a `Makefile` to build our project, and introduce `gdb` and `valgrind`, that are the tools for `c/c++` languages for debugging.
## Resources
To up the pace for next week, please review the `man` pages for `fopen`, `fgets` functions:
```
man fgets
```
You have many functions to read a file, I will be using the `fgets` function, which reads one line at a time from an open file.  
Also I mentioned last week that in practice, especially if your program has many options, you don't want to write an option parser yourself, but you would want to use a library that is usually provided by the language. In C you can use the `getopt` function for parsing arguments. More on that in the man pages:
```
man 3 getopt
```
notice the 3, because this is a section 3 function (C library); if you type just `man getopt`, it will show you section 1, which is a shell command.
