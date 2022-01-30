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
    x.remove(2);
    x.print();
    cout << "preorder: ";
    x.PreOrderPrint();

    cout << "postorder: ";
    x.PostOrderPrint();

    cout << "Hello, World!" << endl;
    return 0;
}
