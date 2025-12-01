#ifndef DATA_H
#define DATA_H
#include <string>
using namespace std;
int pilihan;

// Struktur data user/petugas
struct Data {
    string username;
    string password;
    string nama;
    string alamat;
    string no_telp;
    string role;
};

// Node tree general (multi-child)
class Node {
public:
    Data data;            // menyimpan data lengkap user/petugas
    Node* firstChild;     // anak pertama
    Node* nextSibling;    // saudara berikutnya

    Node(Data value) {
        data = value;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
};

// Struktur Tree
class Tree {
public:
    Node* root;

    Tree() {
        root = nullptr;
    }

    // Membuat root tree (misalnya: "Data Pegawai dan User")
    void createRoot(Data value) {
        root = new Node(value);
    }

    // Menambah anak ke parent (bisa petugas atau user)
    Node* addChild(Node* parent, Data value) {
        Node* newNode = new Node(value);

        if (parent->firstChild == nullptr) {
            parent->firstChild = newNode;
        } else {
            Node* temp = parent->firstChild;
            while (temp->nextSibling != nullptr) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = newNode;
        }

        return newNode;
    }

    // Rekursif hapus seluruh tree
    void deleteTree(Node* node) {
        if (node == nullptr) return;

        deleteTree(node->firstChild);
        deleteTree(node->nextSibling);

        delete node;
    }
};

#endif
