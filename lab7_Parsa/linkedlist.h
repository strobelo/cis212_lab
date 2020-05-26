#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedlist LinkedList;
struct linkedlist {
	void *self;
	int (*append)(const LinkedList *ll, void *element);
	int (*pop)(const LinkedList *ll, void **element);
	void (*destroy)(const LinkedList *ll, void (*freeFxn)(void *));
};

const LinkedList *create_LinkedList();

#endif
