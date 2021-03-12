CC = g++
CFLAGS = -g -Wall -Werror -ansi -pedantic -c
LFLAGS = -lsfml-system

all : ED

ED : main.o EditDistance.o
	$(CC) main.o EditDistance.o $(LFLAGS) -o ED

main.o : main.cpp
	$(CC) main.cpp $(CFLAGS) -c

EditDistance.o : EditDistance.cpp EditDistance.hpp
	$(CC) EditDistance.cpp $(CFLAGS) -c

clean :
	rm -rf *.o *.dSYM ED
