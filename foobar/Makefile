CC = g++
CFLAGS = -Wall -I.

make: foobar.o main.o list.o
	$(CC) $(CFLAGS) -o main main.o foobar.o list.o

foobar.o: foobar.cpp foobar.h
	$(CC) $(CFLAGS) -c foobar.cpp

main.o: main.cpp foobar.h list.h
	$(CC) $(CFLAGS) -c main.cpp

list.o: list.cpp list.h foobar.h
	$(CC) $(CFLAGS) -c list.cpp

clean:
	rm *.o main
