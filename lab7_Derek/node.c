#include "node.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void nodeSetNext(const Node* n, Node* next) {
    NodeData* data = n->self;
    data->next = next;
}

Node* nodeGetNext(const Node* n) {
    NodeData* data = n->self;
    return data->next;
}

void nodeGetValue(const Node* n, void** dest) {
    NodeData* data = n->self;
    (*dest) = data->item;
} 

void nodeDestroy(const Node* n) {

    NodeData* data = n->self;
    Node* next = data->next;
    if(next != NULL) {
        next->destroy(next); // free rest of chain
    }
    if(*data->freeValue != NULL) {
        (*data->freeValue)(data->item); // free value
    } // else do nothing
    free(data); // free data
    free((void*)n); // free dispatch table

}


static Node node_template = {
    NULL, nodeSetNext, nodeGetNext, nodeGetValue, nodeDestroy
};

const Node* Node_create(Node* next, void* item, void (*freeValue)(void* i)) {
    Node* node = (Node*) malloc (sizeof(Node));
    if(node == NULL) { 
        // do nothing
    } else {
        NodeData* data = (NodeData*) malloc(sizeof(NodeData));
        if(data == NULL) {
            free(node);
            node = NULL;
            
        } else {
            *node = node_template;
            data->next = next;
            data->item = item;
            data->freeValue = freeValue;
            node->self = data;
        }
    }
    return node;
}

int main(int argc, char** argv) {
    char* a = "first";
    char* b = "second";
    char* c = "third";

    const Node* cNode = Node_create(NULL, c, NULL);
    const Node* bNode = Node_create((Node*)cNode, b, NULL);
    const Node* aNode = Node_create((Node*)bNode, a, NULL);
    
    Node* head = (Node*) aNode;

    for(Node* n = head; n != NULL; n = n->getNext(n)) {
        char* k;
        n->getValue(n, (void**)&k);
        printf("%s\n", k);
    }

    head->destroy(head);
}