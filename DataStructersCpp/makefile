CC = g++
CFLAGS = -std=c++20

all: LinkedList.o Person.o DataStructersCpp.o
	$(CC) LinkedList.o Person.o DataStructersCpp.o -o output

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CC) $(CFLAGS) -c LinkedList.h LinkedList.cpp

Person.o: Person.cpp
	$(CC) $(CFLAGS) -c Person.cpp

DataStructersCpp.o: DataStructersCpp.cpp
	$(CC) $(CFLAGS) -c DataStructersCpp.cpp