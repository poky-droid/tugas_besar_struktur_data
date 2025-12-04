#ifndef DATA_H
#define DATA_H
#include <string>
using namespace std;
int pilihan;

// Struktur data user/petugas
struct DataUser {
    string username;
    string password;
    string nama;
    string alamat;
    string no_telp;
    string role;
};

struct nodeDataUser
{
    DataUser data;
    nodeDataUser* next;
    nodeDataUser* prev;
};

void printUser(DataUser D);
DataUser inputUser(DataUser in);       // khusus input petugas
nodeDataUser* createNode();            // membuat node baru
nodeDataUser* deleteUser(nodeDataUser* head); // hapus user
nodeDataUser* editData(nodeDataUser* head);



//sampah 

struct Sampah {
    string kategori;
    string jenisSampah;
    double berat;       // dalam kilogram
    double hargaPerKg;  // dalam rupiah
};

struct NodedataSampah
{
    Sampah data;
    NodedataSampah* next;
    NodedataSampah* prev;
};















// // Node tree general (multi-child)
// class Node {
// public:
//     DataUser data;            // menyimpan data lengkap user/petugas
//     Node* firstChild;     // anak pertama
//     Node* nextSibling;    // saudara berikutnya

//     Node(DataUser value) {
//         data = value;
//         firstChild = nullptr;
//         nextSibling = nullptr;
//     }
// };

// // Struktur Tree
// class Tree {
// public:
//     Node* root;

//     Tree() {
//         root = nullptr;
//     }

//     // Membuat root tree (misalnya: "Data Pegawai dan User")
//     void createRoot(DataUser value) {
//         root = new Node(value);
//     }

//     // Menambah anak ke parent (bisa petugas atau user)
//     Node* addChild(Node* parent, DataUser value) {
//         Node* newNode = new Node(value);

//         if (parent->firstChild == nullptr) {
//             parent->firstChild = newNode;
//         } else {
//             Node* temp = parent->firstChild;
//             while (temp->nextSibling != nullptr) {
//                 temp = temp->nextSibling;
//             }
//             temp->nextSibling = newNode;
//         }

//         return newNode;
//     }

//     // Rekursif hapus seluruh tree
//     void deleteTree(Node* node) {
//         if (node == nullptr) return;

//         deleteTree(node->firstChild);
//         deleteTree(node->nextSibling);

//         delete node;
//     }
// };

#endif
