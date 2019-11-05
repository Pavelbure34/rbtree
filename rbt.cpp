#include "rbt.h"

/*
  This is implementation file for rbt.h
  Coded by Alistaire and Kaite.
*/

template<class T>//constructor #3
node<T>::node(T* item, node<T>* p, node<T>* r, node<T>* l){
    if (item != NULL)
      key = new T(*item);
    else
      key = NULL;
    this->p = p;
    this->r = r;
    this->l = l;
}

template<class T>//destructor
node<T>::~node(){
  if (key != NULL)
    delete key;
}

template<class T>
string node<T>::toStr() const{
  /*
    this function prints out node element.

    Pre-Condition:node has to be not-null
  */
  string str = (key != NULL)?"" + to_string(*key):"";
  return str;
}

template<>
string node<string>::toStr() const{
  /*
    this function prints out node element.
    This is special overload for string data type.

    Pre-Condition:node has to be not-null
  */
  string str = (key != NULL)?"" + *key:"";
  return str;
}

template<class T>//default constructor #1
rbt<T>::rbt(){
  root = NULL;  //initiating tree
}

template<class T>//copy constructor #3
rbt<T>::rbt(const rbt<T> &tree){
  root = NULL;              //initiating tree
  deepCopy(tree.getRoot()); //recursively coping node by node
}

template<class T>
void rbt<T>::operator=(rbt<T> &tree){
  /*
    this operator rewrites the tree.
  */
  destroy(root);
  deepCopy(tree.getRoot());
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
  return root == NULL;
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
    
    node<T>* y = NULL;             //set y to NULL
    node<T>* x = root;             //set x to root
    while (x != NULL){
      y = x;
      if (*item < *(x->key))
        x = x->l;
      else
        x = x->r;
    }
    
    node<T>* z = new node<T>(item, y, NULL, NULL); //setting up new node z
    z->colour = R;
    if (y == NULL)                              //if empty tree
      root = z;                                 //z is root
    else if (*item < *(y->key))             //if item smaller than root
      y->l = z;                                 //left tree
    else                                        //if bigger
      y->r = z;                                 //right tree
    insert_fix(z);                              //fix up colour of tree
    cout << 1 << endl;
}

template<class T>
void rbt<T>::insert_fix(node<T> *n){
  /*
    this function fixes up the color of node
    in order to keep the properties of red black tree.

    PreCondition: input node z should not be null.
  */
  if (n->p != NULL)
    cout << "1" << endl;
    while (n->p->colour == R){ //if not root node
      node<T>* y;
      if (n->p == n->p->p->l){
        y = n->p->p->r;
        cout << "a" << endl;
        if (y->colour == R){
          n->p->colour = B;
          y->colour = B;
          n->p->p->colour = R;
          n = n->p->p;
        }else if (n == n->p->r){
          n = n->p;
          leftRotate(n);
        }
        cout << "c" << endl;
        n->p->colour = B;
        n->p->p->colour = R;
        rightRotate(n);
      }else{
        y = n->p->p->l;
        if (n->colour == R){
          n->p->colour = B;
          y->colour = B;
          cout << "f" << endl;
          n->p->p->colour = R;//
          
          n = n->p->p;
        }else if (n == n->p->l){
          n = n->p;
          cout << "e" << endl;
          rightRotate(n);
          cout << "g" << endl;
        }
        cout << "d" << endl;
        n->p->colour = B;
        n->p->p->colour = R;
        leftRotate(n);
      }
    }
  root->colour = B;                     //if root node
}

template<class T>
void rbt<T>::rightRotate(node<T> *n){
  /*
      This function does right rotation of the tree
      on the given node.

      PreCondition: node n should not be null.
  */
  node<T>* y = n->l;   //setting y with right child of x
  n->l = y->r;         //turn x right subtree of y into y leftt subtree
  if(y->r != NULL)
    y->r->p = n;
  y->p = n->p;         //link parent of x to y's
  if(n->p == NULL)
    root = y;
  else if(n == n->p->r)
    n->p->r = y;
  else
    n->p->l = y;
  y->r = n;            //put x on y's right.
  n->p = y;
}

template<class T>
void rbt<T>::leftRotate(node<T> *n){
  /*
      This function does left rotation of the tree
      on the given node.

      PreCondition: node x should not be null.
  */
  node<T>* y = n->r;  //setting y with left child of x
  n->r = y->l;        //turn left subtree of y into x right subtree
  if(y->l != NULL)    
    y->l->p = n;
  y->p = n->p;        //link parent of x to y's
  if(n->p == NULL)
    root = y;
  else if(n == n->p->l)
    n->p->l = y;
  else
    n->p->r = y;
  y->l = n;           //put x on y's left.
  n->p = y;
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
