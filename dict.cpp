#include "dict.h"
/*
    dict.cpp is the implementation file for dict.h.
    Coded by Alistaire Suh and Katie Masell
*/

pair::pair(string* key, string* value){
    if (key != NULL)
        this->key = new string(*key);
    else
        this->key = NULL;

    if (value != NULL)
        this->value = new string(*value);
    else
        this->value = NULL;
}   

bool pair::operator<(pair &node) const{
    return *(this->key) < *(node.key);
}

bool pair::operator>(pair &node) const{
    return *(this->key) > *(node.key);
}

bool pair::operator==(pair node) const{
    return *(this->key) == *(node.key);
}

bool pair::operator>=(pair &node) const{
    return *(this->key) >= *(node.key);
}

bool pair::operator<=(pair &node) const{
    return *(this->key) <= *(node.key);
}

string pair::toString() const{
    string str = "<" + *key + " : " + *value + ">";
    return str;
}

template<class T>
dictionary<T>::dictionary(){
    this->root = NULL;
}


template<class T>
void dictionary<T>::insert(T *key) { //key is a key value pair
  if(isDuplicate(*key)) {    //check if node key's key is already in the BST
    return;                  //do nothing
  }
  rbt<T>::insert(key);       //otherwise, insert the node into the BST
}


template<class T>
bool dictionary<T>::isDuplicate(T &key){
  try{
    T *hn = get(key); //just node key? or do we overwrite get
   return true;
  }catch(noKeyException *e){
    return false;
  }
}
