#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

/** === Node === **/
typedef struct ll_node Node;
const Node* Node_create(Node* next, void* data, void (*freeValue)(void* i));

/* Node Private Data */
struct ll_node_data {
    Node* next;
    void* item;
    void (*freeValue)(void* e);
};

typedef struct ll_node_data NodeData;

/* Node Dispatch Table */
struct ll_node{
    void* self;
    void (*setNext)(const Node* n, Node* next);
    Node* (*getNext)(const Node* n);
    void (*getValue)(const Node* n, void** dest);
    void (*destroy)(const Node* n);
};

#endif /* _LINKEDLIST_H_ */