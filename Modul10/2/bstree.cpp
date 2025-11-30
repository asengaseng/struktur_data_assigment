#include "bstree.h"
#include <iostream>

using namespace std;

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == nullptr) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

address findNode(infotype x, address root) {
    if (root == nullptr) return nullptr;
    if (x == root->info) return root;
    if (x < root->info) return findNode(x, root->left);
    return findNode(x, root->right);
}

void printInOrder(address root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->info << " ";
        printInOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == nullptr) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == nullptr) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == nullptr) return start;
    int L = hitungKedalaman(root->left, start + 1);
    int R = hitungKedalaman(root->right, start + 1);
    return (L > R ? L : R);
}
