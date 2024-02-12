CC = g++
CFLAGS = -Wall -I.

make: foobar.o main.o
	$(CC) $(CFLAGS) -o main main.o foobar.o

foobar.o: foobar.cpp foobar.h
	$(CC) $(CFLAGS) -c foobar.cpp

main.o: main.cpp foobar.h 
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o main
