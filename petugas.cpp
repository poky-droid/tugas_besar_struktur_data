#include <iostream>
#include "data.h"
using namespace std;


// ================================
// CREATE NODE
// ================================
NodeSampah* createNodeSampah(Sampah S) {
    NodeSampah* n = new NodeSampah;
    n->data = S;
    n->next = nullptr;
    n->firstChild = nullptr;
    return n;
}

// ================================
// KELOLA SAMPAH
// ================================
void kelolaSampah() {
    int pilih;
    do {
        cout << "\n==== KELOLA SAMPAH ====\n";
        cout << "1. Tambah Sampah\n";
        cout << "2. Lihat Sampah\n";
        cout << "3. Edit Sampah\n";
        cout << "4. Hapus Sampah\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahSampah(); break;
            case 2: lihatSampah(); break;
            case 3: editSampah(); break;
            case 4: hapusSampah(); break;
        }
    } while (pilih != 5);
}

// ================================
// TAMBAH SAMPAH
// ================================
void tambahSampah() {
    Sampah S = inputSampah();
    NodeSampah* baru = createNodeSampah(S);

    if (!headSampah)
        headSampah = baru;
    else {
        NodeSampah* temp = headSampah;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "Sampah berhasil ditambahkan!\n";
}

// ================================
// LIHAT SAMPAH
// ================================
void lihatSampah() {
    if (!headSampah) {
        cout << "Data kosong\n";
        return;
    }

    NodeSampah* temp = headSampah;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << temp->data.jenisSampah
             << " | " << temp->data.kategori
             << " | " << temp->data.berat << " kg"
             << " | Rp" << temp->data.hargaPerKg << endl;
        temp = temp->next;
    }
}

// ================================
// EDIT & HAPUS SAMPAH
// ================================
void editSampah() {
    lihatSampah();
    int idx;
    cout << "Pilih nomor: ";
    cin >> idx;

    NodeSampah* temp = headSampah;
    for (int i = 1; temp && i < idx; i++) temp = temp->next;

    if (!temp) {
        cout << "Tidak valid\n";
        return;
    }

    temp->data = inputSampah();
    cout << "Data diperbarui\n";
}

void hapusSampah() {
    lihatSampah();
    int idx;
    cout << "Pilih nomor: ";
    cin >> idx;

    if (idx == 1) {
        NodeSampah* del = headSampah;
        headSampah = headSampah->next;
        delete del;
        return;
    }

    NodeSampah* prev = headSampah;
    for (int i = 1; prev->next && i < idx - 1; i++)
        prev = prev->next;

    if (!prev->next) return;

    NodeSampah* del = prev->next;
    prev->next = del->next;
    delete del;
}



void tambahTransaksi() {
    if (!headSampah) {
        cout << "Belum ada sampah\n";
        return;
    }

    lihatSampah();
    int idx;
    cout << "Pilih sampah: ";
    cin >> idx;

    NodeSampah* parent = headSampah;
    for (int i = 1; parent && i < idx; i++)
        parent = parent->next;

    if (!parent) {
        cout << "Sampah tidak ditemukan\n";
        return;
    }

    Transaksi T;
    cout << "ID Transaksi: ";
    cin >> T.idTransaksi;
    cin.ignore();
    cout << "Nama Nasabah: ";
    getline(cin, T.namaNasabah);

    T.jenisSampah = parent->data.jenisSampah;
    T.berat = parent->data.berat;
    T.totalHarga = parent->data.berat * parent->data.hargaPerKg;

    NodeTransaksi* n = new NodeTransaksi;
    n->data = T;
    n->next = nullptr;

    // ===============================
    // SIMPAN KE CHILD (RELASI)
    // ===============================
    if (!parent->firstChild)
        parent->firstChild = n;
    else {
        NodeTransaksi* t = parent->firstChild;
        while (t->next) t = t->next;
        t->next = n;
    }

    // ===============================
    // SIMPAN KE LIST GLOBAL (FIX)
    // ===============================
    if (!headTransaksi)
        headTransaksi = n;
    else {
        NodeTransaksi* temp = headTransaksi;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    cout << "Transaksi berhasil ditambahkan\n";
}

void lihatTransaksi() {
    if (!headTransaksi) {
        cout << "Belum ada transaksi\n";
        return;
    }

    cout << "\n==== DAFTAR TRANSAKSI ====\n";
    NodeTransaksi* t = headTransaksi;

    while (t) {
        cout << "ID        : " << t->data.idTransaksi << endl;
        cout << "Nasabah   : " << t->data.namaNasabah << endl;
        cout << "Sampah    : " << t->data.jenisSampah << endl;
        cout << "Total Rp  : " << t->data.totalHarga << endl;
        cout << "--------------------------\n";
        t = t->next;
    }
}

