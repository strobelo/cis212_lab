#include "scat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scat(FILE *fp, int n, int b, int s) {

  char buffer[BUFSIZ];
  int line = 0;
  int empty = 0; // count number of empty lines
  while (fgets(buffer, BUFSIZ, fp)) {
    if (strcmp(buffer, "\n") == 0)
      empty++;
    else
      empty = 0;
    
    // if s flag specified, print only when you have less than
    // 2 consecutive empty lines
    if (!s || empty < 2) {
      if (b) {
        if (empty)
          printf("\n");
        else {
          line++;
          printf("%6d  %s", line, buffer);
        }

      } else if (n) {
        line++;
        printf("%6d  %s", line, buffer);
      } else
        printf("%s", buffer);
    }
  }
}
