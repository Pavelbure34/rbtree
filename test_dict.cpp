#include "dict.h"
#include "assert.h"

/*
    this file tests dictionary class.
    Coded by Alistaire Suh and Katie Masell
*/

void test_dict_insert(){
    dictionary<h_pair<string, string>> dict;
    assert(dict.empty()); //initial creation should be empty
    //reaching here, default constructor is workign fine.

    //inserting items
    h_pair<string, string>* p1 = new h_pair<string, string>(
        new string("proj5"), new string("binary Search Tree")
    );
    h_pair<string, string>* p2 = new h_pair<string, string>(
        new string("proj6"), new string("hash table")
    );
    h_pair<string, string>* p3 = new h_pair<string, string>(
        new string("proj6"), new string("Red black tree")
    );
    h_pair<string, string>* arr[3] = {
        p1, p2, p3
    };

    for (int i = 0; i < 3; ++i){
        dict.insert(arr[i]);                   //inserting
    }
    assert(!dict.empty()); //inserted tree should not be empty


    dictionary<h_pair<string, string>> temp(dict);
    assert(!temp.empty());
    //reaching here, copy constructor is working fine.

    //inserting duplicat item -- which should not do anything
    dict.insert(
        new h_pair<string, string>(
            new string("proj6"), new string("Red black tree")
        )
    );
    assert(temp.preOrder() == dict.preOrder());
    //reaching here, toString in pair is working fine.
    delete p1, p2, p3;
}

// template<class T>
// void test_remove(dictionary<T> &d, T item1, T item2){
//     int prev, after;

//     //remove testing on existing item
//     d.remove(item1);
//     d.remove(item2);
//     prev = d.itemNum();

//     //remove testing on non existing item
//     try{
//         d.remove(item2);
//     }catch(noKeyException *e){
//         after = d.itemNum();
//     }
//     assert(prev == after);
//     assert(prev == 0);
//     assert(after == 0);
// }

void test_dict_assignmentOP(){
    dictionary<h_pair<string, string>> dict;
    assert(dict.empty()); //initial creation should be empty
    
    //inserting items
    string key1 = "proj1";
    string pair1 = "HashTable";
    h_pair<string, string> h1(&key1, &pair1);
    dict.insert(&h1);
    cout << "here" << endl;

    // assert(!dict.empty()); //inserted tree should not be empty

    // dictionary<h_pair<string, string>> dict1 = dict;
    // assert(!dict1.empty());
    // assert(dict1.preOrder() == dict.preOrder());

    // //reaching here, assignment operator is working fine for empty tree.
    // dictionary<h_pair<string, string>> dict2; //making non empty tree
    // dict2.insert(
    //     new h_pair<string, string>(
    //         new string("proj6"), new string("Red black tree")
    //     )
    // );

    // dict2 = dict1;        
    // assert(!dict2.empty());
    // assert(dict2.preOrder() == dict1.preOrder());
    // //reaching here, assignment operator is working fine for non empty tree.

    // delete p1, p2, p3;
}

void test_dict_get(){
    dictionary<h_pair<string, string>> dict;
    assert(dict.empty()); //initial creation should be empty

    //inserting items
    h_pair<string, string>* p1 = new h_pair<string, string>(
        new string("proj5"), new string("binary Search Tree")
    );
    h_pair<string, string>* p2 = new h_pair<string, string>(
        new string("proj6"), new string("hash table")
    );
    h_pair<string, string>* p3 = new h_pair<string, string>(
        new string("proj6"), new string("Red black tree")
    );
    h_pair<string, string>* arr[3] = {
        p1, p2, p3
    };
   
    for (int i = 0; i < 3; ++i){
        dict.insert(arr[i]);                   //inserting
        assert(*dict.get(*arr[i]) == *arr[i]); //confirming its input
    }
    assert(!dict.empty()); //inserted tree should not be empty
    delete p1, p2, p3;
}


int main(){
    cout << "dictionary test init" << endl;
    test_dict_insert();
    test_dict_assignmentOP();
    // test_dict_get();
    //reaching here with out error, constructors are working fine.
    cout << "dictionary test complete" << endl;
    return 0;
    //reaching here with out error, destructor are working fine.
}
