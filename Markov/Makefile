CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic -c
LFLAGS = -lboost_unit_test_framework

all : TextGenerator # MMTest

TextGenerator: TextGenerator.o MarkovModel.o
	$(CC) TextGenerator.o MarkovModel.o -o TextGenerator

MMTest: mmtest.o MarkovModel.o
	$(CC) mmtest.o MarkovModel.o $(LFLAGS) -o MMTest

mmtest.o: mmtest.cpp
	$(CC) mmtest.cpp $(CFLAGS) -c

TextGenerator.o: TextGenerator.cpp
	$(CC) TextGenerator.cpp $(CFLAGS) -c

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
	$(CC) MarkovModel.cpp $(CFLAGS) -c

clean:
	rm -f *.o *~ TextGenerator MMTest
