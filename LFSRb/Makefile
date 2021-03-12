CC = g++
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window
CFLAGS = -Wall -Werror -ansi -pedantic -c

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	$(CC) PhotoMagic.o LFSR.o $(LFLAGS) -o PhotoMagic

PhotoMagic.o: PhotoMagic.cpp
	$(CC) PhotoMagic.cpp $(CFLAGS)
LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) LFSR.cpp $(CFLAGS)

clean:
	rm -rf *.o *.a PhotoMagic
