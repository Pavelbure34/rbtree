#include "rbt.h"
#include "assert.h"
#define LOG1(x) cout << x << endl;
#define LOG2(x) cout << x;

/*
  this file tests rbt class file.
  Coded by Alistaire Suh and Katie Masell.
*/

void test_node_constructors(){
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
  int a = 10;
  float b = 10.0f;
  double c = 10.0;
  char d = 'a';
  string f = "hello world!";
  node<int> in2(B, &a, &in, &in1, &din);
  node<float> fn2(R, &b, &fn, &fn1, &dfn);
  // node<double> dn2(B, &c, &dn, &dn1, &ddn);
  // node<char> cn2(R, &d, &cn, &cn1, &dcn);
  // node<string> sn2(B, &f, &sn, &sn1, &dsn);

  //testing destructors-if without error, assume it works.
}

void test_node_toString(){
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

  assert(in2.toStr() == "10");
  assert(fn2.toStr() == "10.0");
  assert(dn2.toStr() == "10.0");
  assert(cn2.toStr() == "a");
  assert(sn2.toStr() == "hello world!");
}

void test_rbt_constructors(){
  // rbt<int> x;
  // rbt<int> y(x);
  //rbt<int> z = x;

   //rbt<string> s1;
   //rbt<string> s2(s1);
  // rbt<string> s3 = s2;

   //rbt<float> f1;
   //rbt<float> f2(f1);
  // rbt<float> f3 = f2;

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

  LOG2("node constructor:");
  test_node_constructors();
  LOG1("passed");

  // LOG2("node toStr:");
  // test_node_toString();
  // LOG1("passed");

  // LOG2("rbt constructor:");
  // test_rbt_constructors();
  // LOG1("passed");

  LOG1("RBT class test complete");
  return 0;
}
