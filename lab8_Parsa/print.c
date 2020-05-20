#include "print.h"
#include <stdio.h>
#include <stdlib.h>

// this is the private data for this ADT
typedef struct data Data;
struct data {
	int counter;
};

// private function
static void printHelloHelper() {
	printf("hello world\n");
}

// the functions need to have the same name, return type and argument types 
// as declared in print.h
void printHello() {
	printHelloHelper();
}

void printBye() {
	printf("Bye world\n");
}

// the methods however can have any name, as long as their return type and argument types are the same
void pHello(Print *p) {
	Data *d = (Data *)p->self;
	d->counter++;
	printHelloHelper();
}
void pBye(Print *p) {
	Data *d = (Data *)p->self;
	d->counter--;
	printf("Bye world\n");
}
void destroy(Print *p) {
	free(p->self);
	free(p);
}

// the template contains all of the methods, in the order that they appear in the dispatch table
Print template = {NULL, pHello, pBye, destroy};

// when you make the constructor ...
Print *Print_create(){

	// you need to malloc the data
	Data *data = (Data *)malloc(sizeof(Data));
	Print *p = NULL;
	if (data != NULL) {
		data->counter = 0;

		// then you need to malloc the dispatch table
		p = (Print *)malloc(sizeof(Print));
		if (p) {

			// now copy over the content of template to the dispatch table 
			*p = template;

			// now set the private data
			p->self = data;
		} else {
			free(data);
		}
	}

	// done now p is an object of Print type that has all the methods
	// notice if any of the malloc operations fail, you have to return NULL
	// otherwise we can return p
	return p;
}
