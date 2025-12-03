#include "data.h"
#include <iostream>
using namespace std;

void printUser(DataUser D) {
    cout << "Username : " << D.username << endl;
    cout << "Password : " << D.password << endl;
    cout << "Nama     : " << D.nama << endl;
    cout << "Alamat   : " << D.alamat << endl;
    cout << "No Telp  : " << D.no_telp << endl;
    cout << "Role     : " << D.role << endl;
    cout << "------------------------------" << endl;
}

DataUser inputUser(DataUser in) {
    cout << "Masukkan Username : ";
    cin >> in.username;
    cout << "Masukkan Password : ";
    cin >> in.password;
    cout << "Masukkan Nama     : ";
    cin >> in.nama;
    cout << "Masukkan Alamat   : ";
    cin >> in.alamat;
    cout << "Masukkan No Telp  : ";
    cin >> in.no_telp;
    cout << "Masukkan Role (user/petugas) : ";
    cin >> in.role;

    return in;
}

nodeDataUser* deleteUser(nodeDataUser* head) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada user yang dihapus." << endl;
        return nullptr;
    }

    nodeDataUser* hapus = head;
    head = head->next;

    cout << "User dengan username '" << hapus->data.username << "' telah dihapus." << endl;

    delete hapus;
    return head;
}

nodeDataUser* editData(nodeDataUser* head) {
    if (head == nullptr) {
        cout << "List kosong, tidak ada data yang bisa diedit." << endl;
        return head;
    }

    string key;
    cout << "Masukkan username yang ingin diedit: ";
    cin >> key;

    nodeDataUser* temp = head;
    bool ditemukan = false;

    // Cari username
    while (temp != nullptr) {
        if (temp->data.username == key) {
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }

    if (!ditemukan) {
        cout << "Data dengan username '" << key << "' tidak ditemukan." << endl;
        return head;
    }

    // Edit data
    cout << "=== EDIT DATA USER ===" << endl;
    cout << "Username baru   : ";
    cin >> temp->data.username;
    cout << "Password baru   : ";
    cin >> temp->data.password;
    cout << "Nama baru       : ";
    cin >> temp->data.nama;
    cout << "Alamat baru     : ";
    cin >> temp->data.alamat;
    cout << "No Telp baru    : ";
    cin >> temp->data.no_telp;
    cout << "Role baru       : ";
    cin >> temp->data.role;

    cout << "Data berhasil diperbarui!" << endl;

    return head;
}







