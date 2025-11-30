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