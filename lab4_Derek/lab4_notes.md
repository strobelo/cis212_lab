# Debugging C with `gdb`
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

## Your new worst enemy
```C
#include<stdio.h>

int main(int argc, char** argv) {
    int* s = NULL;
    printf("%d\n", *s);
}
```
```
Segmentation fault (core dumped)
```

Bugs can be much less obvious, though, and C doesn't give you much to go on...
```C
int max(int arr_size, int* arr) {
    int max = 1<<31; // min possible value of int
    for(int i = 0; i <= arr_size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
```

## Your new best friend - `gdb`
```
$ gcc -g -W -Wall lab.c -o lab
$ gdb lab
```

### `(gdb) run`
* Run your program inside gdb
* If your program crashes, you can see the line where the crash occurred (VERY helpful)

### `(gdb) break`
* Add a breakpoint
* `run` will run your program UNTIL the breakpoint and then pause
* While paused, you can investigate:
    * `print` a variable's value
    * `set` a `variable` on the fly
* When you want to keep running your program, you can `continue` to run the program or just `step` one line in your code

### `(gdb) watch`
* `gdb` will watch a variable and pause execution any time its value changes

## Debugging Tips / Strategies:
* The Trace-Through
    * Step through your code line-by-line to see where it differs from what you intended
    * Time-consuming, but much easier with `gdb`!
    * Tip: you can save time in `gdb` by using the abbreviations (e.g. `p` instead of `print`)

* The Sanity Check
    * Run an example which you are CONFIDENT will work, and examine your code from SQUARE ONE
    * Example: Let's say your program calculates the mean value of an array of values. 
        * Sanity check would be something UNRELATED to your actual computation, and seemingly much more trivial. For example, did I allocate the correct amount of memory? Does my program work for just 1 number, in the trivial case?
    
    * With `gdb`, just `print`ing values can be a valuable sanity check



## Bug Tier List:
### S - Disaster Waiting to Happen
* Dereferencing pointers to memory you didn't allocate
```C
int* i = NULL;
printf("%d", *i);
```

* Reading Uninitialized memory
```C
int bufsize = 100000;
char* buf = (char*) malloc(bufsize * sizeof(char));
for(int i = 0; i < bufsize; i++) {
    printf("%c", buf[i]);
}
/* ... */
free(buf);
```

* Buffer Overflowing
```C
int bufsize = 100000;
double* buf = (double*) malloc(bufsize * sizeof(float));
for(int i = 0; i < bufsize; i++) {
    buf[i] = 0.0f;
}
/* ... */
free(buf);
```

* Keeping Pointers to Stack Memory Around Too Long
```C
int* foo() {
    int buf[5] = {1, 2, 3, 4, 5};
    return buf;
}

int main() {
    int* f = foo();
    printf("%d", f[4]);
}
```

### A - Hard to find, easy fix
* Semicolon-muted loops
```C
int sum = 0;
for(int i = 0; i < 100; i++); {
    sum += i;
}
printf("%d", sum);
```

* Off By One
```C
int bufsize = 40;
int buf[bufsize];
for(int i = 0; i <= bufsize; i++) {
    buf[i] = i;
}
```




