#include "rbt.h"

/*
  This is implementation file for rbt.h
  Coded by Alistaire and Kaite.
*/

template<class T>//default constructor #1
node<T>::node(){ 
    key = NULL;
    this->color = NULL;
    this->p = NULL;
    this->r = NULL;
    this->l = NULL;
}

template<class T>//constructor #2
node<T>::node(bool color){
    key = NULL;
    this->color = color;
    this->p = NULL;
    this->r = NULL;
    this->l = NULL;
}

template<class T>//constructor #3
node<T>::node(bool color, T* item, node<T>* p, node<T>* r, node<T>* l){
    key = new T(*item);        
    this->color = color;
    this->p = p;
    this->r = r;
    this->l = l;
}

template<class T>//destructor
node<T>::~node(){
  delete key;
}

template<class T>
string node<T>::toStr() const{
  /*
    this function prints out node element.

    Pre-Condition:node has to be not-null
  */
  string str = "" + to_string(*key) + "";
  return str;
}

template<>
string node<string>::toStr() const{
  /*
    this function prints out node element.
    This is special overload for string data type.

    Pre-Condition:node has to be not-null
  */
  string str = "" + *key + "";
  return str;
}

template<class T>//default constructor #1
rbt<T>::rbt(){}

template<class T>//constructor #2
rbt<T>::rbt(node<T>* n){
    root = new node<T>(n->color, n->key, n->p, n->r, n->l);
}

template<class T>//copy constructor #3
rbt<T>::rbt(const rbt<T> &tree){
    deepCopy(root);
}

template<class T>//destructor
rbt<T>::~rbt(){
    destroy(root);
}

template<class T>
bool rbt<T>::empty() const{
  /*
    this function checks if rbt is empty or not.
  */
  return root->toStr() == "";
}

template<class T>
T* rbt<T>::get(T item) const{

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
void rbt<T>::rbt_insert_fix(node<T>* z){
    /*
      this function fixes up the color of node
      in order to keep the properties of red black tree.

      PreCondition: input node z should not be null.
    */
    while (z->p->color == R){
        if (z->p == z->p->p->l){
            node<T>* y = z->p->p->r;
            if (y->color == R){
                z->p->color = B;
                y->color = B;
                z->p->p->color = R;
                z = z->p->p;
            }
           else if(z == z->p->r){
              z = z->p;
              leftRotate(z);
            }
            z->p->color = B;
            z->p->p->color = R;
            rightRotate(z->p->p);
          }
        else{
          node<T>* y = z->p->p->l;
          if (y->color == R){
              z->p->color = B;
              y->color = B;
              z->p->p->color = R;
              z = z->p->p;
          }
         else if(z == z->p->l){
            z = z->p;
            rightRotate(z);
            }
          z->p->color = B;
          z->p->p->color = R;
          leftRotate(z->p->p);
        }
    }
    root->color = B;
}

template<class T>
void rbt<T>::rightRotate(node<T> *x){
  /*
      This function does right rotation of the tree
      on the given node.

      PreCondition: node x should not be null.
  */
  node<T>* y = x->r;   //setting y with right child of x
  x->r = y->l;         //turn x right subtree of y into y leftt subtree
  if(y->l != NULL)
    y->l->p = x;
  y->p = x->p;         //link parent of x to y's
  if(x->p == NULL)
    root = y;
  else if(x == x->p->l)
    x->p->l = y;
  else
    x->p->r = y;
  y->l = x;            //put x on y's right.
  x->p = y;
}

template<class T>
void rbt<T>::rbt_transplant(node<T> *u, node<T> *v){
  /*
    this function transplant tree for removal.

    PreCondition: input nodes u and v should not be NULL.
  */
  if (u->p == NULL)     //case I:a tree has single node
    root = v;
  else if (u == u->p->l)//case II: 
    u->p->l = v;
  else                  //case III:
    u->p->r = v;
  v->p = u->p;          //setting up the parent equal
}

// template<class T>
// void rbt<T>::remove(T &item){
  
// }

template<class T>
void rbt<T>::leftRotate(node<T> *x){
  /*
      This function does left rotation of the tree
      on the given node.

      PreCondition: node x should not be null.
  */
  node<T>* y = x->l;  //setting y with left child of x
  x->l = y->r;        //turn left subtree of y into x right subtree
  if(y->r != NULL)    
    y->r->p = x;
  y->p = x->p;        //link parent of x to y's
  if(x->p == NULL)
    root = y;
  else if(x == x->p->r)
    x->p->r = y;
  else
    x->p->l = y;
  y->r = x;           //put x on y's left.
  x->p = y;
}

template<class T>
void rbt<T>::operator=(rbt<T> &tree){
  /*
    this operator rewrites the tree.
  */
  destroy(root);
  deepCopy(tree.getRoot());
}

template<class T>
node<T>* rbt<T>::getRoot() const{
  /*
    this function returns pointer to the root.

    PreCondition: root should not be null.
  */
  return root;
}

template<class T>
void rbt<T>::deepCopy(node<T> *n) {
   /*
        this function recursively copy node by node.

        Pre-condition: input n has to be not NULL.
   */
  if(n != NULL){
    insert(n->key);
    deepCopy(n->l);
    deepCopy(n->r);
  }
}

template<class T>
void rbt<T>::destroy(node<T> *n){
  /*
    This function destroys the tree.

    Pre-condition: input n has to be not NULL.
  */
  if (n != NULL) {
    destroy(n->l); //delete left and right nodes first
    destroy(n->r);
    delete n;
  }
}
