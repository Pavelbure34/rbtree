#ifndef _RBT_H
#define _RBT_H
/*
    rbt.h is the ADT for red black tree.
    Coded by Alistaire Suh and Katie Masell
*/
#include <iostream>
#include <string>
using namespace std;

#define R 1
#define B 0

template<class T>
class node{
public:
    T* key;      //key for tree
    bool color; //color value for node
    node<T> *p;   //pointer to the parent node
    node<T> * r;  //pointer to the right child node
    node<T>* l;    //pointer to the left child node
    node();
    node(bool color, T* key, node<T>* p, node<T>* r, node<T>* l);
    node(bool color);
};


template<class T>
class rbt{
protected:
    node<T> *root;

public:
    rbt();                                       //default constructor #1
    rbt(node<T>* n);                             //constructor #2
    rbt(const rbt<T> &tree);                     //copy constructor #3
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
    void operator=(rbt &tree);                   //assignment operator

protected:
    void rightRotate(node<T> *n);
    void leftRotate(node<T> *n);

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
