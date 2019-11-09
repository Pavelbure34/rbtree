#include "dict.h"
/*
    dict.cpp is the implementation file for dict.h.
    Coded by Alistaire Suh and Katie Masell
*/

template<class S, class T>
h_pair<S, T>::h_pair(S* key, T* value){
    this->key = (key != NULL)?new S(*key):NULL;
    this->value = (value != NULL)?new T(*value):NULL;
}

template<class S, class T>
bool h_pair<S, T>::operator<(h_pair<S, T> &node) const{
    return *(this->key) < *(node.key);
}

template<class S, class T>
bool h_pair<S, T>::operator>(h_pair<S, T> &node) const{
    return *(this->key) > *(node.key);
}

template<class S, class T>
bool h_pair<S, T>::operator==(h_pair<S, T> node) const{
    return *(this->key) == *(node.key);
}

template<class S, class T>
bool h_pair<S, T>::operator!=(h_pair<S, T> node) const{
    return *(this->key) != *(node.key);
}

template<class S, class T>
bool h_pair<S, T>::operator>=(h_pair<S, T> &node) const{
    return *(this->key) >= *(node.key);
}

template<class S, class T>
bool h_pair<S, T>::operator<=(h_pair<S, T> &node) const{
    return *(this->key) <= *(node.key);
}

template<class S, class T>
string h_pair<S, T>::toString() const{
    stringstream s;
    string str;

    if (key != NULL && value != NULL)
        s << "<" << *key << " : " << *value << ">";
    else
        s << "<:>";

    s >> str;
    return str;
}

template<class T>
dictionary<T>::dictionary(){
    this->root = NULL;
}

template<class T>
dictionary<T>::dictionary(dictionary<T> &dict){
    deepCopy(dict.getRoot());
}

template<class T>
dictionary<T>::~dictionary(){
    destroy(this->root);
}


template<class T>
void dictionary<T>::insert(T *key) {
   //key is a key value pair
  if(isDuplicate(*key)) {    //check if node key's key is already in the dict
    return;                  //do nothing
  }
  rbt<T>::insert(key);       //otherwise, insert the node into the dict
}


template<class T>
bool dictionary<T>::isDuplicate(T &key){
  try{
    T *hn = get(key); //just node key? or do we overwrite get
   return true;
  }catch(KeyError *e){
    return false;
  }
}
