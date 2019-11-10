#ifndef _DICT_H
#define _DICT_H
/*
    dict.h is the abstract Data type file.
    Coded by Alistaire Suh and Katie Masell
*/
#include "rbt.h"  //rbtree based on the BST

template<class S, class T>
class h_pair{
public:
    S* key;
    T* value;

    h_pair(S* key = NULL, T* value = NULL);

    bool operator<(h_pair<S, T> &node) const;
    bool operator>(h_pair<S, T> &node) const;
    bool operator==(h_pair<S, T> node) const;
    bool operator!=(h_pair<S, T> node) const;
    bool operator>=(h_pair<S, T> &node) const;
    bool operator<=(h_pair<S, T> &node) const;
    string toString() const;

    friend ostream& operator<<(ostream &o, h_pair<S, T> &n){
        //this friend function enables osteam operator.
        o << n.toString();
        return o;
    }

    friend stringstream& operator<<(stringstream &s, h_pair<S, T> &n){
        //this friend function enables stringsteam operator.
        s << n.toString();
        return s;
    }
};

template<class T>
class dictionary: public rbt<T>{
private:
    using rbt<T>::root;

public:
    dictionary();
    dictionary(dictionary<T> &dict);
    ~dictionary();

    void insert(T *key);
    using rbt<T>::get;
    using rbt<T>::empty;
    // using rbt<T>::remove;
    
    using rbt<T>::preOrder;     //testing purposes
    using rbt<T>::operator=;    //for copying with assignment operator
    using rbt<T>::getRoot;      //for copy constructor

private:
    bool isDuplicate(T &key);  //preventing duplicate key error
    using rbt<T>::getPreOrder; //testing purposes
    using rbt<T>::deepCopy;    //for copy constructor
    using rbt<T>::destroy;     //for destructor

};
#include "dict.cpp"
#endif
