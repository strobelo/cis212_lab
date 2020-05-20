CC=gcc
OBJS=linkedlist.o llmain.o

all: linkedlist

linkedlist: linkedlist.o llmain.o
	$(CC) $^ -o $@

linkedlist.o: linkedlist.c
llmain.o: llmain.c

clean: 
	rm $(OBJS) linkedlist
