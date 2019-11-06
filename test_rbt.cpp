#include "rbt.h"
#include "assert.h"
#define LOG1(x) cout << x << endl;
#define LOG2(x) cout << x;

/*
  this file tests rbt class file.
  Coded by Alistaire Suh and Katie Masell.
*/

void test_node_constructors_toStr(){
  //testing completely empty node
  node<int> in;
  node<double> dn;
  node<float> fn;
  node<char> cn;
  node<string> sn;

  node<int> in1;     //dummies for pointer input.
  node<double> dn1;
  node<float> fn1;
  node<char> cn1;
  node<string> sn1;

  //testing giving key
  node<int> in2(new int(10));    
  node<double> dn2(new double(10.0));
  node<float> fn2(new float(11.0f));
  node<char> cn2(new char('a'));
  node<string> sn2(new string("Hello"));

  //testing key, colour
  node<int> in3(new int(10), new bool(R));    
  node<double> dn3(new double(10.0), new bool(B));
  node<float> fn3(new float(11.0f), new bool(R));
  node<char> cn3(new char('a'), new bool(B));
  node<string> sn3(new string("Hello"), new bool(R));

  //testing everything
  node<int> in4(new int(10), new bool(R), &in1, &in2, &in3);    
  node<double> dn4(new double(10.0), new bool(B), &dn1, &dn2, &dn3);
  node<float> fn4(new float(11.0f), new bool(R), &fn1, &fn2, &fn3);
  node<char> cn4(new char('a'), new bool(B), &cn1, &cn2, &cn3);
  node<string> sn4(new string("Hello"), new bool(R), &sn1, &sn2, &sn3);

  //tesing toStr()
  assert(in4.toStr() == "10:r");
  assert(dn4.toStr() == "10.000000:b");
  assert(fn4.toStr() == "11.000000:r");
  assert(cn4.toStr() == "97:b");
  assert(sn4.toStr() == "Hello:r");

  //if no error, detstructor has been working fine at this point.
}

void test_rbt_constructors_1(){
  rbt<int> it;               //making empty tree
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  rbt<int> it1(it);          //testing copy constructor with empty
  rbt<double> dt1(dt);
  rbt<float> ft1(ft);
  rbt<char> ct1(ct);
  rbt<string> st1(st);

  assert(it.empty() == it1.empty());
  assert(dt.empty() == dt1.empty());
  assert(ft.empty() == ft1.empty());
  assert(ct.empty() == ct1.empty());
  assert(st.empty() == st1.empty());
}

void test_rbt_insert(){
  rbt<int> it;
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  assert(it.empty());  //initial creation has to be empty
  assert(dt.empty());
  assert(ft.empty());
  assert(ct.empty());
  assert(st.empty());

  int ia = 41;                 //Katie, your style here!!
  double da = 31.0; 
  float fa = 31.0f;
  char ca = 'x';
  string sa = "Hello World!";    

  //inserting first item
  it.insert(&ia);
  dt.insert(&da);
  ft.insert(&fa);
  ct.insert(&ca);
  st.insert(&sa);

  int ib = 50; 
  double db = 41.0;
  float fb = 41.0f;
  char cb = 'b';
  string sb = "Hello";    

  //inserting second item
  it.insert(&ib);
  dt.insert(&db);
  ft.insert(&fb);
  ct.insert(&cb);
  st.insert(&sb);

  int ic = 44; 
  double dc = 39.0;
  float fc = 39.0f;
  char cc = 'f';
  string sc = "o World!";    

  //inserting third item
  it.insert(&ic);
  dt.insert(&dc);
  ft.insert(&fc);
  ct.insert(&cc);
  st.insert(&sc);

  int id = 10; 
  double dd = 10.0;
  float fd = 5.0f;
  char cd = 'a';
  string sd = "ld!"; 

  //so ... on
  it.insert(&id);
  dt.insert(&dd);
  ft.insert(&fd);
  ct.insert(&cd);
  st.insert(&sd);

  // cout << it.preOrder() << endl;
  // cout << dt.preOrder() << endl;
  // cout << ft.preOrder() << endl;
  // cout << ct.preOrder() << endl;
  // cout << st.preOrder() << endl;

  assert(!it.empty());            //after insertion non empty
  assert(!dt.empty());
  assert(!ft.empty());
  assert(!ct.empty());
  assert(!st.empty());
}

void test_rbt_constructors_2(){
  rbt<int> it;
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  assert(it.empty()); //making it sure it is emtpy
  assert(dt.empty());
  assert(ft.empty());
  assert(ct.empty());
  assert(st.empty());

  int *ia = new int(41);
  int *ib = new int(44);
  double *da = new double(31.0);
  double *db = new double(39.0);
  float *fa = new float(31.0f);
  float *fb = new float(39.0f);
  char *ca = new char('x');
  char *cb = new char('f');
  string *sa = new string("Hello World!");
  string *sb = new string("o World!");

  it.insert(ia);       //inserting
  dt.insert(da);
  ft.insert(fa);
  ct.insert(ca);
  st.insert(sa);

  it.insert(ib);
  dt.insert(db);
  ft.insert(fb);
  ct.insert(cb);
  st.insert(sb);

  rbt<int> it1(it);   //copy constructor with non empty tree
  rbt<double> dt1(dt);
  rbt<float> ft1(ft);
  rbt<char> ct1(ct);
  rbt<string> st1(st);

  assert(!it1.empty()); //making it sure it is not empty
  assert(!dt1.empty());
  assert(!ft1.empty());
  assert(!ct1.empty());
  assert(!st1.empty());

  //reaching here, if no error, deepCopy and destructor has been working fine
  delete ia;           //freeing memory
  delete ib;
  delete da;
  delete db;
  delete fa;
  delete fb;
  delete ca;
  delete cb;
  delete sa;
  delete sb;
}

void test_rbt_assingment(){
  rbt<int> it;
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  assert(it.empty()); //making it sure it is emtpy
  assert(dt.empty());
  assert(ft.empty());
  assert(ct.empty());
  assert(st.empty());

  it.insert(new int(41));       //inserting
  dt.insert(new double(31.0));
  ft.insert(new float(31.0f));
  ct.insert(new char('x'));
  st.insert(new string("Hello World!"));

  it.insert(new int(44));
  dt.insert(new double(39.0));
  ft.insert(new float(39.0f));
  ct.insert(new char('f'));
  st.insert(new string("o World!"));

  rbt<int> it1 = it;   //assignment on empty tree
  rbt<double> dt1 = dt;
  rbt<float> ft1 = ft;
  rbt<char> ct1 = ct;
  rbt<string> st1 = st;

  assert(!it1.empty()); //making it sure it is not empty
  assert(!dt1.empty());
  assert(!ft1.empty());
  assert(!ct1.empty());
  assert(!st1.empty());

  // it1 = it1;            //assignment on non-empty tree core dump here
  // dt1 = dt1;
  // ft1 = ft1;
  // ct1 = ct1;
  // st1 = st1;

  // assert(!it1.empty()); //making it sure it is not empty
  // assert(!dt1.empty());
  // assert(!ft1.empty());
  // assert(!ct1.empty());
  // assert(!st1.empty());
}

template<class T>
void test_rbt_get(rbt<T> &tree, T a, T b){
  rbt<int> it;
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  assert(it.empty()); //making it sure it is emtpy
  assert(dt.empty());
  assert(ft.empty());
  assert(ct.empty());
  assert(st.empty());

  int *ia = new int(41);
  int *ib = new int(44);
  double *da = new double(31.0);
  double *db = new double(39.0);
  float *fa = new float(31.0f);
  float *fb = new float(39.0f);
  char *ca = new char('x');
  char *cb = new char('f');
  string *sa = new string("Hello World!");
  string *sb = new string("o World!");

  it.insert(ia);       //inserting
  dt.insert(da);
  ft.insert(fa);
  ct.insert(ca);
  st.insert(sa);

  it.insert(ib);       //inserting
  dt.insert(db);
  ft.insert(fb);
  ct.insert(cb);
  st.insert(sb);

  assert(!it.empty()); //making it sure it is not empty
  assert(!dt.empty());
  assert(!ft.empty());
  assert(!ct.empty());
  assert(!st.empty());

  assert(*(it.get(*ia)) == *ia && *(it.get(*ib)) == *ib);
  assert(*(dt.get(*da)) == *da && *(dt.get(*db)) == *db);
  assert(*(ft.get(*fa)) == *fa && *(ft.get(*fb)) == *fb);
  assert(*(ct.get(*ca)) == *ca && *(ct.get(*cb)) == *cb);
  assert(*(st.get(*sa)) == *sa && *(st.get(*sb)) == *sb);

  delete ia;           //freeing memory
  delete ib;
  delete da;
  delete db;
  delete fa;
  delete fb;
  delete ca;
  delete cb;
  delete sa;
  delete sb;
}

int main(int argc, char const *argv[]) {
  //destructor isn't working

  LOG1("RBT class test init");
  test_node_constructors_toStr(); //test node constructor, destructor and toStr;
  test_rbt_constructors_1();      //test rbt constructors
  // test_rbt_insert();              //testing insert
  // test_rbt_constructors_2();         //testing copy constructor on non-empty tree         
  // test_rbt_assingment();             //testing assignment operator
  LOG1("RBT class test complete");
  return 0;
}
