CC = g++
OF = -o
CF = -c

all: test_rbt

test_rbt: test_rbt.o
	$(CC) $(OF) test_rbt test_rbt.o

test_rbt.o: test_rbt.cpp rbt.h rbt.cpp
	$(CC) $(CF) test_rbt.cpp