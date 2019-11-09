#ifndef _DICT_H
#define _DICT_H
/*
    dict.h is the abstract Data type file.
    Coded by Alistaire Suh and Katie Masell
*/
#include "rbt.h"  //rbtree based on the BST

class pair{
public:
    string* key;
    string* value;

    pair(string* key = NULL, string* value = NULL);

    bool operator<(pair &node) const;
    bool operator>(pair &node) const;
    bool operator==(pair node) const;
    bool operator>=(pair &node) const;
    bool operator<=(pair &node) const;
    string toString() const;

    friend ostream& operator<<(ostream &o, pair &n){
        //this friend function enables osteam operator.
        o << n.toString();
        return o;
    }
};

template<class T>
class dictionary: public rbt<T> {
private:
    using rbt<T>::root;

public:
    dictionary();

    void insert(T *key);
    using rbt<T>::get;
    // using rbt<T>::itemNum;
    // using rbt<T>::remove;

private:
    bool isDuplicate(T &key);
    
};
#include "dict.cpp"
#endif
