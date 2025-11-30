#include <iostream>
#include "bstree.cpp"

using namespace std;

int main() {

    address root = nullptr;

    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);

    cout << "PreOrder  : ";
    printPreOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    printPostOrder(root);
    cout << endl;

    cout << "Kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "Jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "Total Info : " << hitungTotalInfo(root) << endl;

    return 0;
}
