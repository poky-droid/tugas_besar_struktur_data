#include "data.h"
#include <iostream>
using namespace std;
int menuLogin(){
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
        login();
        break;
    case 2:
        registerUser();
        break;
    
    default:
        break;
    }
}

void menuDasboard(){
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

void login(){
    DataUser d;
    cout << "==========================" << endl;
    cout << "        LOGIN            " << endl;
    cout << "==========================" << endl;
    cout << "Masukkan username: ";
    string username;
    cin >> username;
    cout << "Masukkan password: ";
    string password;
    cin >> password;
    cout << "==========================" << endl;
    if (username == d.username && password == d.password){
        if (d.role == "admin"){
            menuAdmin();
        } 
        else if (d.role == "petugas") {
            menuPetugas();
        } 
        else if (d.role == "user") {
            // Panggil menu user
        }
    } else {
        cout << "Login gagal. Username atau password salah." << endl;
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
    login();
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
    cout << "==========================" << endl;
    cout << "      MENU PETUGAS       " << endl;
    cout << "==========================" << endl;
    cout << "1. Kelola Sampah " << endl;
    cout << "2. Laporan Transaksi " << endl;
    cout << "3. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;



}

void menuUser(){
    cout << "==========================" << endl;
    cout << "       MENU USER         " << endl;
    cout << "==========================" << endl;
    cout << "1. Setor Sampah " << endl;
    cout << "2. Lihat Saldo " << endl;
    cout << "3. Keluar " << endl;
    cout << "==========================" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan; 
}




