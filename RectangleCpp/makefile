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

all: Color.o Font.o LineStyle.o Point.o Rectangle.o Shape.o main.o
	$(CC) Color.o Font.o LineStyle.o Point.o Rectangle.o Shape.o main.o -o output

Color.o: Color.h Color.cpp
	$(CC) $(CFLAGS) -c Color.h Color.cpp

Font.o: Font.h Font.cpp
	$(CC) $(CFLAGS) -c Font.h Font.cpp

LineStyle.o: LineStyle.h LineStyle.cpp
	$(CC) $(CFLAGS) -c LineStyle.h LineStyle.cpp

Point.o: Point.h Point.cpp
	$(CC) $(CFLAGS) -c Point.h Point.cpp

Rectangle.o: Rectangle.h Rectangle.cpp
	$(CC) $(CFLAGS) -c Rectangle.h Rectangle.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm *.o rm *.gch rm output


