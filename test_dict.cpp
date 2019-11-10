#include "dict.h"
#include "assert.h"

/*
    this file tests dictionary class.
    Coded by Alistaire Suh and Katie Masell
*/

void test_dict(){
    dictionary<h_pair<string, string>> dict;
    assert(dict.empty()); //initial creation should be empty
    //reaching here, default constructor is workign fine.

    //testing assingment on empty tree
    dictionary<h_pair<string, string>> dict1 = dict;
    assert(dict1.empty());
    //reaching here, assignment operator works fine for emtpy tree.

    //inserting items
    h_pair<string, string>* arr[3];
    string key1 = "Prj1";
    string val1 = "HashTable";
    arr[0] = new h_pair<string, string>(&key1, &val1);
    string key2 = "Prj2";
    string val2 = "RBT";
    arr[1] = new h_pair<string, string>(&key2, &val2);
    string key3 = "Prj3";
    string val3 = "Graph";
    arr[2] = new h_pair<string, string>(&key3, &val3); 

    for (int i = 0; i < 3; ++i){
        dict.insert(arr[i]);                   //inserting
        assert(*dict.get(*arr[i]) == *arr[i]);//confirming its input
    }
    assert(!dict.empty()); //inserted tree should not be empty
    //reaching here, insert and get works fine.

    dictionary<h_pair<string, string>> temp(dict);
    assert(!temp.empty());
    //reaching here, copy constructor is working fine.

    //inserting duplicat item -- which should not do anything
    dict.insert(
        new h_pair<string, string>(
            new string("Prj3"), new string("Graph")
        )
    );
     
    assert(temp.preOrder() == dict.preOrder());
    //reaching here, toString in pair is working fine.

    //reaching here, assignment operator is working fine for empty tree.
    dictionary<h_pair<string, string>> dict2; //making non empty tree
    dict2.insert(
        new h_pair<string, string>(
            new string("proj6"), new string("Red black tree")
        )
    );

    dict2 = dict;        
    assert(!dict2.empty());
    assert(dict2.preOrder() == dict.preOrder());
    //reaching here, assignment operator is working fine for non empty tree.
}

int main(){
    cout << "dictionary test init" << endl;
    test_dict();
    cout << "dictionary test complete" << endl;
    return 0;
    // reaching here with out error, destructor are working fine.
}
