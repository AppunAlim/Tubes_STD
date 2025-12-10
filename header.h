#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct Node* adrNode;

struct Infotype {
    string nama;
    string tipe;
};

struct Node {
    Infotype info;
    adrNode firstChild;
    adrNode nextSibling;
};

adrNode newNode(string nama, string tipe);
void insertNode(adrNode parent, string nama, string tipe);
void printTree(adrNode root, int level);
void preOrder(adrNode root);
void postOrder(adrNode root);
void inOrder(adrNode root);
adrNode findNode(adrNode root, string nama);


#endif // HEADER_H_INCLUDED
