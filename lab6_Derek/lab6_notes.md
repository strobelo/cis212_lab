# Data Structures: Stack
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

## Haven't we already talked a lot about "The Stack (TM)" in C?
Yes. But the call stack of a program is really just one application of the **data structure** known as a **stack**.

Data structures you've used:
* Python:
    * Lists
    * Dictionaries
* C:
    * Arrays
    * ArrayList ADT

## Why don't we just use one data structure for everything? Why do we need different ones?

Data structures are tools, and tools are used for a specific job they're good at. Often times there will be some overlap in what different data structures CAN do; your job as a programmer is to choose the data structure that will work best for what you're trying to do. You CAN use the back of a screwdriver to pound in a nail... but a hammer would make the job much easier.

## The Stack
Stack: **L**ast **I**n **F**irst **O**ut
![stack toy](https://i.pinimg.com/originals/9d/b0/ca/9db0ca4e8adf65d6b572a1e540f18e75.jpg)

### Why is this useful? Seems unnecesarily restrictive.
It comes in handy surprisingly often. Consider this example: we have some strings representing mathematical expressions, like this:

`x + (3 + 5)`

We want to check if this string has valid parenthesization. In other words, there is a `)` for every `(`, and they go in an order that makes sense mathematically (no sets of parentheses are closed before they're opened.)

You can try and implement this without a stack - it's a little tricky. But with a stack, it becomes dead simple. But first... we need a stack!


## Ok. Let's implement in Python 😈
Here are the methods we want to implement for any good stack:
* `__init__`: initialize the internals of our data structure
* `push`: add a new element on top
* `pop`:  remove and retrieve the top element
* `peek`: retrieve (but don't remove) the top element
* `size`: return the number of elements on the stack
* `isEmpty`: determine if the stack is empty
* `clear`: remove all elements and start with an empty stack
* `__repr__`: a nice string representation of our data structure so we can print it out


Now.. back to the parentheses example. Using our stack data structure:

```Py
def test_parentheses(str):
    '''
    (string) -> int
    Uses a stack to determine whether a string expression has valid parenthesization.
    If so, returns the number of pairs of valid parentheses in the string.
    If the string is invalidly parenthesized (too many left parens,
    too many right parens, or in the wrong order), returns -1.
    '''

    stack = Stack() # Initialize an empty stack
    nValid = 0 # Keep a counter of valid pairs of parentheses
    for c in str: # Loop over every character in the expression
        if c == '(':
            stack.push(c) # Push open parens onto the stack
        elif c == ')': # Close parens: Pop from the stack
            if stack.pop() == None: # stack was empty; there was no open paren, so must be invalid
                return -1
            else:
                nValid += 1 # close paren matched to open paren; increment valid counter
    if s.isEmpty():
        return nValid
    else:
        return -1
```

Cool right? Actually, stacks are used all the time in grammar processing. Your favorite C compiler, for example, almost certainly uses a stack to determine parenthesization really similarly to this!

