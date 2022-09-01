# the compiler: gcc for C program, define as g++ for C++
CC = g++
GTEST = /usr/local/lib/libgtest.a

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall -std=c++20

# The build target
TARGET = main


all: main LIFO_test_main FIFO_test_main

main: main.o
	$(CC) $(CFLAGS) main.o $(GTEST) -o main

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp

LIFO_test_main: LIFO_test.o LIFO_test_main.o
	$(CC) $(CFLAGS) LIFO_test.o LIFO_test_main.o $(GTEST) -o LIFO_test_main

LIFO_test_main.o: src/LIFO_test_main.cpp
	$(CC) $(CFLAGS) -c src/LIFO_test_main.cpp

LIFO_test.o: src/LIFO_test.cpp
	$(CC) $(CFLAGS) -c src/LIFO_test.cpp

FIFO_test_main: FIFO_test.o FIFO_test_main.o
	$(CC) $(CFLAGS) FIFO_test.o FIFO_test_main.o $(GTEST) -o FIFO_test_main

FIFO_test_main.o: src/FIFO_test_main.cpp
	$(CC) $(CFLAGS) -c src/FIFO_test_main.cpp

FIFO_test.o: src/FIFO_test.cpp
	$(CC) $(CFLAGS) -c src/FIFO_test.cpp

clean:
	$(RM) *.o main LIFO_test_main FIFO_test_main