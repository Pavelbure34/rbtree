#include "rbt.h"

/*
  This is implementation file for rbt.h
  Coded by Alistaire and Kaite.
*/

template<class T>//constructor #3
node<T>::node(T* item, bool *colour, node<T>* p, node<T>* r, node<T>* l){
    if (colour != NULL)
      this->colour = new bool(*colour);
    else
      this->colour = new bool;

    if (item != NULL)
      this->key = new T(*item);
    else
      this->key = NULL;

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
  stringstream s;
  string str, col;

  col = (*colour == R)?"r":"b";
  s << *key << ":" << col << "";

  s >> str;
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
  return this->root == NULL;
}

template<class T>
node<T>* rbt<T>::getNode(node<T>* n, T* key) const{
  /*
    this function recursively finds target node
    that contains argument key.

    Precondition: key should not null.
  */
  // cout << *n << endl;
  if (*(n->key) == *key || n == NULL)
    return n;

  if (*(n->key) < *key)
    getNode(n->r, key);
  else
    getNode(n->l, key);
}

template<class T>
T* rbt<T>::get(T item) const{
  /*
    this function returns the pointer to the value we look for.

    PreCondition: tree has to be initialized.
  */
  node<T> *temp = root;
  while (temp != NULL){
    // cout << *temp << endl;
    if (*temp->key == item)
      return temp->key;

    if (*(temp->key) < item)
      temp = temp->r;
    else
      temp = temp->l;
  }

  throw new KeyError;
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
      // cout << "a" << endl;
      y = n->p->p->r;
      y_colour = (y == NULL)?B:*(y->colour); //NULL pointer error protection
      if (y_colour == R){
        //cout << "case 1" << endl;
        *(n->p->colour) = *(y->colour) = B;
        *(n->p->p->colour) = R;
        n = n->p->p;
      }else {
        if (n == n->p->r){
        //cout << "case 2" << endl;
          n = n->p;
          leftRotate(n);
      }

      //cout << "case 3" << endl;
      if (n->p != NULL){           //NULL pointer error protection
        *(n->p->colour) = B;
        if (n->p->p != NULL){      //NULL pointer error protection
          *(n->p->p->colour) = R;
          rightRotate(n->p->p);
        }else
          rightRotate(n->p);
      }
    }
    }else{
      // cout << "b" << endl;
      y = n->p->p->r;
      y_colour = (y == NULL)?B:*(y->colour);
      if (y_colour == R){
        // cout << "case 1" << endl;
        *(n->p->colour) = *(y->colour) = B;
        *(n->p->p->colour) = R;
        n = n->p->p;
      }else {
        if (n == n->p->l){
          // cout << "case 2" << endl;
          n = n->p;
          rightRotate(n);
      }
      // cout << "case 3" << endl;
     if (n->p != NULL){             //NULL pointer error protection
        *(n->p->colour) = B;
        if (n->p->p != NULL){      //NULL pointer error protection
          *(n->p->p->colour) = R;
          leftRotate(n->p->p);
        }else
          leftRotate(n->p);
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
//   /*
//     This funciton removes the node from the tree.
//     PreConditions:
//       1. item should exist in the tree.
//       2. tree should be initiated.
//   */
//   node<T> *y, *z, *x;

//   z = getNod(item);
//   if (z == NULL)
//     throw new noKeyException;

//   y = z;
//   bool y_o_colour = *(y->colour);
//   if (z->l == NULL){
//     x = z->r;
//     rbt_transplant(z, z->r);
//   }else if (z->r == NULL){
//     x = z->l;
//     rbt_transplant(z, z->l);
//   }else{
//     y = getNode(*min(z->r));
//     y_o_colour = *(y->colour);
//     x = y->r;
//     if (y->p == z){
//       x->p = y;
//     }else{
//       rbt_transplant(y, y->r);
//       y->r = z->r;
//       y->r->p = y;
//     }
//     rbt_transplant(z, y);
//     y->l = z->l;
//     y->l->p = y;
//     *(y->colour) = *(z->colour);
//   }

//   if (y_o_colour == B){
//     remove_fix(x);
//   }
// }

// template<class T>
// void rbt<T>::remove_fix(node<T>* n){
//   /*
//     This funciton fix up the node after deletion.
//     PreConditions:
//       1. tree should be initiated.
//       2. n should not be null.
//   */
//   node<T> *w;
//   bool w_l_colour, w_r_colour, n_p_colour, n_colour;
//   while (n != root && *(n->colour) == B){
//     // if (n->p != NULL)
//     //   if (n->p->l != NULL){//null pointer possible
//         if (n == n->p->l){
//           cout << "a" << endl;
//           w = n->p->r;
//           if (*(w->colour) == R){                         //case 1:
//             cout << "case 1" << endl;
//             *(w->colour) = B;
//             *(n->p->colour) = R;
//             leftRotate(n->p);
//             w = x->p->r;
//           }
//           w_l_colour = (w->l == NULL)?B:*(w->l->colour);
//           w_r_colour = (w->r == NULL)?B:*(w->r->colour);
//           if (w_l_colour == B && w_r_colour == B){        //case 2:
//             cout << "case 2" << endl;
//             *(w->colour) == R;
//             n = n->p;
//           }else if (w_r_colour == B){                     //case 3:
//             cout << "case 3" << endl;
//             if (w->l != NULL)
//               *(w->l->colour) = B;
//             *(w->colour) == R;
//             rightRotate(w);
//             w = (n->p == NULL)?n->r:n->p->r;
//           }

//           n_p_colour = (n->p == NULL)?B:*(n->p->colour);
//           *(w->colour) == n_p_colour;                     //case 4:
//           cout << "case 4" << endl;
//           if (n->p != NULL)
//             *(n->p->colour) = B;
//           if (w->r != NULL)
//             *(w->r->colour) = B;
//           if (n->p != NULL)
//             leftRotate(n->p);

//           n = root;
//         }else{
//           cout << "b" << endl;
//           w = n->p->l;
//           if (*(w->colour) == R){                         //case 1:
//             cout << "case 1" << endl;
//             *(w->colour) = B;
//             *(n->p->colour) = R;
//             rightRotate(n->p);
//             w = x->p->l;
//           }
//           w_l_colour = (w->l == NULL)?B:*(w->l->colour);
//           w_r_colour = (w->r == NULL)?B:*(w->r->colour);
//           if (w_l_colour == B && w_r_colour == B){        //case 2:
//             cout << "case 2" << endl;
//             *(w->colour) == R;
//             n = n->p;
//           }else if (w_l_colour == B){                     //case 3:
//             cout << "case 3" << endl;
//             if (w->r != NULL)
//               *(w->r->colour) = B;
//             *(w->colour) == R;
//             leftRotate(w);
//             w = (n->p == NULL)?n->l:n->p->l;
//           }

//           n_p_colour = (n->p == NULL)?B:*(n->p->colour);
//           *(w->colour) == n_p_colour;                     //case 4:
//           cout << "case 4" << endl;
//           if (n->p != NULL)
//             *(n->p->colour) = B;
//           if (w->l != NULL)
//             *(w->l->colour) = B;
//           if (n->p != NULL)
//             rightRotate(n->p);

//           n = root;
//         }
//       // }
//   }
//   cout << "done" << endl;
//   *(n->colour) = B;
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
