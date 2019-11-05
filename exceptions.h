#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class noKeyException: public exception{
public:
    const char* what() const throw(){
        return "key not found in the tree.";
    }
};

class KeyError: public exception {
public:
  const char* what() const throw() {
    return "key error";
  }
};

class DuplicateKeyException: public exception{
public:
    const char* what() const throw(){
        return "key is dupicate.";
    }
};

class emptyTreeException: public exception{
public:
    const char* what() const throw(){
        return "tree is empty.";
    }
};
#endif
