# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -std=c++20

# The build target
TARGET = main


all: main

main: Interface.o main.o FIFO.o
	$(CC) $(CFLAGS) Interface.o main.o FIFO.o -o main

Interface.o: src/Interface.cpp
	$(CC) $(CFLAGS) -c src/Interface.cpp

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

FIFO.o: src/FIFO.cpp
	$(CC) $(CFLAGS) -c src/FIFO.cpp

clean:
	$(RM) *.o main