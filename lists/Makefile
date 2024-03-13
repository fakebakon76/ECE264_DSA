CC = g++
CFLAGS = -Wall -I.

make: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp SimpleList.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o main
