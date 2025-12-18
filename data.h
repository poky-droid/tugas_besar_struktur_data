#ifndef DATA_H
#define DATA_H

#include <string>
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
// FITUR PETUGAS - TRANSAKSI
// ================================

struct Transaksi {
    string idTransaksi;
    string namaNasabah;
    string jenisSampah;
    float berat;
    int totalHarga;
};

// =======================
// CHILD (Transaksi)
// =======================
struct NodeTransaksi {
    Transaksi data;
    NodeTransaksi* next;
};


extern NodeTransaksi* headTransaksi;

void laporanTransaksi();
void tambahTransaksi();
void lihatTransaksi();

// Pengelolaan Sampah 

typedef struct Sampah {
    string jenisSampah;
    float berat;        // kilogram
    float hargaPerKg; // harga per kilogram  
    string kategori; 
} Sampah;

typedef struct queueNode {
    Sampah data;
    queueNode* next;
} queueNode;

typedef struct titikpengumpulan {
    string RW;
    string alamat;
    titikpengumpulan* next;
} titikpengumpulan;


// ================================
// FITUR PETUGAS - SAMPAH
// ================================

// =======================
// PARENT (Sampah)
// =======================
struct NodeSampah {
    Sampah data;
    NodeSampah* next;
    NodeTransaksi* firstChild;
};

extern NodeSampah* headSampah;


void kelolaSampah();
void tambahSampah();
void lihatSampah();
void editSampah();
void hapusSampah();


// Pointer queue (global) 
extern queueNode* depan;   // front
extern queueNode* belakang; // rear


// pointer head (global or passed)
extern titikpengumpulan* headRW;


// Prototipe fungsi queue
queueNode* createSampah(Sampah S);
void enqueueSampah(Sampah S);
string dequeueSampah();
void tampilQueueSampah();
bool isEmpty();
Sampah inputSampah();
void tambahRW();
void tampilRW();
void hapusRW(string rw);
void editRW(string rw);
float getHargaPerKgJenis(string kategori, string jenis);


#endif