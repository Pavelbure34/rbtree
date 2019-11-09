#ifndef _RBT_H
#define _RBT_H
/*
    rbt.h is the ADT for red black tree.
    Coded by Alistaire Suh and Katie Masell
*/
#include <iostream>
#include <string>
#include <sstream>
#include "exceptions.h"
using namespace std;

//represeting red and black with boolean value
#define R true     //true for red
#define B false    //false for black

template<class T>
class node{
public:
    T* key;                       //pointer to key for tree
    bool* colour;                 //colour value for node
    node<T> *p;                   //pointer to the parent node
    node<T> *r;                   //pointer to the right child node
    node<T>* l;                   //pointer to the left child node

    node(T* item = NULL, bool *colour = NULL, node<T>* p = NULL,
     node<T>* r = NULL, node<T>* l = NULL);  //constructor

    string toStr() const;                    //toString method
    friend ostream& operator<<(ostream &o, node<T> &n){
        //this friend function enables osteam operator.
        o << n.toStr();
        return o;
    }
};

template<class T>
class rbt{
protected:
    node<T> *root; 

public:
    rbt();                                         //default constructor #1
    rbt(const rbt<T> &tree);                       //copy constructor #2
    ~rbt();                                        //destructor

    bool empty() const;                            //returns true if empty
    T* get(T item) const;                          //returns the pointer to value
    void insert(T* item);                          //insert the item
    // void remove(T &item);                          //remove the item

    T* succ(T* key) const;                         //get the successor
    T* predec(T* key) const;                       //get the predecessor

    string inOrder() const;                        //in-order travelsal
    string preOrder() const;                       //pre-order travelsal
    string postOrder() const;                      //post-order travelsal

    void operator=(rbt<T> &tree);                  //assignment operator
    node<T>* getRoot() const;                      //returns the root

protected:
    void insert_fix(node<T>* n);                   //helper function for insert
    // void remove_fix(node<T>* n);                   //helper function for remove
    void rightRotate(node<T> *n);                  //right rotate the tree
    void leftRotate(node<T> *n);                   //left rotate the tree
    // void rbt_transplant(node<T> *u, node<T> *v);   //transplant tree

    T* max(node<T>* n) const;                      //get the maximum item
    T* min(node<T>* n) const;                      //get the minimum item

    string getInOrder(node<T>* x) const;           //helper function for inOrder
    string getPreOrder(node<T> *x) const;          //helper function for preOrder
    string getPostOrder(node<T> *x) const;         //helper function for postOrder

    void destroy(node<T> *n);                     //helper function for clearing memory.
    void deepCopy(node<T> *n);                    //helper function for copy
    node<T>* getNode(node<T>* n, T* key) const;   //returning target node.
};
#include "rbt.cpp"
#endif
