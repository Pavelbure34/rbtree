CC = g++
OF = -o
CF = -c

all: test_rbt test_dict

imdb3: imdb3.o
	$(CC) $(OF) imdb3 imdb3.o

test_dict: test_dict.o
	$(CC) $(OF) test_dict test_dict.o

test_rbt: test_rbt.o
	$(CC) $(OF) test_rbt test_rbt.o

imdb3.o: imdb.cpp dict.h dict.cpp rbt.h rbt.cpp
	$(CC) $(CF) imdb3.cpp

test_rbt.o: test_rbt.cpp rbt.h rbt.cpp
	$(CC) $(CF) test_rbt.cpp

test_dict.o: test_dict.cpp dict.h dict.cpp rbt.h rbt.cpp
	$(CC) $(CF) test_dict.cpp