#include<stdio.h>
#include "linkedlist.h"

int main() {
  const LinkedList *ll = create_LinkedList();
  if (ll) {
    printf("appending ...\n");
    for (long i = 0; i < 5; i++) {
        printf("%ld ", i);
        ll->append(ll, (void *)i);
    }
    printf("\npopping ...\n");
    long elm;
    while (ll->pop(ll, (void **)&elm)) {
        printf("%ld ", elm);
    }
    printf("\n");
    ll->destroy(ll, NULL);
  }
}
