# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -std=c++20

# The build target
TARGET = main


all: main

main: main.o
	$(CC) $(CFLAGS) main.o -o main

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

clean:
	$(RM) *.o main