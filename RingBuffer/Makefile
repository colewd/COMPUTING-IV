CC = g++
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window -lsfml-audio -lboost_unit_test_framework
CFLAGS = -Wall -Werror -ansi -pedantic -c

all: RingBuffer

RingBuffer: test.o RingBuffer.o
	$(CC) test.o RingBuffer.o $(LFLAGS) -o RingBuffer

RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(CC) RingBuffer.cpp -c

test.o: test.cpp
	$(CC) test.cpp -c

clean:
	rm -f *.o *~ RingBuffer
