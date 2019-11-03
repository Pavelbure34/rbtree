

#include "rbt.h"




void test_node_constructors(){
  node<int> x;
}



void test_rbt_constructors(){
  rbt<int> x;
  rbt<int> y(x);
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
  test_node_constructors();
  printf("%s\n", "Testing RBT Constructors");
  test_rbt_constructors();
  //printf("%s\n", "Testing RBT Insert");
  test_rbt_insert();
  return 0;
}
