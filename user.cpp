#include "data.h"
#include <iostream>
using namespace std;

nodeDataUser* createNode() {
    nodeDataUser* baru = new nodeDataUser;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}


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

    string key;
    cout << "Masukkan username yang ingin dihapus: ";
    cin >> key;

    nodeDataUser* temp = head;

    // cari node
    while (temp != nullptr && temp->data.username != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "User tidak ditemukan!" << endl;
        return head;
    }

    // jika node yang dihapus adalah head
    if (temp == head) {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
    } 
    else {
        temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;
    }

    cout << "User '" << temp->data.username << "' berhasil dihapus.\n";
    delete temp;

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

    // cari username
    while (temp != nullptr && temp->data.username != key) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "User tidak ditemukan!" << endl;
        return head;
    }

    cout << "\n=== EDIT DATA USER ===\n";

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

    cout << "Data berhasil diperbarui!\n";

    return head;
}







