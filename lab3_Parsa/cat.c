#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *Synopsis:
 *
 *	cat [-nbs] [files ...]
 * */

void cat(FILE *fp, int n, int b, int s) {
	
}

int main(int argc, char *argv[]) {
	int n = 0, b = 0, s = 0;
	//./a.out -ns somfile
	int i = 1;
	for(; i < argc; i++){
		if(argv[i][0] == '-') {
			for (int j = 1; argv[i][j] != '\0'; j++) {
				if(argv[i][j] == 'n') {
					n = 1;
				} else if(argv[i][j] == 's') {
					s = 1;
				} else if(argv[i][j] == 'b') {
					b = 1;
				} else {
					fprintf(stderr, "%s: unknown option -- %c\n", argv[0], argv[i][j]);
					exit(1);
				}

			}
		} else {
			break;
		}
	}
	
	if (i == argc) {
		cat(stdin, n, b, s);
	}

	for(; i < argc; i++) {
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			fprintf(stderr, "%s: no such file or directory %s\n", argv[0], argv[i] );
			exit(1);
		}
		cat(fp, n, b, s);
		//I have to close the file now, because it occupies memory, and I have to release that memory
	}
}
