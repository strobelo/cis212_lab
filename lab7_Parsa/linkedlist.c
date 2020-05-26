#include "linkedlist.h"
#include <stdlib.h>

typedef struct node Node;
struct node {
	void *element;
	Node *next;
};

typedef struct lldata LLData;
struct lldata {
	Node *head;
};

int append(const LinkedList *ll, void *element) {
	LLData *d = (LLData *)ll->self;
	Node *n = (Node *)malloc(sizeof(Node));
	if (n == NULL)
		return 0;

	n->element = element;
	n->next = NULL;
	
	if (d->head == NULL) {
		d->head = n;
	} else {
		Node *tmp = d->head;
		while(tmp->next != NULL) {
			tmp = tmp->next;
	LLData *d = (LLData *)ll->self;
		}
		tmp->next = n;
	}

	return 1;
}

int pop(const LinkedList *ll, void **element) {
	LLData *d = (LLData *)ll->self;
	if (d->head == NULL) {
		return 0;
	}
	
	Node *tmp = d->head, *p = NULL;
	while (tmp->next != NULL) {
		p = tmp;
		tmp = tmp->next;
	}
	
	*element = tmp->element;
	if (p == NULL) {
		d->head = NULL;
	} else {
		p->next = NULL;
	}
	return 1;
}

void destroy(const LinkedList *ll, void (*freeFxn)(void*)) {
	LLData *d = (LLData *)ll->self;
	Node *cur = d->head, *tmp = NULL;
	while (cur != NULL) {
		tmp = cur;
		cur = tmp->next;
		if (freeFxn != NULL)
			freeFxn(tmp->element);
		free(tmp);
	}
	free(d);
	free((void *)ll);
}

LinkedList template = {NULL, append, pop, destroy};

const LinkedList *create_LinkedList() {
	LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
	
	if (ll != NULL) {
		LLData *d = (LLData *)malloc(sizeof(LLData));
		if (d != NULL) {
			d->head = NULL;
			*ll = template;
			ll->self = (void *)d;
		} else
			free(ll);
	}

	return ll;
}
