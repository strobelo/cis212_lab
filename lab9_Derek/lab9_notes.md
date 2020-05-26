# Double-ended queue (deque) with a doubly linked list
Derek Strobel  
CIS212 University of Oregon  
Spring 2020

## Virtual learning survey! Voluntary, but please do participate if you'd like and have time.
https://oregon.qualtrics.com/jfe/form/SV_6XOcvmXTKdlgfmB

## Why deque?
It's a pretty niche data structure. But for some problems, it's really handy. If you're interested, check out https://en.wikipedia.org/wiki/Work_stealing.

Here's another example: We are writing a web browser and keeping a browser history record. We want to automatically record visited sites in order, but also provide a function to clear the oldest hour or day of records. How could we solve this using a deque?

## How deque?
Deque is just a queue where we can access *both* ends. You could kind of think of it like a queue AND a stack at the same time. 

Like most data structures, you can implement it a lot of ways. Today we'll look at (in Python) a doubly-linked list implementation, which is pretty straightforward. However, it's NOT the only implementation, and indeed some implementations (like C++'s `std::deque`) work much differently internally. However, to the end user, they appear to be the same!

## Doubly-Linked List
Singly-linked lists: each node has a `next`
Doubly-linked lists: each node has a `next` **and** a `previous`!

Pros:
* Can now traverse forwards and backwards!

Cons:
* Have to keep 2 pointers per node instead of one. Might not seem like much, but consider that it actually **doubles** the amount of memory overhead vs singly-linked list!

## The Sentinel node

![gandalf](https://www.icge.co.uk/languagesciencesblog/wp-content/uploads/2014/04/you_shall_not_pass1.jpg)

Just a convenient way to keep track of the head and tail of the list!

Sentinel node:
* `next`: Head of list
* `prev`: Tail of list

When the list is empty, the sentinel's `next` and `prev` point back to the sentinel!

Benefits:
* No conditionals when pushing or popping nodes!
* No conditionals when iterating!

All we need is a way to tell the sentinel node apart from regular nodes.

![Sentinel diagram](https://i.stack.imgur.com/nlX1F.png)
