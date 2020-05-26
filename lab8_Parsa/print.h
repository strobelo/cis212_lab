#ifndef PRINT_H
#define PRINT_H


// this is a dispatch table
typedef struct print Print;
struct print {
    // this is a pointer to private data
	void *self;

    // these are methods
	void (*printHello)(Print *p);
	void (*printBye)(Print *p);
    void (*destroy)(Print *p); // this is the destructor
};


// these are functions
Print *Print_create(); // this is the constructor

void printHello();

void printBye();

#endif
