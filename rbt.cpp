#include "rbt.h"

/*
  This is implementation file for rbt.h
  Coded by Alistaire and Kaite.
*/

template<class T>//constructor #3
node<T>::node(T* item, bool *colour, node<T>* p, node<T>* r, node<T>* l){
    if (item != NULL)
      key = new T(*item);
    else
      key = NULL;

    if (colour != NULL)
      this->colour = new bool(*colour);
    else
      this->colour = new bool;

    this->p = p;
    this->r = r;
    this->l = l;
}

template<class T>
string node<T>::toStr() const{
  /*
    this function prints out node element.
    Pre-Condition:node has to be not-null
  */
  string col = (*colour == R)?"r":"b";
  string str = (key != NULL)? to_string(*key) + ":" + col : "";
  return str;
}

template<>
string node<string>::toStr() const{
  /*
    this function prints out node element.
    This is special overload for string data type.

    Pre-Condition:node has to be not-null
  */
  string col = (*colour == R)?"r":"b";
  string str = (key != NULL)? *key + ":" + col : "";
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
  /*
    this function returns the pointer to the value we look for.

    PreCondition: tree has to be initialized.
  */
  if (root == NULL)
    throw new emptyTreeException;

  node<T> *temp = getNode(root, &item);
  if (temp == NULL)
    throw new noKeyException;

  return temp->key;
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

    //setting up new node z
    node<T>* z = new node<T>(item, new bool(R));
    z->p = (y != NULL)?y:NULL;
    z->r = z->l = NULL;
    if (y == NULL)                                     //if empty tree
      root = z;                                        //z is root
    else if (*item < *(y->key)){                       //if item smaller than root
      y->l = z;                                        //left tree
    }else{                                             //if bigger
      y->r = z;                                        //right tree
    }

    insert_fix(z);                                     //fix up colour of tree
}

template<class T>
void rbt<T>::insert_fix(node<T> *n){
  /*
    Repositioning and Recolouring
    PreCondition: input n should not be null.
  */
  bool n_p_colour = (n->p == NULL)?B:*(n->p->colour);//NULL pointer error protection
  while (n_p_colour == R){
    node<T> *y;
    bool y_colour;
    if (n->p == n->p->p->l){ //if parent equals to parent's uncle
      y = n->p->p->l;
      y_colour = (y == NULL)?B:*(y->colour); //NULL pointer error protection
      if (y_colour == R){
        *(n->p->colour) = *(y->colour) = B;
        *(n->p->p->colour) = R;
        n = n->p->p;
      }else if (n == n->p->r){
        n = n->p;
        leftRotate(n);
      }

      if (n->p != NULL){           //NULL pointer error protection
        *(n->p->colour) = B;
        if (n->p->p != NULL){      //NULL pointer error protection
          *(n->p->p->colour) = R;
          rightRotate(n->p->p);
        }
      }
    }else{
      y = n->p->p->r;
      y_colour = (y == NULL)?B:*(y->colour);
      if (y_colour == R){
        *(n->p->colour) = *(y->colour) = B;
        *(n->p->p->colour) = R;
        n = n->p->p;
      }else if (n == n->p->l){
        n = n->p;
        rightRotate(n);
      }

     if (n->p != NULL){             //NULL pointer error protection
        *(n->p->colour) = B;
        if (n->p->p != NULL){      //NULL pointer error protection
          *(n->p->p->colour) = R;
          leftRotate(n->p->p);
        }
      }
    }

    n_p_colour = (n->p == NULL)?B:*(n->p->colour);//updating  n_p_colour
  }

  *(root->colour) = B;                            //making the root as colour black
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

// template<class T>
// void rbt<T>::rbt_transplant(node<T> *u, node<T> *v){
//   /*
//     this function transplant tree for removal.

//     PreCondition: input nodes u and v should not be NULL.
//   */
//   if (u->p == NULL)     //case I:a tree has single node
//     root = v;
//   else if (u == u->p->l)//case II:
//     u->p->l = v;
//   else                  //case III:
//     u->p->r = v;
//   v->p = u->p;          //setting up the parent equal
// }

// template<class T>
// void rbt<T>::remove(T &item){
//   node<T> *z = getNode(item);
//   node<T> *y, *x;
//   if (z == NULL)
//     throw new noKeyException;

//   if (z->l == NULL || z->r == NULL){
//     y = z;
//   }else{
//     y = getNode(*succ(new T(item)));
//   }

//   if (y->l != NULL){
//     x = y->l;
//   }else{
//     x = y->r;
//   }
// }

// template<class T>
// void rbt<T>::remove_fix(node<T>* n){

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
void rbt<T>::operator=(rbt<T> &tree){
  /*
    this operator rewrites the tree.
  */
  destroy(root);
  root = NULL;
  deepCopy(tree.getRoot());
}

template<class T>
void rbt<T>::deepCopy(node<T> *n) {
   /*
        this function recursively copy node by node.
        Pre-condition: input n has to be not NULL.
   */
  if(n != NULL && n->key != NULL){
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
    // cout << *n << endl;
    destroy(n->l); //delete left and right nodes first
    destroy(n->r);
    delete n;      //then delete itself
  }
}

template<class T>
T* rbt<T>::min(node<T>* n) const{
  /*
    this function gets minimum value from the given node.
    Pre-condition: input n should not be null
  */
  if(root == NULL)
    throw new emptyTreeException;

  node<T> *temp = n;
  while(temp->l != NULL) { //go as far left as possible
    temp = temp->l;
  }
  return temp->key;
}

template<class T>
T* rbt<T>::max(node<T>* n) const{
  /*
    this function gets maximum value from the given node.
    Pre-condition: input n should not be null
  */
  if(root == NULL)
    throw new emptyTreeException;

  node<T> *temp = n;
  while(temp->r != NULL) { //go as far left as possible
    temp = temp->r;
  }
  return temp->key;
}

template<class T>
T* rbt<T>::succ(T* key) const{
  /*
    this function gets successor from the given value.
    Pre-condition: input key should not be null
  */
  node<T> *x = getNode(root, key);
  if(x == NULL) {
    throw new noKeyException;
  }
  if(x->r != NULL) {
    return min(x->r); //get min
  }

  node<T> *y = x->p;
  while(y != NULL && x == y->r){
    x = y;
    y = y->p; //advance upwards
  }

  if(y == NULL) {
    throw new KeyError;
  }
  return y->key;
}

template<class T>
T* rbt<T>::predec(T* key) const{
   /*
    this function gets predecessor from the given value.
    Pre-condition: input key should not be null
  */
  node<T> *x = getNode(root, key);
  if(x == NULL) {
    throw new noKeyException;
  }
  if(x->l != NULL) {
    return max(x->l); //get min
  }

  node<T> *y = x->p;
  while(y != NULL && x == y->l){
    x = y;
    y = y->p; //advance upwards
  }

  if(y == NULL) {
    throw new KeyError;
  }
  return y->key;
}

template<class T>
node<T>* rbt<T>::getNode(node<T>* n, T* key) const{
  /*
    this function recursively finds target node
    that contains argument key.

    Precondition: key should not null.
  */
  while(n != NULL && *key != *(n->key)){
    if(*(n->key) < *key)
      n = n->r;
    else
      n = n->l;
  }

  return n;
}


template<class T>
int rbt<T>::bh(node<T>* n) const{
  return 0;//dummy
}

template<class T>
string rbt<T>::getInOrder(node<T>* x) const{
  /*
    this function is helper method for inOrder function.
    utilizing node's toStr() function

    PreCondition: x should not be null.
  */
  if(x == NULL)
    return "";
  else
    return getInOrder(x->l) + x->toStr() + " " + getInOrder(x->r);
}


template<class T>
string rbt<T>::getPreOrder(node<T> *x) const{
  /*
    this function is helper method for preOrder function.
    utilizing node's toStr() function

    PreCondition: x should not be null.
  */
  if(x == NULL)
    return "";
  else
    return x->toStr() + " " + getPreOrder(x->l) + getPreOrder(x->r);
}

template<class T>
string rbt<T>::getPostOrder(node<T> *x) const{
   /*
    this function is helper method for postOrder function.
    utilizing node's toStr() function

    PreCondition: x should not be null.
  */
  if(x == NULL)
    return "";
  else
    return getPostOrder(x->l) + getPostOrder(x->r) +  x->toStr() + " ";
}

template<class T>
string rbt<T>::inOrder() const{
  /*
    this function prints out the tree inOrder travelsal
  */
  return getInOrder(root);
}

template<class T>
string rbt<T>::preOrder() const{
  /*
    this function prints out the tree preOrder travelsal
  */
  return getPreOrder(root);
}


template<class T>
string rbt<T>::postOrder() const{
   /*
    this function prints out the tree postOrder travelsal
  */
  return getPostOrder(root);
}
