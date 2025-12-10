#include <iostream>
#include "data.h"
using namespace std;



// list buat user/petugas

void adminListUser(nodeDataUser* headUser) {
    cout << "\n===== DATA USER & PETUGAS =====\n";
    if (!headUser) {
        cout << "Data kosong!\n";
        return;
    }

    nodeDataUser* p = headUser;
    while (p) {
        cout << "Username : " << p->data.username << endl;
        cout << "Nama     : " << p->data.nama << endl;
        cout << "Role     : " << p->data.role << endl;
        cout << "---------------------------------\n";
        p = p->next;
    }
}



// buat nambah user/petugas

void adminTambahUser(nodeDataUser*& headUser) {
    DataUser baru;

    cout << "\n===== TAMBAH USER / PETUGAS =====\n";
    cout << "Username : "; cin >> baru.username;
    cout << "Password : "; cin >> baru.password;
    cout << "Nama     : "; cin >> baru.nama;
    cout << "Alamat   : "; cin >> baru.alamat;
    cout << "No Telp  : "; cin >> baru.no_telp;
    cout << "Role (user/petugas): "; cin >> baru.role;

    nodeDataUser* nodeBaru = createNode(baru);

    if (!headUser) {
        headUser = nodeBaru;
    } else {
        nodeDataUser* p = headUser;
        while (p->next) p = p->next;

        p->next = nodeBaru;
        nodeBaru->prev = p;
    }

    cout << "Data berhasil ditambahkan!\n";
}



// buat ediet user/petugas

void adminEditUser(nodeDataUser* headUser) {
    if (!headUser) {
        cout << "Data kosong!\n";
        return;
    }

    string username;
    cout << "Masukkan username yang ingin diedit: ";
    cin >> username;

    nodeDataUser* p = findUser(headUser, username);

    if (!p) {
        cout << "User tidak ditemukan!\n";
        return;
    }

    cout << "Nama Baru : "; cin >> p->data.nama;
    cout << "Alamat Baru : "; cin >> p->data.alamat;
    cout << "No Telp Baru : "; cin >> p->data.no_telp;
    cout << "Role Baru : "; cin >> p->data.role;

    cout << "Data berhasil diperbarui!\n";
}



// buat hapus user/petugas

void adminHapusUser(nodeDataUser*& headUser) {
    if (!headUser) {
        cout << "Data kosong!\n";
        return;
    }

    string username;
    cout << "Masukkan username yang ingin dihapus: ";
    cin >> username;

    nodeDataUser* p = findUser(headUser, username);

    if (!p) {
        cout << "User tidak ditemukan!\n";
        return;
    }

    if (p == headUser) {
        headUser = p->next;
        if (headUser) headUser->prev = nullptr;
    } else {
        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
    }

    delete p;
    cout << "User berhasil dihapus!\n";
}
