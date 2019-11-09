CC = g++
OF = -o
CF = -c

all: test_rbt test_dict

test_dict: test_dict.o
	$(CC) $(OF) test_dict test_dict.o

test_rbt: test_rbt.o
	$(CC) $(OF) test_rbt test_rbt.o

test_rbt.o: test_rbt.cpp rbt.h rbt.cpp
	$(CC) $(CF) test_rbt.cpp

test_dict.o: test_dict.cpp dict.h dict.cpp rbt.h rbt.cpp
	$(CC) $(CF) test_dict.cpp