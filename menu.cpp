#include "data.h"
#include <iostream>
using namespace std;

// ...existing code...

void menuUser() {
    do {
        cout << "==========================" << endl;
    cout << "       MENU USER         " << endl;
    cout << "==========================" << endl;
    cout << "1. Setor Sampah " << endl;
    cout << "2. Lihat Saldo " << endl;
    cout << "3. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            cout << "Fitur setor sampah belum tersedia." << endl;
            break;
        case 2:
            cout << "Fitur lihat saldo belum tersedia." << endl;
            break;
        case 3:
            cout << "Keluar dari menu user." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
    } // close switch

    } while (pilihan != 3);
    
}







int MenuUtama(){
    do {
        cout << "==========================" << endl;
        cout << "      MENU UTAMA         " << endl;
        cout << "==========================" << endl;
        cout << "1. Login " << endl;
        cout << "2. Register " << endl;
        cout << "3. Keluar " << endl;
        cout << "==========================" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                login(headUser);
                break;
            case 2:
                registerUser();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem!" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 3);
    return 0;
}


int menuLogin(){
    do{
         cout << "==========================" << endl;
    cout << "      MENU LOGIN         " << endl;
    cout << "==========================" << endl;
    cout << "1. Login " << endl;
    cout << "2. register " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    switch (pilihan)
    {
    case 1:
       login(headUser);
        break;
    case 2:
        registerUser();
        break;
    
    default:
        break;
    }
    }while (pilihan !=3);
    return 0;
 }
   


void menuDasboard(){
    void dashboard(nodeDataUser* headUser, queueNode* headSampah);
    cout << "==========================" << endl;
    cout << "     MENU DASHBOARD      " << endl;
    cout << "==========================" << endl;
    cout << "1. list pengguna " << endl;
    cout << "2. total transaksi " << endl;
    cout << "3. menagemet sampah  " << endl;
    cout << "4. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
}

void menuPengguna(){
    cout << "==========================" << endl;
    cout << "      MENU PENGGUNA      " << endl;
    cout << "==========================" << endl;
    cout << "1. user " << endl;
    cout << "2. petugas" << endl;
    cout << "4. kembali " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
}
void menuManagemetSampah(){
    cout << "==========================" << endl;
    cout << "   MENU MANAGEMET SAMPAH " << endl;
    cout << "==========================" << endl;
    cout << "1. daftar ketegori " << endl;
    cout << "2. management titik pengumpulan " << endl;
    cout << "3. harga sampah " << endl;
    cout << "4. aturan pemilahan" << endl;
    cout << "5. kembali " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

}

nodeDataUser* findUser(nodeDataUser* head, string username) {
    nodeDataUser* current = head;
    while (current != NULL) {
        if (current->data.username == username) {
            return current; // ketemu
        }
        current = current->next;
    }
    return NULL; // tidak ditemukan
}

void login(nodeDataUser* head) {
    cout << "==========================" << endl;
    cout << "          LOGIN           " << endl;
    cout << "==========================" << endl;

    string username, password;

    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    cout << "==========================" << endl;

    // cari user di linked list
    nodeDataUser* userNode = findUser(head, username);

    if (userNode == NULL) {
        cout << "Login gagal: Username tidak ditemukan." << endl;
        return;
    }

    if (password != userNode->data.password) {
        cout << "Login gagal: Password salah." << endl;
        return;
    }

    // Jika lolos username & password
    cout << "Login berhasil! Selamat datang, " << userNode->data.nama << endl;

    // Cek role
    if (userNode->data.role == "admin") {
        menuAdmin();
    } 
    else if (userNode->data.role == "petugas") {
        menuPetugas();
    } 
    else if (userNode->data.role == "user") {
        menuUser();
    } 
    else {
        cout << "Role tidak dikenal." << endl;
    }
}



string registerUser(){
    DataUser d;
    cout << "==========================" << endl;
    cout << "       REGISTER          " << endl;
    cout << "==========================" << endl;
    cout << "Masukkan nama: ";
    cin >> d.nama;
    cout << "Masukkan alamat: ";
    cin >> d.alamat;
    cout << "Masukkan no_telp: ";
    cin >> d.no_telp;
    cout << "Masukkan username: ";
    cin >> d.username;
    cout << "Masukkan password: ";
    cin >> d.password;
    d.role = "user"; // default role user
    cout << "==========================" << endl;

    // Simpan ke linked list
    nodeDataUser* newNode = createNode();
    newNode->data = d;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (headUser == nullptr) {
        headUser = newNode;
    } else {
        nodeDataUser* temp = headUser;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Registrasi berhasil. Silakan login." << endl;
    return "Registrasi berhasil. Silakan login.";

}



void menuAdmin(){
    cout << "==========================" << endl;
    cout << "       MENU ADMIN        " << endl;
    cout << "==========================" << endl;
    cout << "1. Kelola Pengguna " << endl;
    cout << "2. Kelola Sampah " << endl;
    cout << "3. Laporan Transaksi " << endl;
    cout << "4. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            menuPengguna();
            break;
        case 2:
            menuManagemetSampah();
            break;
        case 3:
             menuDasboard();
            break;
        case 4:
            cout << "Keluar dari menu admin." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
    }
}

void menuPetugas(){
    int pilihan;
    do {
    cout << "==========================" << endl;
    cout << "      MENU PETUGAS       " << endl;
    cout << "==========================" << endl;
    cout << "1. Kelola Sampah " << endl;
    cout << "2. Laporan Transaksi " << endl;
    cout << "3. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kelolaSampah();
            break;
        case 2:
            laporanTransaksi();
            break;
        case 3:
            cout << "Keluar dari menu petugas." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
     } while (pilihan != 3);
}

// ================================
// TRANSAKSI (CHILD)
// ================================
void laporanTransaksi() {
    int pilih;
    do {
        cout << "\n==== LAPORAN TRANSAKSI ====\n";
        cout << "1. Lihat Transaksi\n";
        cout << "2. Tambah Transaksi\n";
        cout << "3. Kembali\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                lihatTransaksi();
                break;
            case 2:
                tambahTransaksi();
                break;
            case 3:
                cout << "Kembali ke menu petugas...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 3);
}

