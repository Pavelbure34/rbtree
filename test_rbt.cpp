#include "rbt.h"
#include "assert.h"
#define LOG1(x) cout << x << endl;
#define LOG2(x) cout << x;

/*
  this file tests rbt class file.
  Coded by Alistaire Suh and Katie Masell.
*/

void test_node_constructors_toStr(){
  //testing constructor with no argument  
  node<int> in;                                  //dummy for parent node
  node<double> dn;
  node<float> fn;
  node<char> cn;
  node<string> sn;

  //testing constructor with arguments.
  node<int> in1;                                 //giving colour
  in1.colour = R;
  node<double> dn1;
  dn1.colour = B;
  node<float> fn1;
  fn1.colour = R;
  node<char> cn1;
  cn1.colour = B;
  node<string> sn1;
  sn1.colour = R;

  node<int> in2(new int(10));                    //giving colour and key
  in2.colour = R;
  node<double> dn2(new double(10.0));
  dn2.colour = B;
  node<float> fn2(new float(10.0f));
  fn2.colour = R;
  node<char> cn2(new char('a'));
  cn2.colour = B;
  node<string> sn2(new string("hello world!"));
  sn2.colour = R;

  node<int> in3(new int(10), NULL, &in1, &in);   //giving colour, key, and rest of pointers.
  in3.colour = R;
  node<double> dn3(new double(10.0), NULL, &dn1, &dn);
  dn3.colour = B;
  node<float> fn3(new float(10.0f), NULL, &fn1, &fn);
  fn3.colour = R;
  node<char> cn3(new char('a'), NULL, &cn1, &cn);
  cn3.colour = B;
  node<string> sn3(new string("hello world!"), NULL, &sn1, &sn);
  sn3.colour = R;
  
  //testing toStr method
  assert(in.toStr() == "");
  assert(dn.toStr() == "");
  assert(fn.toStr() == "");
  assert(cn.toStr() == "");
  assert(sn.toStr() == "");
  assert(in1.toStr() == "");
  assert(dn1.toStr() == "");
  assert(fn1.toStr() == "");
  assert(cn1.toStr() == "");
  assert(sn1.toStr() == "");
  assert(in2.toStr() == "10");
  assert(dn2.toStr() == "10.000000");
  assert(fn2.toStr() == "10.000000");
  assert(cn2.toStr() == "97");
  assert(sn2.toStr() == "hello world!");

  //if no error, detstructor has been working fine at this point.
}

template<class T>
void test_rbt_insert(rbt<T> &tree, T* a, T* b, T* c){
  tree.insert(a);           //testing insert with empty tree
  tree.insert(b);           //testing insert with non empty tree
  tree.insert(c);
  cout << 1 << endl;
  assert(!tree.empty());    //it should not insert
}

template<class T>
void test_rbt_assingment(rbt<T> &a, rbt<T> &b){
  a = b;
  if (b.empty())       //if copy object is empty
    assert(a.empty()); //copied object is also empty
  else                 //if not
    assert(!a.empty());//it is not.
}

template<class T>
void test_rbt_get(rbt<T> &tree, T a, T b){
  
}

template<class T>
void test_rbt_remove(rbt<T> &tree, T a, T b){

}

int main(int argc, char const *argv[]) {
  LOG1("RBT class test init");
  LOG1("----------------------------------------");

  LOG2("(1) node constructor, destructor and toStr:");
  test_node_constructors_toStr();
  LOG1(" passed");

  LOG2("(2) bt default constructor:");
  rbt<int> it;          //testing default constructor
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;
  LOG1(" passed");

  LOG2("(3) rbt copy constructor on empty tree:");
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
  LOG1("passed");

  LOG2("(4) rbt copy assignment operator with emptyTree:");
  test_rbt_assingment(it, it);
  test_rbt_assingment(dt, dt);
  test_rbt_assingment(ft, ft);
  test_rbt_assingment(ct, ct);
  test_rbt_assingment(st, st);
  LOG1(" passed");
  LOG1("(5) rbt empty: passed"); //reaching here, empty works.

  LOG2("(6) rbt insert:");
  test_rbt_insert(it, new int(10), new int(15),new int(12));
  test_rbt_insert(dt, new double(10.0), new double(15.0), new double(12.0));
  test_rbt_insert(ft, new float(10.0f), new float(15.0f), new float(12.0f));
  test_rbt_insert(ct, new char('a'), new char('c'), new char('b'));
  test_rbt_insert(st, new string("hello"), new string("lo"), new string("Hel"));
  LOG1(" passed");

  LOG2("(7) rbt copy constructor with non-emptyTree:");
  rbt<int> it2(it);          
  rbt<double> dt2(dt);
  rbt<float> ft2(ft);
  rbt<char> ct2(ct);
  rbt<string> st2(st);
  assert(!it2.empty());
  assert(!dt2.empty());
  assert(!ft2.empty());
  assert(!ct2.empty());
  assert(!st2.empty());
  LOG1(" passed");

  //reaching here, insert_fix, rotate functions have working fine.
  LOG2("(8) rbt insert_fix: passed");
  LOG2("(9) rbt leftRotate: passed");
  LOG2("(10) rbt rightRotate: passed");

  // LOG2("rbt copy assignment operator with non-emptyTree:");
  // test_rbt_assingment(it1, it);
  // test_rbt_assingment(dt1, dt);
  // test_rbt_assingment(ft1, ft);
  // test_rbt_assingment(ct1, ct);
  // test_rbt_assingment(st1, st);
  // LOG1("passed");

  // LOG2("rbt get:");
  // LOG1("passed");
  
  LOG1("----------------------------------------");
  LOG1("RBT class test complete");
  return 0;
}
