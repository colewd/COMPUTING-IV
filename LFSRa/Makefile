CC = g++
LFLAGS = -lboost_unit_test_framework
CFLAGS = -Wall -Werror -ansi -pedantic -c

all: lfsr ps2a

ps2a: LFSR.o test.o
	$(CC) LFSR.o test.o $(LFLAGS) -o ps2a

lfsr: main.o LFSR.o
	$(CC) main.o LFSR.o -o lfsr

main.o: main.cpp
	$(CC) main.cpp $(CFLAGS)
LFSR.o: LFSR.cpp LFSR.hpp
	$(CC) LFSR.cpp $(CFLAGS)
test.o: test.cpp
	$(CC) test.cpp $(CFLAGS)

clean:
	rm -rf *.o *.a *~ lfsr ps2a
