CC=gcc
OBJS=print.o pmain.o

all: hello

hello: print.o pmain.o
	$(CC) $^ -o $@

print.o: print.c
pmain.o: pmain.c
clean: 
	rm $(OBJS) hello 
