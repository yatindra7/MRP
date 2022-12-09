CC=gcc
CFLAGS=-Wall

librsocket.a: rsocket.o
	ar -rcs librsocket.a rsocket.o

rsocket.o: rsocket.c rsocket.h
	$(CC) $(CFLAGS) -c rsocket.c -lpthread

clean:
	rm -f librsocket.a rsocket.o