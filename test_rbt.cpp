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

void test_rbt_constructors(){
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

  rbt<int> it2(it);   //copy constructor with non empty tree
  rbt<double> dt2(dt);
  rbt<float> ft2(ft);
  rbt<char> ct2(ct);
  rbt<string> st2(st);

  assert(it2.preOrder() == it.preOrder()); //making it sure it is not empty
  assert(dt2.preOrder() == dt.preOrder());
  assert(ft2.preOrder() == ft.preOrder());
  assert(ct2.preOrder() == ct.preOrder());
  assert(st2.preOrder() == st.preOrder());
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

  int iArr[6] = {50, 30, 40, 10, 5, 70};
  double dArr[6] = {50.0, 30.0, 40.0, 10.0, 5.0, 70.0};
  float fArr[6] = {50.0f, 30.0f, 40.0f, 10.0f, 5.0f, 70.0f};
  char cArr[6] = {'z','f','g', 'a', 'b', 'x'};
  string sArr[6] = {"Hello","World","Hel","lo","rld", "d"};

  for (int i = 0;i < 6; i++){
    it.insert(iArr + i);
    dt.insert(dArr + i);
    ft.insert(fArr + i);
    ct.insert(cArr + i);
    st.insert(sArr + i);
    assert(*it.get(*(iArr + i)) == *(iArr + i)); //confirming insertion
    assert(*dt.get(*(dArr + i)) == *(dArr + i));
    assert(*ft.get(*(fArr + i)) == *(fArr + i));
    assert(*ct.get(*(cArr + i)) == *(cArr + i));
    assert(*st.get(*(sArr + i)) == *(sArr + i));
  }

  // cout << it.preOrder() << endl;
  // cout << dt.preOrder() << endl;
  // cout << ft.preOrder() << endl;
  // cout << ct.preOrder() << endl;
  // cout << st.preOrder() << endl;
  
  assert(!it.empty());  //after insertion it has not to be empty
  assert(!dt.empty());
  assert(!ft.empty());
  assert(!ct.empty());
  assert(!st.empty());
}

void test_rbt_assingment(){
  rbt<int> it3;
  rbt<double> dt3;
  rbt<float> ft3;
  rbt<char> ct3;
  rbt<string> st3;
  
  assert(it3.empty()); //making it sure it is emtpy
  assert(dt3.empty());
  assert(ft3.empty());
  assert(ct3.empty());
  assert(st3.empty());

  int iArr[2] = {41, 44};
  double dArr[2] = {31.0, 31.9};
  float fArr[2] = {31.0f, 31.9f};
  char cArr[2] = {'x', 'f'};
  string sArr[2] = {"Hello World!", "o World!"};

  for (int i = 0; i < 2; i++){
    it3.insert(iArr + i);        //inserting
    dt3.insert(dArr + i);
    ft3.insert(fArr + i);
    ct3.insert(cArr + i);
    st3.insert(sArr + i);
    assert(*it3.get(iArr[i]) == iArr[i]); //confirming insertion
    assert(*dt3.get(dArr[i]) == dArr[i]);
    assert(*ft3.get(fArr[i]) == fArr[i]);
    assert(*ct3.get(cArr[i]) == cArr[i]);
    assert(*st3.get(sArr[i]) == sArr[i]);
  }

  rbt<int> it1 = it3;   //assignment on empty tree
  rbt<double> dt1 = dt3;
  rbt<float> ft1 = ft3;
  rbt<char> ct1 = ct3;
  rbt<string> st1 = st3;

  assert(it1.inOrder() == it3.inOrder()); //making it sure it is not empty
  assert(dt1.inOrder() == dt3.inOrder());
  assert(ft1.inOrder() == ft3.inOrder());
  assert(ct1.inOrder() == ct3.inOrder());
  assert(st1.inOrder() == st3.inOrder());

  it1 = it3;            //assignment on non-empty tree core dump here
  dt1 = dt3;
  ft1 = ft3;
  ct1 = ct3;
  st1 = st3;

  assert(it1.inOrder() == it3.inOrder()); //making it sure it is not empty
  assert(dt1.inOrder() == dt3.inOrder());
  assert(ft1.inOrder() == ft3.inOrder());
  assert(ct1.inOrder() == ct3.inOrder());
  assert(st1.inOrder() == st3.inOrder());
}

void test_rbt_get(){
  rbt<int> it;
  rbt<double> dt;
  rbt<float> ft;
  rbt<char> ct;
  rbt<string> st;

  //testing get on empty tree to produce an exception
  try{
    it.get(10);
  }catch(emptyTreeException *e){}
  try{
    dt.get(10.0);
  }catch(emptyTreeException *e){}
  try{
    ft.get(10.0f);
  }catch(emptyTreeException *e){}
  try{
    ct.get('a');
  }catch(emptyTreeException *e){}
  try{
    st.get("10");
  }catch(emptyTreeException *e){}

  assert(it.empty());  //initial creation has to be empty
  assert(dt.empty());
  assert(ft.empty());
  assert(ct.empty());
  assert(st.empty());

  int iArr[6] = {50, 30, 40, 10, 5, 70};
  double dArr[6] = {50.0, 30.0, 40.0, 10.0, 5.0, 70.0};
  float fArr[6] = {50.0f, 30.0f, 40.0f, 10.0f, 5.0f, 70.0f};
  char cArr[6] = {'z','f','g', 'a', 'b', 'x'};
  string sArr[6] = {"Hello","World","Hel","lo","rld", "d"};

  for (int i = 0;i < 6; i++){
    it.insert(iArr + i);
    dt.insert(dArr + i);
    ft.insert(fArr + i);
    ct.insert(cArr + i);
    st.insert(sArr + i);
    assert(*it.get(iArr[i]) == iArr[i]); //confirming insertion
    assert(*dt.get(dArr[i]) == dArr[i]);
    assert(*ft.get(fArr[i]) == fArr[i]);
    assert(*ct.get(cArr[i]) == cArr[i]);
    assert(*st.get(sArr[i]) == sArr[i]);
  }

  //testing get to throw noKeyException
  try{
    it.get(100);
  }catch(noKeyException *e){}
  try{
    dt.get(100.0);
  }catch(noKeyException *e){}
  try{
    ft.get(100.0f);
  }catch(noKeyException *e){}
  try{
    ct.get('c');
  }catch(noKeyException *e){}
  try{
    st.get("el");
  }catch(noKeyException *e){}

  assert(!it.empty());  //after insertion it has not to be empty
  assert(!dt.empty());
  assert(!ft.empty());
  assert(!ct.empty());
  assert(!st.empty());
}

int main(int argc, char const *argv[]) {
  LOG1("RBT class test init");
  test_node_constructors_toStr();    //test node constructor, destructor and toStr;
  test_rbt_constructors();           //testing rbt constructor
  test_rbt_insert();                 //testing insert
  test_rbt_get();                    //testing get         
  test_rbt_assingment();             //testing assignment operator
  LOG1("RBT class test complete");
  return 0;
}
