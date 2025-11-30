#include <iostream>
#include "crud.h"
using namespace std;

//buat 
Node* createData(Tree &t, Node* parent){
    Data d;
    cout << "Masukan username : " << d.username << endl;
    cout << "Masukan password : " << d.password << endl;
    cout << "Masukan nama : " << d.nama << endl;
    cout << "Masukan alamat : " << d.alamat << endl;
    cout << "Masukan no_telp : " << d.no_telp << endl;

    if(t.root == nullptr){
        t.createRoot(d);
        return t.root;
    }
    return t.addChild(parent, d);
}

//read data
void readData(Node* node, int space = 0){
    if (node == nullptr) return;
    for (int i = 0; i < space; i++) cout << " ";
    cout << "> " << node -> data.username << "(" << node -> data.nama << ") \n";
    readData(node -> firstChild, space + 2);
    readData(node -> nextSibling, space);
}

//delete
bool deleteData(Tree &t, Node* parent, string username) {
    if (parent == nullptr) return false;

    Node* child = parent->firstChild;

    if (child != nullptr && child->data.username == username) {
        parent->firstChild = child->nextSibling;
        delete child;
        return true;
    }

    Node* prev = child;
    if (child != nullptr) child = child->nextSibling;

    while (child != nullptr) {
        if (child->data.username == username) {
            prev->nextSibling = child->nextSibling;
            delete child;
            return true;
        }
        prev = child;
        child = child->nextSibling;
    }

    child = parent->firstChild;
    while (child != nullptr) {
        if (deleteData(t, child, username)) return true;
        child = child->nextSibling;
    }

    return false;
}