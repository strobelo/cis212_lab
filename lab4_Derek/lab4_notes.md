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




