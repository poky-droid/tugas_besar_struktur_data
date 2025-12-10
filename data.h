#ifndef DATA_H
#define DATA_H

#include <string>
#include "pengelolaan_sampah.h"
using namespace std;

// ================================
// VARIABEL GLOBAL
// ================================
extern int pilihan;

// user linked list
struct DataUser {
    string username;
    string password;
    string nama;
    string alamat;
    string no_telp;
    string role;
};

struct nodeDataUser {
    DataUser data;
    nodeDataUser* next;
    nodeDataUser* prev;
};

extern nodeDataUser* headUser;


// ================================
// DEKLARASI FUNGSI USER / LOGIN
// ================================
void login(nodeDataUser* head);
string registerUser();
nodeDataUser* createNode();
nodeDataUser* findUser(nodeDataUser* head, string username);

void printUser(DataUser D);
DataUser inputUser(DataUser in);
nodeDataUser* editData(nodeDataUser* head);
nodeDataUser* deleteUser(nodeDataUser* head);


// ================================
// MENU
// ================================
int MenuUtama();
void menuAdmin();
void menuPetugas();
void menuUser();
void menuDasboard();
void menuManagemetSampah();
void menuPengguna();


// ================================
// FITUR PETUGAS - SAMPAH
// ================================
extern int jumlahSampah;
extern Sampah dataSampah[20];

void kelolaSampah();
void tambahSampah();
void lihatSampah();
void editSampah();
void hapusSampah();


// ================================
// FITUR PETUGAS - TRANSAKSI
// ================================

struct Transaksi {
    string idTransaksi;
    string namaNasabah;
    string jenisSampah;
    float berat;
    int totalHarga;
};

extern int jumlahTransaksi;
extern Transaksi dataTransaksi[50];

void laporanTransaksi();
void tambahTransaksi();
void lihatTransaksi();

#endif
