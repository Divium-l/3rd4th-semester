CC = g++
CFLAGS = -std=c++20
NAME = output

SOURCES = source/Color.cpp source/Font.cpp \
		source/Point.cpp source/LineStyle.cpp \
		source/Rectangle.cpp main.cpp \

HEADERS = include/Color.h include/Font.h \
		include/LineStyle.h include/LineType.h \
		include/Object.h include/Point.h \
		include/Rectangle.h include/Colors.h\

OBJECTS = $(SOURCES:.cpp = .o)

$(NAME): $(OBJECTS) $(HEADERS)
	$(CC) -c $< -o $@

all: Color.o Font.o LineStyle.o Point.o Rectangle.o main.o
	$(CC) Color.o Font.o LineStyle.o Point.o Rectangle.o main.o -o output

Color.o: include/Color.h source/Color.cpp
	$(CC) $(CFLAGS) -c include/Color.h source/Color.cpp

Font.o: include/Font.h source/Font.cpp
	$(CC) $(CFLAGS) -c include/Font.h source/Font.cpp

LineStyle.o: include/LineStyle.h source/LineStyle.cpp
	$(CC) $(CFLAGS) -c include/LineStyle.h source/LineStyle.cpp

Point.o: include/Point.h source/Point.cpp
	$(CC) $(CFLAGS) -c include/Point.h source/Point.cpp

Rectangle.o: include/Rectangle.h source/Rectangle.cpp
	$(CC) $(CFLAGS) -c include/Rectangle.h source/Rectangle.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o rm include/*.gch rm output