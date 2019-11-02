#ifndef _RBT_H
#define _RBT_H
/*
    rbt.h is the ADT for red black tree.
    Coded by Alistaire Suh and Katie Masell
*/
#include <iostream>
#include <string>
using namespace std;

#define R "red"
#define B "black"

template<class T>
class node{
public:
    T* item;      //key for tree
    string color; //color value for node
    node<T> *p;   //pointer to the parent node
    node<T> * r;  //pointer to the right child node
    node<T> l;    //pointer to the left child node

    node(string color = "", T* key = NULL, node<T>* p = NULL, node<T>* r = NULL, node<T>* l = NULL);
};


template<class T>
class rbt{
protected:
    node<T> *root;

public:
    rbt(node<T>* n = NULL);                      //default constructor #1
    rbt(const rbt<T> &tree);                     //copy constructor #2
    ~rbt();                                      //destructor

    bool empty() const;                          //returns true if empty
    T* get(T item) const;                        //returns the pointer to value
    void insert(T* item);                        //insert the item
    void remove(T &item);                        //remove the item
    T* max() const;                              //get the maximum item
    T* min() const;                              //get the minimum item
    T* succ() const;                             //get the successor
    T* predec() const;                           //get the predecessor
    string inOrder() const;                      //in-order travelsal
    string preOrder() const;                     //pre-order travelsal
    string postOrder() const;                    //post-order travelsal
    void operator=(bst &tree);                   //assignment operator

protected:
    void transplant(node<T> *u, node<T> *v);     
    string getInOrder(node<T> *x) const;
    string getPreOrder(node<T> *x) const;
    string getPostOrder(node<T> *x) const;
    void destroy(node<T> *n);
    void deepCopy(node<T> *n); 
    node<T>* getNode(node<T> *n, T key) const;
    void rbt_insert_fix(node<T>* n);
};  

#include "rbt.cpp"
#endif