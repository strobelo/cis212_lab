#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

/** === Node === **/

/* Node Private Data */
struct ll_node_data {
    Node* prev;
    Node* next;
    void* data;
};

/* Node Dispatch Table */
typedef struct ll_node{
    
} Node;
const Node* Node_create(Node* prev, Node* next, void* data);


/** === Linked List === **/

/* Node Private Data */
struct linkedlist_data {
    Node* head;
    Node* tail;
};

typedef struct linkedlist {

    int (*get)(const LinkedList* ll, int i, void** out); // get element i
    int (*push_back)(const LinkedList* ll, void* data); // append data to end of 
    void (*destroy)(const LinkedList* ll); // destroy entire linked list

} LinkedList;
const LinkedList* LinkedList_create(Node* head, Node* tail, void (*freeValue)(void *e));



#endif /* _LINKEDLIST_H_ */