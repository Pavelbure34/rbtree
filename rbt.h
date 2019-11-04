#ifndef _RBT_H
#define _RBT_H
/*
    rbt.h is the ADT for red black tree.
    Coded by Alistaire Suh and Katie Masell
*/
#include <iostream>
#include <string>
using namespace std;

//represeting red and black with boolean value
#define R true     //true for red
#define B false    //false for black

template<class T>
class node{
public:
    T* key;        //key for tree
    bool color;    //color value for node
    node<T> *p;    //pointer to the parent node
    node<T> * r;   //pointer to the right child node
    node<T>* l;    //pointer to the left child node

    node();                               //default constructor #1          
    node(bool color, T* key,              //constructor #2
     node<T>* p, node<T>* r, node<T>* l);
    node(bool color);                     //constructor #3
    // ~node();                              //destructor

    string toStr() const;
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
    void rightRotate(node<T> *n);                //right rotate the tree   
    void leftRotate(node<T> *n);                 //left rotate the tree
    void rbt_transplant(node<T> *u, node<T> *v); //transplant tree
    string getInOrder(node<T> *x) const;         //helper function for walks 
    string getPreOrder(node<T> *x) const;
    string getPostOrder(node<T> *x) const;
    void destroy(node<T> *n);                    //helper function for clearing memory.
    void deepCopy(node<T> *n);                   //helper function for copy
    node<T>* getNode(node<T> *n, T key) const;   //returning target node.
    void rbt_insert_fix(node<T>* n);             //helper function for insert
};
#include "rbt.cpp"
#endif
