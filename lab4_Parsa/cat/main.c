#include "scat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n = 0, b = 0, s = 0;
  int i = 1;
  for (; i < argc; i++) {
    if (argv[i][0] == '-') {
      for (int j = 1; argv[i][j] != '\0'; j++) {
        if (argv[i][j] == 'n')
          n = 1;
        else if (argv[i][j] == 's')
          s = 1;
        else if (argv[i][j] == 'b')
          b = 1;
        else {
          fprintf(stderr, "%s: unknown option -- %c\n", argv[0], argv[i][j]);
          exit(1);
        }
      }
    } else
      break;
  }

  if (i == argc)
    scat(stdin, n, b, s);

  for (; i < argc; i++) {
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      fprintf(stderr, "%s: no such file or directory %s\n", argv[0], argv[i]);
      exit(1);
    }
    scat(fp, n, b, s);
    fclose(fp);
  }
  exit(0);
}
