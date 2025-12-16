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
        return;
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
        return root;
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
    if (root == nullptr) return;
    inOrder(root->firstChild);
    cout << root->info.nama << " - ";
    inOrder(root->nextSibling);
}

void levelOrder(adrNode root, int level){
    if (root == nullptr) return;

    for (int i = 0; i < level; i++){
        cout << "   ";
    }

    if (root->info.tipe == "Genre"){
        cout << "[Genre] ";
    } else if (root->info.tipe == "Artist"){
        cout << "|-> [Artist] ";
    } else if (root->info.tipe == "Album"){
        cout << "     |-> [Album] ";
    } else {
        cout << "          |-> [Lagu] ";
    }
    cout << root->info.nama << endl;
    levelOrder(root->firstChild, level + 1);
    levelOrder(root->nextSibling, level);
}

void preOrder(adrNode root){
    if (root == nullptr) return;
    cout << root->info.nama << " - ";
    preOrder(root->firstChild);
    preOrder(root->nextSibling);
}

void menu(){
    cout << "\n=====Menu Playlist=====" << endl;
    cout << "1. Tambah Genre" << endl;
    cout << "2. Tambah Artist" << endl;
    cout << "3. Tambah Album" << endl;
    cout << "4. Tambah Lagu" << endl;
    cout << "5. Tampilkan Playlist" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan: ";
}
