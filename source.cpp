#include "header.h"
#include <iostream>

using namespace std;


adrNode newNode(string nama, string tipe) {
    adrNode p = new Node;
    p->info.nama = nama;
    p->info.tipe = tipe;
    p->firstChild = nullptr;
    p->nextSibling = nullptr;
    return p;
}

void insertNode(adrNode parent, string nama, string tipe) {
    if (parent == nullptr){
        return nullptr;
    }

    adrNode pBaru = newNode(nama, tipe);

    if (parent->firstChild == nullptr) {
        parent->firstChild = pBaru;
    } else {
        adrNode temp = parent->firstChild;
        while (temp->nextSibling != nullptr) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = pBaru;
    }
}

adrNode findNode(adrNode root, string nama) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->info.nama == nama){
        return root
    }
    adrNode hasil = findNode(root->firstChild, nama);
    if (hasil != nullptr) {
        return hasil;
    }
    return findNode(root->nextSibling, nama);
}

void postOrder(adrNode root){
    if (root == nullptr) return;
    postOrder(root->firstChild);
    cout << root->info.nama << " - ";
    postOrder(root->nextSibling);
}

void inOrder(adrNode root){
    if (root == NULL) return;
    inOrder(root->firstChild);
    cout << root->info.nama << " - ";
    inOrder(root->nextSibling);
}
