#include "rbt.h"

template<class T>
node<T>::node(string color, T* item, node<T>* p, node<T>* r, node<T>* l){
    *key = *item;
    this->color = color;
    this->p = p;
    this->r = r;
    this->l = l;
}



template<class T>//default constructor #1
rbt<T>::rbt(node<T>* n = NULL){
    root = new node<T>(n->color, n->item, n->p, n->r, n->l);
}

template<class T>//copy constructor #2
rbt<T>::rbt(const rbt<T> &tree){
    deepCopy(root);
}

template<class T>//destructor
rbt<T>::~rbt(){
    destory(root);
}

template<class T>
void rbt<T>::insert(T* item){
    /*
        this function insert the item inside.

        Precondition: tree has to be initialized.
    */
    node<T> *x = root;            //set x to root
    node<T> *y = NULL;            //set y to null

    while(x != NULL) {            //in this case, we create the node inside of insert, but in the dictionary, we are inserting pairs
        y = x;                    //for the dictionary implementation, x->getKey() produces a NODE with key/value pairs.
        if(*item < *(x->key))     //if our current node's key is larger, go left of the tree
            x = x -> l;           //set x to left child
        else 
            x = x -> r;           //set x to right child
    }

    node<T> *z = new node<T>();   //create new node with the desired key
    z->p = y;
    z->key = item;

    if(y == NULL)                 //the case that the tree is empty
        this->root = z;           //make z the new root
    else if(*(z->key) < *(y->key))
        y->l = z;                 //if y's key is bigger, z is the left child
    else
        y->r = z;                 //otherwise make z the right child

    z->l = NULL;
    z->r = NULL;
    z->color = R;
    rbt_insert_fix(z);            //fix up the color of nodes
}

template<class T>
void rbt<T>::rbt_insert_fix(node<T>* n){
    while (n->p->color == R){
        if (n->p == z->p->p->l){
            node<T>* y = z->p->p->r;
            if (y->color == R){
                
            }
        }else{

        }
    }
}


template<class T>
void rbt<T>::deepCopy(node<T> *n) {
   /*
        this function recursively copy node by node.

        Pre-condition: input n has to be not NULL.
   */
  if(n != NULL){
    insert(new T(n->key));
    deepCopy(n->getLeft());
    deepCopy(n->getRight());
  }
}

template<class T>
void rbt<T>::destroy(node<T> *n){
  /*
    This function destroys the tree.

    Pre-condition: input n has to be not NULL.
  */
  if (n != NULL) {
    destroy(n->getLeft()); //delete left and right nodes first
    destroy(n->getRight());
    delete n;
  }
}