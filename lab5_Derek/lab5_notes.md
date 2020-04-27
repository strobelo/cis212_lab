# Heap Memory and Valgrind
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

## Heap Memory
* Do's:
    * Use the correct pointer types with `malloc` 
        ```C
        char* buffer = (char*) malloc (80 * sizeof(char));
        ```
    * Call `free` for **every** call to `malloc`
    * Initialize memory before reading from it
    * Close open files after you are done with them (`fclose`)

* Don'ts:
    * Run off the end of your heap block
    * Use a pointer AT ALL after it has been `free`d
        * Common practice: `NULL` your pointers RIGHT AFTER `free`ing them

But how to detect these issues in debugging?

## Valgrind
Reminder: Compile with `-g` when using debugging programs such as `gdb` or `valgrind`

### What does `valgrind` do?
Valgrind runs `Memcheck`, which will detect any invalid usage of memory in your program. Violations of any of the "do's" and "don'ts" above will be detected by `valgrind`.

### My program works, but `valgrind` gives me issues. Do I really need to fix it?
**YES.**
Programs that contain any memory-usage indiscretions (leaks, use of uninitialized memory, read/write outside allocated memory, etc.) should be treated as **pure evil**, even if they work on your machine. They are *very* likely to cause `Segmentation Fault` in different circumstances.

### To run your program with `valgrind`:
```
$ valgrind ./myprog myarg1 myarg2 ...
```

Common outputs of `valgrind`:
* `Invalid read`: reading outside allocated memory (possibly running off end of block)
* `Invalid write`: writing outside allocated memory (possibly running off end of block)
* `LEAK SUMMARY`: Any lost or still reachable memory is a leak. We want `total heap usage: X allocs` to equal `x frees`, and we want 0 bytes lost, reachable, or suppressed.

The magic phrase we want:

```
All heap blocks were freed -- no leaks are possible
```

### OK, valgrind tells me I have some bytes lost. How do I go about fixing my leak?
Get some more details about where your leaked memory is coming from:
```
$ valgrind --leak-check=full ./myprog myarg1 myarg2 ...
```

Example:
```C
#include<stdio.h>
#include<string.h>

int main() {
    /** Create an nxn matrix of doubles
    */
    int n = 10;
    double** matrix = (double**) malloc(n * sizeof(double*)); // alloc rows of matrix
    for(int i = 0; i < n; i++) {
        matrix[i] = (double*) malloc(n * sizeof(double)); // alloc columns of matrix
        for(int j = 0; j < n; j++) {
            matrix[i][j] = 0; // initialize all matrix values to 0
        }
    }

    /*
     Perform calculations with matrix here
    */

    free(matrix);
}
```

```
$ gcc -g matrix.c -o matrix
$ valgrind ./matrix
```
outputs:
```
==346== HEAP SUMMARY:
==346==     in use at exit: 800 bytes in 10 blocks
==346==   total heap usage: 11 allocs, 1 frees, 880 bytes allocated
==346==
==346== LEAK SUMMARY:
==346==    definitely lost: 800 bytes in 10 blocks
==346==    indirectly lost: 0 bytes in 0 blocks
==346==      possibly lost: 0 bytes in 0 blocks
==346==    still reachable: 0 bytes in 0 blocks
==346==         suppressed: 0 bytes in 0 blocks
==346== Rerun with --leak-check=full to see details of leaked memory
```

We have a leak :( let's get some more info.
```
$ valgrind --leak-check=full ./matrix
```
outputs:
```
==347== 800 bytes in 10 blocks are definitely lost in loss record 1 of 1
==347==    at 0x4C2FB0F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==347==    by 0x1086DE: main (matrix.c:9)
```
Hmm... Line 9 is our inner malloc. Ah! We never `free`'d that one. One `free` per `malloc`, remember?

```C
#include<stdio.h>
#include<string.h>

int main() {
    /** Create an nxn matrix of doubles
    */
    int n = 10;
    double** matrix = (double**) malloc(n * sizeof(double*)); // alloc rows of matrix
    for(int i = 0; i < n; i++) {
        matrix[i] = (double*) malloc(n * sizeof(double)); // alloc columns of matrix
        for(int j = 0; j < n; j++) {
            matrix[i][j] = 0; // initialize all matrix values to 0
        }
    }

    /*
     Perform calculations with matrix here
    */

    for(int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
```

Now let's double check that it's fixed:
```
$ valgrind --leak-check=full ./matrix
```
outputs:
```
==353== HEAP SUMMARY:
==353==     in use at exit: 0 bytes in 0 blocks
==353==   total heap usage: 11 allocs, 11 frees, 880 bytes allocated
==353==
==353== All heap blocks were freed -- no leaks are possible
```

**Nice :)**

### Other notes:
* Valgrind isn't *just* for checking heap memory; ANY invalid memory accesses will be caught by `valgrind`
    ```C
    int main() {
        int buf[100]; // stack memory, no initialization
        printf("%d", buf[40]); // read from uninitialized memory
    }
    ```