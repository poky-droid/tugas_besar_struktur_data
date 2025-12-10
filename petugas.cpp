#include <iostream>
#include "data.h"
#include "pengelolaan_sampah.h"
using namespace std;

// ===============================
// Definisi variabel global
// ===============================
int jumlahSampah = 0;
Sampah dataSampah[20];

int jumlahTransaksi = 0;
Transaksi dataTransaksi[50];


// =======================================================
//                      KELOLA SAMPAH
// =======================================================
void kelolaSampah() {
    int pilih;

    do {
        cout << "\n======== KELOLA SAMPAH ========\n";
        cout << "1. Tambah Sampah\n";
        cout << "2. Lihat Data Sampah\n";
        cout << "3. Edit Data Sampah\n";
        cout << "4. Hapus Data Sampah\n";
        cout << "5. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tambahSampah(); break;
            case 2: lihatSampah(); break;
            case 3: editSampah(); break;
            case 4: hapusSampah(); break;
            case 5: break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
}


// =======================================================
//                 TAMBAH SAMPAH (PAKAI inputSampah())
// =======================================================
void tambahSampah() {
    if (jumlahSampah >= 20) {
        cout << "Data sampah penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH DATA SAMPAH ===\n";
    
    // pakai inputSampah dari pengelolaan_sampah.cpp
    Sampah S = inputSampah();

    dataSampah[jumlahSampah] = S;
    jumlahSampah++;

    cout << "Data sampah berhasil ditambahkan!\n";
}


// =======================================================
//                    LIHAT SAMPAH
// =======================================================
void lihatSampah() {
    cout << "\n=== DAFTAR SAMPAH ===\n";

    if (jumlahSampah == 0) {
        cout << "Belum ada data sampah.\n";
        return;
    }

    for (int i = 0; i < jumlahSampah; i++) {
        cout << i+1 << ". Kategori: " << dataSampah[i].kategori << endl;
        cout << "   Jenis   : " << dataSampah[i].jenisSampah << endl;
        cout << "   Berat   : " << dataSampah[i].berat << " kg\n";
        cout << "   Harga/Kg: Rp " << dataSampah[i].hargaPerKg << "\n";
    }
}


// =======================================================
//                    EDIT SAMPAH
// =======================================================
void editSampah() {
    lihatSampah();

    if (jumlahSampah == 0)
        return;

    int index;
    cout << "\nMasukkan nomor data yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > jumlahSampah) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    cout << "\n=== EDIT DATA SAMPAH ===\n";

    // cukup panggil inputSampah (tidak bikin ulang)
    dataSampah[index - 1] = inputSampah();

    cout << "Data berhasil diperbarui!\n";
}


// =======================================================
//                    HAPUS SAMPAH
// =======================================================
void hapusSampah() {
    lihatSampah();

    if (jumlahSampah == 0)
        return;

    int index;
    cout << "\nMasukkan nomor data yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > jumlahSampah) {
        cout << "Nomor tidak valid!\n";
        return;
    }

    for (int i = index - 1; i < jumlahSampah - 1; i++) {
        dataSampah[i] = dataSampah[i + 1];
    }

    jumlahSampah--;
    cout << "Data sampah berhasil dihapus!\n";
}


// =======================================================
//                    TAMBAH TRANSAKSI
// =======================================================
void tambahTransaksi() {
    if (jumlahTransaksi >= 50) {
        cout << "Data transaksi penuh!\n";
        return;
    }

    cout << "\n=== TAMBAH TRANSAKSI ===\n";
    Transaksi T;

    cout << "ID Transaksi: ";
    cin >> T.idTransaksi;

    cout << "Nama Nasabah: ";
    cin.ignore();
    getline(cin, T.namaNasabah);

    // panggil inputSampah
    Sampah S = inputSampah();

    T.jenisSampah = S.jenisSampah;
    T.berat = S.berat;
    T.totalHarga = S.hargaPerKg * S.berat;

    dataTransaksi[jumlahTransaksi] = T;
    jumlahTransaksi++;

    cout << "Transaksi berhasil ditambahkan!\n";
}


// =======================================================
//                    LIHAT TRANSAKSI
// =======================================================
void lihatTransaksi() {
    cout << "\n=== DAFTAR TRANSAKSI ===\n";

    if (jumlahTransaksi == 0) {
        cout << "Belum ada transaksi.\n";
        return;
    }

    for (int i = 0; i < jumlahTransaksi; i++) {
        cout << i+1 << ". ID     : " << dataTransaksi[i].idTransaksi << endl;
        cout << "   Nama   : " << dataTransaksi[i].namaNasabah << endl;
        cout << "   Jenis  : " << dataTransaksi[i].jenisSampah << endl;
        cout << "   Berat  : " << dataTransaksi[i].berat << " kg\n";
        cout << "   Total  : Rp " << dataTransaksi[i].totalHarga << "\n";
    }
}
