# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target
TARGET = main


all: main

main: Interface.o main.o
	$(CC) Interface.o main.o -o main

Interface.o: src/Interface.cpp
	$(CC) -c src/Interface.cpp

main.o: src/main.cpp
	$(CC) -c src/main.cpp

clean:
	$(RM) *.o main