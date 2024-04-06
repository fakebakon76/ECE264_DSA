CC = g++
CFLAGS = -Wall -I. -w

make: main.o
	$(CC) $(CFLAGS) -o main main.o

main.o: main.cpp Node.h SimpleList.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o main
