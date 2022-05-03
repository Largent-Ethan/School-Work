CC=gcc --std=c99 -g

all: main

main: main.c list.o
	$(CC) main.c list.o -o main

list.o: list.c list.h
	$(CC) -c list.c

clean:
	rm -f *.o main
