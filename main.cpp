#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST<int> x;
    x.insert(4);
//    x.insert(3);
    x.insert(7);
    x.insert(9);
    x.insert(6);
    x.insert(2);
    x.insert(3);
    x.insert(1);
    x.print();
    x.deleteTree();
    x.insert(2);
    x.insert(3);
    x.insert(1);
    x.print();

    BST<char> u;
    u.insert('g');
    u.insert('h');
    u.insert('e');
    u.insert('u');
    u.insert('a');
    u.insert('d');
    u.insert('l');
    u.print();

    BST<string> v;
    v.insert("ACT");
    v.insert("SAT");
    v.insert("EUAEL");
    v.print();


    string y = "zeuael" > "mekonen"? "euael": "mekonen";
    cout << y << endl;
    cout << "Hello, World!" << endl;

    return 0;
}
