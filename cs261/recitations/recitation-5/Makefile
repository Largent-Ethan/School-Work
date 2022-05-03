CC=gcc --std=c99 -g

all: time_dynarray_insert

time_dynarray_insert: time_dynarray_insert.c dynarray.o
	$(CC) time_dynarray_insert.c dynarray.o -o time_dynarray_insert

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

clean:
	rm -f *.o time_dynarray_insert
