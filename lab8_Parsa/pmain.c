#include<stdio.h>
#include "print.h"

int main() {
  Print *p = Print_create();
  if (p) {
    p->printHello(p);
    p->printBye(p);
    p->destroy(p);
  }
}
