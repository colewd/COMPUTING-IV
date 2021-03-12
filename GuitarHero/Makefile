CC = g++
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lboost_unit_test_framework
CFLAGS = -Wall -Werror -ansi -pedantic -c

all: GuitarHero RBtest GStest

GuitarHero : GuitarHero.o RingBuffer.o GuitarString.o
	$(CC) GuitarHero.o RingBuffer.o GuitarString.o $(LFLAGS) -o GuitarHero

RBtest: test.o RingBuffer.o
	$(CC) test.o RingBuffer.o $(LFLAGS) -o RBtest

GStest: GStest.o GuitarString.o RingBuffer.o
	$(CC) GStest.o GuitarString.o RingBuffer.o $(LFLAGS) -o GStest

GuitarHero.o:	GuitarHero.cpp
	$(CC) GuitarHero.cpp -c

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) RingBuffer.cpp -c

GuitarString.o: GuitarString.cpp GuitarString.hpp
	$(CC) GuitarString.cpp -c

test.o: test.cpp
	$(CC) test.cpp -c

GStest.o: GStest.cpp
	$(CC) GStest.cpp -c

clean:
	rm -f *.o *~ GuitarHero RBtest GStest
