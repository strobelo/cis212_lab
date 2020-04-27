CC:=gcc
CFLAGS:=-g -W -Wall
TARGET:=scat
OBJECTS:=main.o scat.o
RM:=rm -f

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
scat.o: scat.c

clean:
	$(RM) $(TARGET) $(OBJECTS)
