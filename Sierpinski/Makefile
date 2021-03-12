CC = g++
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window
CFLAGS = -Wall -Werror -ansi -pedantic -c

all: sierpinski

sierpinski: main.o sierpinski.o
	$(CC) main.o sierpinski.o $(LFLAGS) -o sierpinski
main.o: main.cpp
	$(CC) main.cpp $(CFLAGS)
sierpinski.o: sierpinski.cpp
	$(CC) sierpinski.cpp $(CFLAGS)

clean:
	rm sierpinski $(OBJ) *~ *.gch *.o -rf
