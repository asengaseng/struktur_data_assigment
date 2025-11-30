#include <iostream>
#include "BSTree.cpp"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = nullptr;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);   
    insertNode(root, 7);

    cout << "InOrder Traversal: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
