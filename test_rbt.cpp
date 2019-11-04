#include "rbt.h"
#include "assert.h"
#define LOG1(x) cout << x << endl;
#define LOG2(x) cout << x;

/*
  this file tests rbt class file.
  Coded by Alistaire Suh and Katie Masell.
*/

void test_node_constructors_toStr(){
  //testing default constructor for node class
  node<int> in;
  node<float> fn;
  node<double> dn;
  node<char> cn;
  node<string> sn;

  node<int> din;
  node<float> dfn;
  node<double> ddn;
  node<char> dcn;
  node<string> dsn;

  //testing constructor#2 for node class
  node<int> in1(B);
  node<float> fn1(R);
  node<double> dn1(B);
  node<char> cn1(R);
  node<string> sn1(B);

  //testing constructor#3 for node class
  // int* a = new int(10);
  int a = 10;
  float b = 10.0f;
  double c = 10.0;
  char d = 'a';
  string f = "hello world!";
  node<int> in2(B, &a, &in, &in1, &din);
  node<float> fn2(R, &b, &fn, &fn1, &dfn);
  node<double> dn2(B, &c, &dn, &dn1, &ddn);
  node<char> cn2(R, &d, &cn, &cn1, &dcn);
  node<string> sn2(B, &f, &sn, &sn1, &dsn);

  //testing toStr with stream operator
  assert(in2.toStr() == "10");
  assert(fn2.toStr() == "10.000000");
  assert(dn2.toStr() == "10.000000");
  assert(cn2.toStr() == "97");
  assert(sn2.toStr() == "hello world!");

  //testing destructors-if without error, assume it works.
}

void test_rbt_constructors_deepCopy_Destroy_insert(){
  //testing constructor #1
  rbt<int> it;
  rbt<float> ft;
  rbt<double> dt;
  rbt<char> ct;
  rbt<string> st;

  assert(it.empty());
  assert(ft.empty());
  assert(dt.empty());
  assert(ct.empty());
  assert(st.empty());

  // //testing constructor #2
  // rbt<int> it1(new node<int>(R, new int(15), NULL, NULL, NULL));
  // rbt<float> ft1(new node<float>(R, new float(15.12f), NULL, NULL, NULL));
  // rbt<double> dt1(new node<double>(R, new double(15.126), NULL, NULL, NULL));
  // rbt<char> ct1(new node<char>(B, new char('d'), NULL, NULL, NULL));
  // rbt<string> st1(new node<string>(B, new string("Hello World"), NULL, NULL, NULL));

  // assert(!it1.empty());
  // assert(!ft1.empty());
  // assert(!dt1.empty());
  // assert(!ct1.empty());
  // assert(!st1.empty());

  // //testing insert
  // it.insert(new int(20));  //testing insert on empty tree
  // ft.insert(new float(19.6f));
  // dt.insert(new double(19.65));
  // ct.insert(new char('f'));
  // st.insert(new string("Hello NHL"));
  // it1.insert(new int(20)); //testing insert on non-empty tree
  // ft1.insert(new float(19.6f));
  // dt1.insert(new double(19.65));
  // ct1.insert(new char('f'));
  // st1.insert(new string("Hello NHL"));

  // //testing copy constructor #3
  // rbt<int> it2(it1);
  // rbt<float> ft2(ft1);
  // rbt<double> dt2(dt1);
  // rbt<char> ct2(ct1);
  // rbt<string> st2(st1);

  // assert(!it2.empty());
  // assert(!ft2.empty());
  // assert(!dt2.empty());
  // assert(!ct2.empty());
  // assert(!st2.empty());

  // //testing assignment operator
  // rbt<int> it3 = it1;    //testing on empty tree
  // rbt<float> ft3 = ft1;
  // rbt<double> dt3 = dt1;
  // rbt<char> ct3 = ct1;
  // rbt<string> st3 = st1;
  // it = it1;              //testing on non-empty tree
  // ft = ft1;
  // dt = dt1;
  // ct = ct1;
  // st = st1; 

  //reaching here without error, please assume that destructor, empty works.
}

void test_rbt_insert(){
  //rbt<int> x;
  //rbt<int> y(x);

  // int* a = new int;
  // *a = 5;
  // x.insert(a);
  // *a = 7;
  // x.insert(a);
  // *a = 6;
  // x.insert(a);
  // *a = 9;
  // x.insert(a);
  // *a = 1;
  // x.insert(a);
  // *a = 4;
  // x.insert(a);
  //
  // rbt<int> z = x;
  // rbt<int> w(x);
}

int main(int argc, char const *argv[]) {
  LOG1("RBT class test init");

  LOG2("node constructor, destructor and toStr:");
  test_node_constructors_toStr();
  LOG1("passed");

  LOG2("rbt constructor:");
  test_rbt_constructors_deepCopy_Destroy_insert();
  LOG1("passed");

  LOG1("RBT class test complete");
  return 0;
}
