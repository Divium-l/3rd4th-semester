CC = g++
CFLAGS = -std=c++20

all: BinaryTree.o LinkedList.o Person.o DataStructersCpp.o
	$(CC) BinaryTree.o LinkedList.o Person.o DataStructersCpp.o -o output

LinkedList.o: LinkedList.h LinkedList.cpp
	$(CC) $(CFLAGS) -c LinkedList.h LinkedList.cpp

Person.o: Person.cpp
	$(CC) $(CFLAGS) -c Person.cpp

BinaryTree.o: BinaryTree.h BinaryTree.cpp
	$(CC) $(CFLAGS) -c BinaryTree.h BinaryTree.cpp

DataStructersCpp.o: DataStructersCpp.cpp
	$(CC) $(CFLAGS) -c DataStructersCpp.cpp

clean:
	rm *.o rm *.gch


