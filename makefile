
MAKEFLAGS += --silent

.PHONY: all main

all:	main

main:	ClassWithAllConstructors.o main.o
	g++ -std=c++2a ClassWithAllConstructors.o main.o -o main

main.o: main.cpp
	g++ -c main.cpp

ClassWithAllConstructors.o: ClassWithAllConstructors.cpp
	g++ -c ClassWithAllConstructors.cpp

clean:
	rm -rf main.o ClassWithAllConstructors.o

wipeout:
	make clean
	rm -rf main
