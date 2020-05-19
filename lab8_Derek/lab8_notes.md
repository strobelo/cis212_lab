# QA Session and C Tips
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

## Common Questions
* Q: What can you store in the "Generic" ADTs? Anything?
A: They're not *really* generic. They store a `void*`, which on most systems is an 8-byte type (all pointer types are the same size). However, because pointer types are all the same size (just 8-byte numbers - you can print these out and look at them!), you can cast between them without any worries of over or underflowing data. This is the sense in which the "generic" ADTs are generic. 

You can also store values smaller than 8 bytes (like 1-byte `char`s, for example) in them as literal values by just typecasting up to `void*`. If the type you want is bigger than 8 bytes, you'll have to allocate them dynamically on the heap (so the memory is actually not "on" the stack); instead, the things on the stack are pointers to each element.

From Wikipedia:
***Murphy's law** is an adage or epigram that is typically stated as: "Anything that can go wrong will go wrong".*

The point here is, whenever you are storing something in a `void*`, you **must** think carefully about the size of the values going into a `void*` (or indeed during any typecast). Things to think about, and what occurs:
* Underflow: Is the value you are storing smaller than the type you are casting it to? 
    * This is not a big deal, because you have more than enough memory to store the value you want. Usually when you typecast to a larger value the unused bytes are padded as `0` or some filler value.

* Overflow: Is the value you are storing bigger than the type you are casting it to? 
    ```C
    char c
    sscanf("210","%ld",(long*)&c); //BAD
    ```
    * `c` has 1 byte of memory, but by taking its address and casting to `long*` we are essentially telling the compiler "yeah it's okay don't worry, there's definitely 8 bytes on the other end of this pointer!" when there isn't.

